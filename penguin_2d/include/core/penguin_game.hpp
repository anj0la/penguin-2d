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