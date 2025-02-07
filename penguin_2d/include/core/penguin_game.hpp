///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_game.hpp                                                 ///
///                                                                             ///
/// Defines the PenguinGame class, which serves as the base class for creating  ///
/// a game with Penguin2D. This class provides virtual functions for game		///
/// initialization, updating game logic, rendering, and quitting.				///
///																				///
/// Derived classes must override these functions.                              ///
///                                                                             ///
/// Functions to override:                                                      ///
///  - init() -> Initialize game variables (e.g., player starting position).    ///
///  - update(delta_time) -> Game logic goes here.                              ///
///  - draw(alpha) -> Render game objects to the screen.                        ///
///  - quit() -> Cleanup and free resources.                                    ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_GAME_HPP
#define PENGUIN_GAME_HPP

namespace Penguin2D {

	/// @brief An abstract base class for defining the game logic and lifecycle.
	///
	/// This class provides a set of virtual methods that define the basic structure of a game.
	/// Concrete game classes will inherit from this and implement the necessary behavior for initialization,
	/// updating game states, rendering, and quitting.
	class PenguinGame {
	public:
		virtual ~PenguinGame() = default;

		/// @brief Initializes the game, setting up necessary resources.
		virtual void init() = 0;

		/// @brief Updates the game state for the current frame.
		/// @param delta_time: The time elapsed since the last frame.
		virtual void update(double delta_time) = 0;

		/// @brief Draws the current state of the game to the screen.
		/// @param alpha: The interpolation factor used for rendering.
		virtual void draw(double alpha) = 0;

		/// @brief Quits the game and cleans up any resources.
		virtual void quit() = 0;
	};
}

#endif // PENGUIN_GAME_HPP