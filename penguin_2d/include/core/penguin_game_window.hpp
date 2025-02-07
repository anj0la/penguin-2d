///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_game_window.hpp											///
///                                                                             ///
/// Defines the PenguinGameWindow class, which represents the main game window. ///
///                                                                             ///
/// This class is responsible for creating and managing the game window,        ///
/// initializing core systems such as rendering, event handling, and input.     ///
/// It provides functions to start and stop the game, handle events, and manage ///
/// the game loop.                                                              ///
///                                                                             ///
/// The PenguinGameWindow class serves as the central component for running a   ///
/// Penguin2D game, connecting to a PenguinGame instance and executing game     ///
/// logic within a structured loop.                                             ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_GAME_WINDOW_HPP
#define PENGUIN_GAME_WINDOW_HPP

// Penguin2D related include files
#include "penguin_window.hpp"
#include "penguin_renderer.hpp"
#include "penguin_text_renderer.hpp"
#include "penguin_input.hpp"
#include "penguin_event_handler.hpp"
#include "penguin_timer.hpp"
#include "penguin_game.hpp"
#include "vector2.hpp"
#include "rect2.hpp"
#include "colour.hpp"
#include "exception.hpp"

// SDL related include files
#include <SDL3/SDL.h>

// C++ library files
#include <memory>

namespace Penguin2D {

	/// @brief Manages the game window, rendering, input handling, events, and game loop.
	class PenguinGameWindow {
	public:
		/// @brief Constructs a game window with the specified title and size.
		/// @param game_title: The title of the game window.
		/// @param window_size: The dimensions of the game window.
		PenguinGameWindow(const std::string& game_title, Vector2<int> window_size);

		/// @brief Constructs a game window with the specified title and dimensions.
		/// @param game_title: The title of the game window.
		/// @param width: The width of the game window.
		/// @param height: The height of the game window.
		PenguinGameWindow(const std::string& game_title, int width, int height) : PenguinGameWindow(game_title, Vector2<int>(width, height)) {}

		/// @brief Constructs a game window with the specified dimensions and no title.
		/// @param width: The width of the game window.
		/// @param height: The height of the game window.
		PenguinGameWindow(int width, int height) : PenguinGameWindow("", Vector2<int>(width, height)) {}

		/// @brief Constructs a game window with the specified size and no title.
		/// @param window_size: The dimensions of the game window.
		explicit PenguinGameWindow(Vector2<int> window_size) : PenguinGameWindow("", window_size) {}

		/// @brief Default constructor, initializes a 640x480 game window.
		PenguinGameWindow();

		~PenguinGameWindow() = default;

		PenguinWindow window; /// The main game window.
		PenguinRenderer renderer; /// The renderer used for rendering graphics.
		PenguinTextRenderer text_renderer; /// The text renderer for rendering text.
		PenguinTimer timer; /// The game timer used to manage frame times.
		PenguinEventHandler event_handler; /// Handles user input and events.
		PenguinInput input; /// Manages keyboard input.
		int width; /// The width of the game window.
		int height; /// The height of the game window.

		/// @brief Connects a game instance to the game window.
		/// @param game: The unique pointer to the PenguinGame instance.
		void connect_game(std::unique_ptr<PenguinGame> game);

		/// @brief Runs the game loop.
		void run();

		/// @brief Stops the game loop.
		void stop_game();

		/// @brief Checks if the game is currently running.
		/// @return True if the game is running, otherwise false.
		bool is_running() const;

		/// @brief Checks if the window is still open.
		/// @return True if the window is open, otherwise false.
		bool is_open() const;

		/// @brief Closes the game window.
		void close_window();
		
	private:
		/// @brief Handles SDL events and processes them accordingly.
		/// @param p_event: The SDL event to be processed.
		void init_events(const SDL_Event& p_event);

		std::unique_ptr<PenguinGame> game_instance; /// Stores the instance of the created game.
		bool running; /// Tracks whether the game is currently running.
		bool window_open; /// Tracks whether the window is open.
	};
}

#endif // PENGUIN_GAME_WINDOW_HPP