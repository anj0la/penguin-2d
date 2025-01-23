#ifndef PENGUIN_GAME_HPP
#define PENGUIN_GAME_HPP

#include "penguin_window.hpp"
#include "penguin_renderer.hpp"
#include "penguin_text_renderer.hpp"
#include "penguin_input.hpp"
#include "penguin_event_handler.hpp"
#include "penguin_sdl_manager.hpp"
#include "penguin_timer.hpp"
#include "vector2.hpp"
#include "rect2.hpp"
#include "colour.hpp"
#include "exception.hpp"

#include <SDL3/SDL.h>
// #include <SDL3_ttf/SDL_ttf.h>

namespace Penguin2D {

	class PenguinGame {
	public:
		// We need the window title, we need the window size, and a default param for the window
		PenguinGame(const std::string& game_title, Vector2<int> window_size);
		PenguinGame(const std::string& game_title, int width, int height) : PenguinGame(game_title, Vector2<int>(width, height)) {}
		PenguinGame(int width, int height) : PenguinGame("", Vector2<int>(width, height)) {}
		explicit PenguinGame(Vector2<int> window_size) : PenguinGame("", window_size) {}
		PenguinGame(); // default constructor (initializes window size to 640 x 480)

		~PenguinGame() = default;

		void run();

	protected:
		PenguinSDLManager sdl_manager; // ORDER MATTERS -> sdl_manager is destructed last (so SDL_Quit() is called last)
		PenguinWindow window;
		PenguinRenderer renderer;
		PenguinTextRenderer text_renderer;
		PenguinTimer timer;
		PenguinEventHandler event_handler;
		PenguinInput input;

		int width;
		int height;

		virtual void init();
		virtual void update(double delta_time);
		virtual void draw(double delta_time);
		virtual void quit();

	private:
		void init_events(const SDL_Event& p_event);
	};
}

#endif // PENGUIN_GAME_HPP