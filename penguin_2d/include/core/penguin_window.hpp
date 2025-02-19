///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_window.hpp                                               ///
///                                                                             ///
/// Defines the PenguinWindow class, which initializes and manages a window.    ///
///                                                                             ///
/// This class creates a window with the specified name, size, and flags. It    ///
/// provides functions for modifying window properties such as title, size,     ///
/// and constraints on maximum and minimum size.                                ///
///                                                                             ///
/// Currently, window flags are not supported in Penguin2D and require the use  ///
/// of SDL_WindowFlags. Future updates may introduce dedicated Penguin2D flags. ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_WINDOW_HPP
#define PENGUIN_WINDOW_HPP

// Penguin2D related include files
#include "exception.hpp"
#include "vector2.hpp"

// SDL related include files
#include <SDL_video.h>

// C++ library files
#include <memory>
#include <string>

namespace Penguin2D {
	
	/// @brief Manages the creation and properties of a window in the Penguin2D framework.
	///
	/// This class provides an interface for creating and managing
	/// an application window. It allows setting window properties such as 
	/// title, size, and constraints on maximum and minimum dimensions. 
	class PenguinWindow {
	public:
		/// @brief Constructs a PenguinWindow with the given title, size, and flags.
		/// @param title: The title of the window.
		/// @param size: The dimensions of the window.
		/// @param p_flags: The SDL window flags.
		PenguinWindow(const std::string& title, Vector2<int> size, SDL_WindowFlags p_flags = 0); // TODO: Update SDL_WindowFlags with relevant PenguinWindowFlags
		
		/// @brief Constructs a PenguinWindow with a given size and flags, without a title.
		/// @param size: The dimensions of the window.
		/// @param p_flags: The SDL window flags.
		explicit PenguinWindow(Vector2<int> size, SDL_WindowFlags p_flags = 0);

		/// @brief Retrieves the underlying SDL_Window pointer.
		/// @return A pointer to the SDL_Window instance.
		SDL_Window* get_window();

		/// @brief Sets the window title.
		/// @param title: The new title for the window.
		void set_title(std::string& title);

		/// @brief Sets the maximum allowed size of the window.
		/// @param max_size: The maximum dimensions of the window.
		void set_max_size(Vector2<int> max_size);

		/// @brief Sets the minimum allowed size of the window.
		/// @param min_size: The minimum dimensions of the window.
		void set_min_size(Vector2<int> min_size);

		/// @brief Resizes the window to the given dimensions.
		/// @param new_size: The new size of the window.
		void resize(Vector2<int> new_size);

	private:
		std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
	};

}

#endif