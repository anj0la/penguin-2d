#ifndef PENGUIN_RENDERER_HPP
#define PENGUIN_RENDERER_HPP

#include <SDL3/SDL_render.h>
#include <memory>
#include <string>
#include "exception.hpp"

#include "penguin_window.hpp"
#include "colour.hpp"
#include "rect2.hpp"

namespace Penguin2D {

	class PenguinRenderer {
	public:
		explicit PenguinRenderer(PenguinWindow& p_window, const std::string& p_name = "");
		
		void clear();
		void draw_line(Vector2<> vect_a, Vector2<> vect_b, Colour colour = Colours::WHITE);
		void draw_pixel(Vector2<> vect, Colour colour = Colours::WHITE);
		void draw_rect(Rect2<float> rect, Colour outline = Colours::WHITE, Colour fill = Colours::TRANSPARENT);
		void present();
		void set_colour(Colour colour);
		void reset_colour();
		SDL_Renderer* get_renderer();

	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
	};
}

#endif // PENGUIN_RENDERER_HPP