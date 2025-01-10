#ifndef PENGUIN_WINDOW_HPP
#define PENGUIN_WINDOW_HPP

#include <memory>
#include <SDL3/SDL_video.h>
#include <string>
#include "exception.hpp"
#include "vector2.hpp"

namespace Penguin2D {
	
	class PenguinWindow {
	public:
		PenguinWindow(const std::string& p_title_name, Vector2<int> size, SDL_WindowFlags p_flags = 0);
		explicit PenguinWindow(Vector2<int> size, SDL_WindowFlags p_flags = 0);

		SDL_Window* get_window();
		void set_title(std::string& title);
		// void set_icon(); -> implement once PenguinSurface / PenguinTexture is supported
		void set_max_size(Vector2<int> max_size);
		void set_min_size(Vector2<int> min_size);
		void resize(Vector2<int> new_size);

	private:
		std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
	};

}

#endif