#include "penguin_window.hpp"

#include <iostream>

using namespace Penguin2D;

// Change p_width and p_height to Vector2() object.
PenguinWindow::PenguinWindow(const std::string &p_title_name, Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow(p_title_name.c_str(), size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

SDL_Window* PenguinWindow::get_window() {

	// Throw error if the window has not been initialized.
	Exception::throw_if(!window, "The window is not initalized.", WINDOW_ERROR);

	return window.get();
}