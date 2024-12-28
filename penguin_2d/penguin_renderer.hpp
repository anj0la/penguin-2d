#ifndef PENGUIN_RENDERER_HPP
#define PENGUIN_RENDERER_HPP

#include <SDL3/SDL_render.h>
#include <memory>
#include <string>
#include <stdexcept>

#include "penguin_window.hpp"
#include "colour.hpp"

namespace Penguin2D {

	class PenguinRenderer {
	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
	public:
		PenguinRenderer(PenguinWindow& p_window, std::string p_name);
		void clear();
		void draw_rect();
		void set_colour(Colour colour);
	};
}

#endif // PENGUIN_RENDERER_HPP