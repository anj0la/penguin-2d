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
		PenguinRenderer(PenguinWindow& p_window, std::string p_name);
		void clear();
		void draw_rect(Rect2<float> rect, Colour outline, Colour fill);
		void present();
		void set_colour(Colour colour);
		void reset_colour();

	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
	};
}

#endif // PENGUIN_RENDERER_HPP