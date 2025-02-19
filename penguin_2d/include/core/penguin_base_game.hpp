///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_base_game.hpp                                            ///
///                                                                             ///
/// Defines the PenguinBaseGame class, which serves as the base class for		///
/// creating a game with Penguin2D.												///
///																				///
/// This class provides virtual functions for game initialization, updating		///
/// game logic, rendering, and quitting.										///
///																				///
/// Derived classes should override these functions:                            ///
///  - init() -> Initialize game variables (e.g., player starting position).    ///
///  - update(delta_time) -> Game logic goes here.                              ///
///  - draw(alpha) -> Render game objects to the screen.                        ///
///  - quit() -> Cleanup and free resources.                                    ///
///																				///
/// However, these functions have default empty implementations, so they can be ///
/// left unimplemented in derived classes if not needed.						///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_BASE_GAME_HPP
#define PENGUIN_BASE_GAME_HPP

// Penguin2D related include files
#include "penguin_game_window.hpp"

namespace Penguin2D {

	/// @brief An abstract base class for defining the game logic and lifecycle.
	///
	/// This class provides a set of virtual methods that define the basic structure of a game.
	/// Concrete game classes will inherit from this and implement the necessary behavior for initialization,
	/// updating game states, rendering, and quitting.
	class PenguinBaseGame : public PenguinGame {
	public:
		PenguinBaseGame(PenguinGameWindow& window) : game_window(window) {}
		~PenguinBaseGame() = default;
	protected:
		PenguinGameWindow& game_window;

		/// @brief Initializes the game, setting up necessary resources.
		void init() override {}

		/// @brief Updates the game state for the current frame.
		/// @param delta_time: The time elapsed since the last frame.
		void update(double delta_time) override {}

		/// @brief Draws the current state of the game to the screen.
		/// @param alpha: The interpolation factor used for rendering.
		void draw(double alpha) override {};

		/// @brief Quits the game and cleans up any resources.
		void quit() override {};
	};
}

#endif // PENGUIN_BASE_GAME_HPP