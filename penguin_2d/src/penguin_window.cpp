#include "penguin_window.hpp"

#include <iostream>

using namespace Penguin2D;

PenguinWindow::PenguinWindow(const std::string &p_title_name, Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow(p_title_name.c_str(), size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

PenguinWindow::PenguinWindow(Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow("", size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}


SDL_Window* PenguinWindow::get_window() {

	// Throw error if the window has not been initialized.
	Exception::throw_if(!window, "The window is not initalized.", WINDOW_ERROR);

	return window.get();
}

void PenguinWindow::set_title(std::string& title) {

	Exception::throw_if(
		!SDL_SetWindowTitle(window.get(), title.c_str()),
		"There was an error setting the window title.",
		WINDOW_ERROR
	);
}

void PenguinWindow::set_max_size(Vector2<int> max_size) {

	Exception::throw_if(
		!SDL_SetWindowMaximumSize(window.get(), max_size.x, max_size.y),
		"There was an error setting the window's maximum size",
		WINDOW_ERROR
	);
}

void PenguinWindow::set_min_size(Vector2<int> min_size) {

	Exception::throw_if(
		!SDL_SetWindowMinimumSize(window.get(), min_size.x, min_size.y),
		"There was an error setting the window's minimum size",
		WINDOW_ERROR
	);
}

void PenguinWindow::resize(Vector2<int> new_size) {
	Exception::throw_if(
		!SDL_SetWindowSize(window.get(), new_size.x, new_size.y),
		"There was an error setting the window's new size",
		WINDOW_ERROR
	);
}