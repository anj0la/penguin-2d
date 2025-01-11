#include "penguin_renderer.hpp"
#include <iostream>

#include <stdexcept>

using namespace Penguin2D;

PenguinRenderer::PenguinRenderer(PenguinWindow& p_window, const std::string& p_name) 
: renderer(SDL_CreateRenderer(
	p_window.get_window(), 
	p_name.empty() ? NULL : p_name.c_str()), // If empty, allow SDL to handle getting the driver.
	&SDL_DestroyRenderer) {

	// Throws an exception if the renderer was not intialized
	Exception::throw_if(!renderer, "The renderer was not initialized.", RENDERER_ERROR);
}

void PenguinRenderer::clear() {
	reset_colour();
	Exception::throw_if(
		!SDL_RenderClear(renderer.get()),
		"Failed to set clear renderer from window.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::present() {
	Exception::throw_if(
		!SDL_RenderPresent(renderer.get()),
		"Failed to set present renderer to window.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::set_colour(Colour colour) {
	Exception::throw_if(
		!SDL_SetRenderDrawColor(renderer.get(), colour.red, colour.green, colour.blue, colour.alpha),
		"Failed to set renderer draw color.",
		RENDERER_ERROR
	);
}
void PenguinRenderer::draw_line(Vector2<> vect_a, Vector2<> vect_b, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderLine(renderer.get(), vect_a.x, vect_a.y, vect_b.x, vect_b.y),
		"Failed to draw a line to the renderer",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_pixel(Vector2<> vect, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderPoint(renderer.get(), vect.x, vect.y),
		"Failed to draw a line to the renderer",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_rect(Rect2<float> rect, Colour outline) {
	set_colour(outline);
	auto sdl_rect = (SDL_FRect)rect;
	Exception::throw_if(
		!SDL_RenderRect(renderer.get(), &sdl_rect),
		"Failed to draw the rect to the renderer.",
		RENDERER_ERROR
	);

}

void PenguinRenderer::draw_filled_rect(Rect2<float> rect, Colour fill) {
	set_colour(fill);
	auto sdl_rect = (SDL_FRect)rect;
	Exception::throw_if(
		!SDL_RenderFillRect(renderer.get(), &sdl_rect),
		"Failed to draw the filled rect to the renderer.",
		RENDERER_ERROR
	);
}


void PenguinRenderer::draw_circle(Vector2<float> center, int radius, int border, Colour outline) {
	// The vector will contain the SDL_FPoints needed to render the circle onto the screen.
	std::vector<SDL_FPoint> points;

	// Initialize outer and inner variables that will create the circle with the border size. 
	int outer = radius;
	int inner = radius - border;

	// Handle edge case where border is too large.
	if (inner < 0) inner = 0;

	// Initialize variables needed for the modified midpoint algorithm.
	int x_outer = outer;
	int x_inner = inner;
	int y = 0;
	int err_outer = 1 - x_outer;
	int err_inner = 1 - x_inner;

	while (x_outer >= y) {
		x_line(center.x + x_inner, center.x + x_outer, center.y + y, points);
		y_line(center.x + y, center.y + x_inner, center.y + x_outer, points);
		x_line(center.x - x_outer, center.x - x_inner, center.y + y, points);
		y_line(center.x - y, center.y + x_inner, center.y + x_outer, points);
		x_line(center.x - x_outer, center.x - x_inner, center.y - y, points);
		y_line(center.x - y, center.y - x_outer, center.y - x_inner, points);
		x_line(center.x + x_inner, center.x + x_outer, center.y - y, points);
		y_line(center.x + y, center.y - x_outer, center.y - x_inner, points);

		y++;

		// Update outer circle error.
		if (err_outer < 0) {
			err_outer += 2 * y + 1;
		}
		else {
			x_outer--;
			err_outer += 2 * (y - x_outer + 1);
		}

		// Update inner circle error.
		if (y > inner) {
			x_inner = y;
		}
		else {
			if (err_inner < 0) {
				err_inner += 2 * y + 1;
			}
			else {
				x_inner--;
				err_inner += 2 * (y - x_inner + 1);
			}
		}
	}

	// Draw the circle.
	set_colour(outline);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a circle to the renderer.",
		RENDERER_ERROR
		);
}

void PenguinRenderer::draw_filled_circle(Vector2<float> center, int radius, Colour fill) {
	// Initialize variables needed for the midpoint algorithm.
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1); // (radius << 1 = diameter)

	while (x >= y) {
		draw_horizontal_line(center.x - x, center.x + x, center.y + y, fill); // Top span
		draw_horizontal_line(center.x - x, center.x + x, center.y - y, fill); // Bottom span

		// Left and right spans
		draw_horizontal_line(center.x - y, center.x + y, center.y + x, fill); // Right span
		draw_horizontal_line(center.x - y, center.x + y, center.y - x, fill); // Left span

		if (err <= 0) {
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0) {
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
	
}

void PenguinRenderer::reset_colour() {
	set_colour(Colours::BLACK); 
}

SDL_Renderer* PenguinRenderer::get_renderer() {
	return renderer.get();
}


void PenguinRenderer::x_line(int x1, int x2, int y, std::vector<SDL_FPoint>& points) {
	while (x1 <= x2) points.push_back({ (float)x1++, (float)y });
}

void PenguinRenderer::y_line(int x, int y1, int y2, std::vector<SDL_FPoint>& points) {
	while (y1 <= y2) points.push_back({ (float)x, (float)y1++ });
}

void PenguinRenderer::draw_horizontal_line(float x1, float x2, float y, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderLine(renderer.get(), x1, y, x2, y),
		"Failed to render a line to the screen",
		RENDERER_ERROR
	);
}