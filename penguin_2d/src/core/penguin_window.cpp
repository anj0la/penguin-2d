/// File name: penguin_window.cpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinWindow initializes a window to be displayed onto the screen.
/// 
/// This class creates a window with the specified name, size and flags. It also has functions to set the maximum and minimum size of the window, as well as setting the
/// title and resizing the window.
/// 

#include "penguin_window.hpp"

using namespace Penguin2D;

/// <summary>
/// Creates a window with the specified name, size and flags.
/// </summary>
/// <param name="p_title_name">- the name of the window. Displayed on the top left corner of the window.</param>
/// <param name="size">- the size of the window.</param>
/// <param name="p_flags">- the flags associated with the window (e.g., RESIZABLE).</param>
PenguinWindow::PenguinWindow(const std::string & title, Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow(title.c_str(), size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

PenguinWindow::PenguinWindow(Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow("", size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

/// <summary>
/// Returns the underlying SDL window that makes up the PenguinWindow.
/// </summary>
/// <returns>SDL_Window* - pointer to the underlying SDL_Window.</returns>
SDL_Window* PenguinWindow::get_window() {

	// Throw error if the window has not been initialized.
	Exception::throw_if(!window, "The window is not initalized.", WINDOW_ERROR);

	return window.get();
}

/// <summary>
/// Sets the title of the window to the specified parameter.
/// </summary>
/// <param name="title"> - the title of the window.</param>
void PenguinWindow::set_title(std::string& title) {

	Exception::throw_if(
		!SDL_SetWindowTitle(window.get(), title.c_str()),
		"There was an error setting the window title.",
		WINDOW_ERROR
	);
}

/// <summary>
/// Sets the maximum size of the window. The window will not be able to exceed the set size.
/// </summary>
/// <param name="max_size"> - the maximum size of the window.</param>
void PenguinWindow::set_max_size(Vector2<int> max_size) {

	Exception::throw_if(
		!SDL_SetWindowMaximumSize(window.get(), max_size.x, max_size.y),
		"There was an error setting the window's maximum size",
		WINDOW_ERROR
	);
}

/// <summary>
/// Sets the minimum size of the window. The window will not shrink beyond the set size.
/// </summary>
/// <param name="min_size"> - the minimum size of the window.</param>
void PenguinWindow::set_min_size(Vector2<int> min_size) {

	Exception::throw_if(
		!SDL_SetWindowMinimumSize(window.get(), min_size.x, min_size.y),
		"There was an error setting the window's minimum size",
		WINDOW_ERROR
	);
}

/// <summary>
/// Resizes the window to the specified size.
/// </summary>
/// <param name="new_size"> - the new size of the window.</param>
void PenguinWindow::resize(Vector2<int> new_size) {
	Exception::throw_if(
		!SDL_SetWindowSize(window.get(), new_size.x, new_size.y),
		"There was an error setting the window's new size",
		WINDOW_ERROR
	);
}