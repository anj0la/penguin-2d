///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_window.cpp                                               ///
///                                                                             ///
/// This file implements the PenguinWindow class, which manages the creation	///
/// and handling of an SDL window, including initialization, manipulation,		///
/// and cleanup.																///	
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_window.hpp"

using namespace Penguin2D;

/// @brief Constructs a PenguinWindow with the specified title, size, and flags.
/// 
/// This constructor initializes a window with the given name, size, and window flags.
/// If the window cannot be created, an exception is thrown.
/// 
/// @param title: The name of the window, displayed in the top-left corner.
/// @param size: The size of the window.
/// @param flags: The flags associated with the window (e.g., RESIZABLE).
PenguinWindow::PenguinWindow(const std::string & title, Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow(title.c_str(), size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

/// @brief Constructs a PenguinWindow with the size, and flags, without a title.
/// 
/// This constructor initializes a window with the given size, and window flags.
/// If the window cannot be created, an exception is thrown.
/// 
/// @param title: The name of the window, displayed in the top-left corner.
/// @param size: The size of the window.
/// @param flags: The flags associated with the window (e.g., RESIZABLE).
PenguinWindow::PenguinWindow(Vector2<int> size, SDL_WindowFlags p_flags)
	: window(SDL_CreateWindow("", size.x, size.y, p_flags), &SDL_DestroyWindow) {

	Exception::throw_if(!window, "The window could not be initalized.", WINDOW_ERROR);
}

/// @brief Returns the underlying SDL window object.
/// 
/// This function returns the pointer to the SDL_Window associated with this PenguinWindow.
/// If the window has not been initialized, an exception is thrown.
/// 
/// @return SDL_Window*: The pointer to the underlying SDL_Window object.
SDL_Window* PenguinWindow::get_window() {

	// Throw error if the window has not been initialized.
	Exception::throw_if(!window, "The window is not initalized.", WINDOW_ERROR);

	return window.get();
}

/// @brief Sets the title of the window.
/// 
/// This function sets the title of the window to the specified string.
/// If there is an error while setting the title, an exception is thrown.
/// 
/// @param title: The title of the window to set.
void PenguinWindow::set_title(std::string& title) {

	Exception::throw_if(
		!SDL_SetWindowTitle(window.get(), title.c_str()),
		"There was an error setting the window title.",
		WINDOW_ERROR
	);
}

/// @brief Sets the maximum size of the window.
/// 
/// This function sets the maximum size that the window can be resized to. 
/// If there is an error, an exception is thrown.
/// 
/// @param max_size: The maximum size of the window.
void PenguinWindow::set_max_size(Vector2<int> max_size) {

	Exception::throw_if(
		!SDL_SetWindowMaximumSize(window.get(), max_size.x, max_size.y),
		"There was an error setting the window's maximum size",
		WINDOW_ERROR
	);
}

/// @brief Sets the minimum size of the window.
/// 
/// This function sets the minimum size that the window can be resized to. 
/// If there is an error, an exception is thrown.
/// 
/// @param min_size: The minimum size of the window.
void PenguinWindow::set_min_size(Vector2<int> min_size) {

	Exception::throw_if(
		!SDL_SetWindowMinimumSize(window.get(), min_size.x, min_size.y),
		"There was an error setting the window's minimum size",
		WINDOW_ERROR
	);
}

/// @brief Resizes the window to the specified size.
/// 
/// This function resizes the window to the provided size. 
/// If there is an error, an exception is thrown.
/// 
/// @param new_size: The new size of the window.
void PenguinWindow::resize(Vector2<int> new_size) {
	Exception::throw_if(
		!SDL_SetWindowSize(window.get(), new_size.x, new_size.y),
		"There was an error setting the window's new size",
		WINDOW_ERROR
	);
}