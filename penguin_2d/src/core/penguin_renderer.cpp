#include "penguin_renderer.hpp"

using namespace Penguin2D;

PenguinRenderer::PenguinRenderer(PenguinWindow& p_window, const std::string& p_name) 
: renderer(SDL_CreateRenderer(
	p_window.get_window(), 
	p_name.empty() ? NULL : p_name.c_str()), // If empty, allow SDL to handle getting the driver.
	&SDL_DestroyRenderer) {

	// Throw an exception if the renderer was not intialized.
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

void PenguinRenderer::draw_circle(Vector2<float> center, int radius, Colour outline) {
	// Initial points and decision variable.
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1); // (radius << 1 = diameter)

	// Vector for points to be rendered onto screen.
	std::vector<SDL_FPoint> points;

	// Fill all the 8 octances.
	while (x >= y) {
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x - x, center.y - y });
		points.push_back({ center.x + y, center.y + x });
		points.push_back({ center.x + y, center.y - x });
		points.push_back({ center.x - y, center.y + x });
		points.push_back({ center.x - y, center.y - x });

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

	// Draw the circle.
	set_colour(outline);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a circle to the renderer.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_filled_circle(Vector2<float> center, int radius, Colour fill) {
	// Initial points and decision variable.
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1); // (radius << 1 = diameter)

	while (x >= y) {
		draw_horizontal_line(center.x - x, center.x + x, center.y + y, fill); // Top span
		draw_horizontal_line(center.x - x, center.x + x, center.y - y, fill); // Bottom span

		// Left and right spans.
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

void PenguinRenderer::draw_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour outline) {
	// Squares of the radii for the ellipse.
	int rx2 = radius_x * radius_x;
	int ry2 = radius_y * radius_y;

	// Initial points and decision variable for region 1.
	int x = 0;
	int y = radius_y;
	int dx = 2 * ry2 * x;
	int dy = 2 * rx2 * y;
	int err = ry2 - (rx2 * radius_y) + (rx2 / 4);

	// Vector for points to be rendered onto the screen.
	std::vector<SDL_FPoint> points;

	// |slope| < 1 (region 1).
	while (dx < dy) {
		// Symmetrical points.
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y - y });

		if (err < 0) {
			x++;
			dx += 2 * ry2;
			err += dx + ry2;
		}
		else {
			x++;
			y--;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + ry2;
		}
	}

	err = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

	// |slope| >= 1 (region 2).
	while (y >= 0) {
		// Symmetrical points.
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y - y });

		if (err > 0) {
			y--;
			dy -= 2 * rx2;
			err += rx2 - dy;
		}
		else {
			y--;
			x++;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + rx2;
		}
	}

	// Draw the ellipse.
	set_colour(outline);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a circle to the renderer.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_filled_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour fill) {
	// Squares of the radii for the ellipse.
	int rx2 = radius_x * radius_x;
	int ry2 = radius_y * radius_y;

	// Initial points and decision variable for region 1.
	int x = 0;
	int y = radius_y;
	int dx = 2 * ry2 * x;
	int dy = 2 * rx2 * y;
	int err = ry2 - (rx2 * radius_y) + (rx2 / 4);

	// Vector for points to be rendered onto the screen.
	std::vector<SDL_FPoint> points;

	// |slope| < 1 (region 1).
	while (dx < dy) {
		// Fill horizontal lines for symmetrical points.
		for (int i = center.x - x; i <= center.x + x; i++) {
			points.push_back({ (float)i, center.y + y });
			points.push_back({ (float)i, center.y - y });
		}

		if (err < 0) {
			x++;
			dx += 2 * ry2;
			err += dx + ry2;
		}
		else {
			x++;
			y--;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + ry2;
		}
	}

	err = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

	// |slope| >= 1 (region 2).
	while (y >= 0) {
		// Fill horizontal lines for symmetrical points.
		for (int i = center.x - x; i <= center.x + x; i++) {
			points.push_back({ (float)i, center.y + y });
			points.push_back({ (float)i, center.y - y });
		}

		if (err > 0) {
			y--;
			dy -= 2 * rx2;
			err += rx2 - dy;
		}
		else {
			y--;
			x++;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + rx2;
		}
	}

	// Draw the filled ellipse.
	set_colour(fill);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a filled ellipse to the renderer.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_sprite(PenguinSprite sprite, Rect2<float>position) {
	auto sdl_position = (SDL_FRect)position;
	Exception::throw_if(
		!SDL_RenderTexture(renderer.get(), sprite.get_sprite_ptr(), NULL, &sdl_position),
		"Failed to render the sprite to the screen.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::draw_sprite_region(PenguinSprite sprite, Rect2<float> clip_region, Rect2<float>position) {
	auto sdl_clip_region = (SDL_FRect)clip_region;
	auto sdl_position = (SDL_FRect)position;
	Exception::throw_if(
		!SDL_RenderTexture(renderer.get(), sprite.get_sprite_ptr(), &sdl_clip_region, &sdl_position),
		"Failed to render the sprite region to the screen.",
		RENDERER_ERROR
	);
}

void PenguinRenderer::reset_colour() {
	set_colour(Colours::BLACK); 
}

SDL_Renderer* PenguinRenderer::get_renderer() {
	return renderer.get();
}

void PenguinRenderer::draw_horizontal_line(float x1, float x2, float y, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderLine(renderer.get(), x1, y, x2, y),
		"Failed to render a line to the screen.",
		RENDERER_ERROR
	);
}