/// File name: penguin_game.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinGame represents a base game class, with virtual functions that are overridden in derived classes.
/// 
/// This class is the base class for constructing a game with Penguin2D. It has four functions that the derived classes must override, which are the following:
///		init() -> can be used to initialize game variables (e.g., starting position of the player),
///		update(delta_time) -> where all game logic resides in,
///		draw(alpha) -> to render all game objects onto the screen,
///		quit() -> can be used to save game resources, called before game objects are freed.
///

#ifndef PENGUIN_GAME_HPP
#define PENGUIN_GAME_HPP

namespace Penguin2D {

	class PenguinGame {
	public:
		virtual ~PenguinGame() = default;

		virtual void init() = 0;
		virtual void update(double delta_time) = 0;
		virtual void draw(double alpha) = 0;
		virtual void quit() = 0;
	};
}

#endif // PENGUIN_GAME_HPP