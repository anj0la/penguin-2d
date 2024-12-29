#ifndef PENGUIN_WINDOW_HPP
#define PENGUIN_WINDOW_HPP

#include <memory>
#include <SDL3/SDL_video.h>
#include <string>
#include "exception.hpp"
#include "vector2.hpp"

namespace Penguin2D {
	
	class PenguinWindow {
	private:
		std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
	public:
		PenguinWindow(const std::string & p_title_name, Vector2<int> size, SDL_WindowFlags p_flags);
		SDL_Window* get_window();
	};

}

#endif