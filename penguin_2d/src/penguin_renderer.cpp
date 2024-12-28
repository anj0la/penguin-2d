#include "penguin_renderer.hpp"
#include <iostream>

using namespace Penguin2D;
using namespace Penguin2D::Colours;

PenguinRenderer::PenguinRenderer(PenguinWindow& p_window, std::string p_name) 
: renderer(SDL_CreateRenderer(
	p_window.get_window(), 
	p_name.empty() ? NULL : p_name.c_str()), // If empty string, then allow SDL to handle getting the driver.
	&SDL_DestroyRenderer) {

	// Throw error if renderer was not set up.
	if (!renderer) {
		throw std::runtime_error(SDL_GetError());
	}
}

void PenguinRenderer::clear() {
	reset_colour();
	bool success = SDL_RenderClear(renderer.get());
	if (!success) {
		throw std::runtime_error(SDL_GetError());
	}
}

void PenguinRenderer::present() {
	bool success = SDL_RenderPresent(renderer.get());
	if (!success) {
		throw std::runtime_error(SDL_GetError());
	}
}

void PenguinRenderer::set_colour(Colour colour) {
	bool success = SDL_SetRenderDrawColor(renderer.get(), colour.red, colour.green, colour.blue, colour.alpha);
	if (!success) {
		throw std::runtime_error(SDL_GetError());
	}
}

// Set colour would handle rgb (and alpha) values for now.
// Colour a_colour = Colour(R, G, B, A) 
// You can add conversions later.
//void PenguinRenderer::set_colour(Color) {
//	bool success = SDL_SetRenderDrawColor()
//}

// Draw rect would take a Rect2 which consists of a Vector2 (x, y) which represents the position, and a Vector2(w, h) which represents the size.
// Internally, the Rect2 represents the SDL_FRect, where x -> position.x and y -> position.y, and w -> size.x and h -> size.y.

void PenguinRenderer::draw_rect(Rect2<float> rect, Colour outline, Colour fill) {

	// Draw the fill
	if (fill.alpha) {
		set_colour(fill);
		auto sdl_rect = (SDL_FRect)rect;
		// TODO: Create an exception class to reduce code.
		bool success = SDL_RenderFillRect(renderer.get(), &sdl_rect);
		if (!success) {
			throw std::runtime_error(SDL_GetError());
		}

	}
	
	// Draw the outline
	if (outline.alpha) {
		set_colour(outline);
		auto sdl_rect = (SDL_FRect)rect;
		// TODO: Create an exception class to reduce code.
		bool success = SDL_RenderRect(renderer.get(), &sdl_rect);
		if (!success) {
			throw std::runtime_error(SDL_GetError());
		}

	}

}


void PenguinRenderer::reset_colour() {
	set_colour(Colours::BLACK); 
}