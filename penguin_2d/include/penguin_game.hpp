#ifndef PENGUIN_GAME_HPP
#define PENGUIN_GAME_HPP

#include "penguin_window.hpp"
#include "penguin_renderer.hpp"
#include "penguin_input.hpp"
#include "penguin_event_handler.hpp"
#include "penguin_sdl_manager.hpp"
#include "vector2.hpp"
#include "rect2.hpp"
#include "colour.hpp"
#include "exception.hpp"

#include <SDL3/SDL.h>
// #include <SDL3_ttf/SDL_ttf.h>

namespace Penguin2D {

	class PenguinGame {
	public:
		PenguinGame();
		~PenguinGame() = default;

		void run();

	protected:
		virtual void init();
		virtual void update(float delta_time);
		virtual void draw(float delta_time);
		virtual void quit();

	private:
		PenguinSDLManager sdl_manager; // ORDER MATTERS -> sdl_manager is destructed last (so SDL_quit() is called last)
		PenguinWindow window;
		PenguinRenderer renderer;
		PenguinEventHandler event_handler;
		PenguinInput input;

		void init_events(const SDL_Event& p_event);
	};
}

#endif // PENGUIN_GAME_HPP