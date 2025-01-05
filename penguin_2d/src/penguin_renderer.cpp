#include "penguin_renderer.hpp"
#include <iostream>

#include <stdexcept>

using namespace Penguin2D;
using namespace Penguin2D::Colours;

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

void PenguinRenderer::draw_rect(Rect2<float> rect, Colour outline, Colour fill) {
	// Draw the fill
	if (fill.alpha) {
		set_colour(fill);
		auto sdl_rect = (SDL_FRect)rect;
		Exception::throw_if(
			!SDL_RenderFillRect(renderer.get(), &sdl_rect),
			"Failed to set draw a rect to the renderer.",
			RENDERER_ERROR
		);
	}
	
	// Draw the outline
	if (outline.alpha) {
		set_colour(outline);
		auto sdl_rect = (SDL_FRect)rect;
		Exception::throw_if(
			!SDL_RenderRect(renderer.get(), &sdl_rect),
			"Failed to set draw the rect to the renderer.",
			RENDERER_ERROR
		);
	}

}

void PenguinRenderer::reset_colour() {
	set_colour(Colours::BLACK); 
}

SDL_Renderer* PenguinRenderer::get_renderer() {
	return renderer.get();
}