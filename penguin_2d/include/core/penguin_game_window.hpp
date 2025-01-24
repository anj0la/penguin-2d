#ifndef PENGUIN_GAME_WINDOW_HPP
#define PENGUIN_GAME_WINDOW_HPP

// Penguin2D related include files
#include "penguin_window.hpp"
#include "penguin_renderer.hpp"
#include "penguin_text_renderer.hpp"
#include "penguin_input.hpp"
#include "penguin_event_handler.hpp"
#include "penguin_sdl_manager.hpp"
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

	class PenguinGameWindow {
	public:
		PenguinGameWindow(const std::string& game_title, Vector2<int> window_size);
		PenguinGameWindow(const std::string& game_title, int width, int height) : PenguinGameWindow(game_title, Vector2<int>(width, height)) {}
		PenguinGameWindow(int width, int height) : PenguinGameWindow("", Vector2<int>(width, height)) {}
		explicit PenguinGameWindow(Vector2<int> window_size) : PenguinGameWindow("", window_size) {}
		PenguinGameWindow(); // default constructor (initializes window size to 640 x 480)

		~PenguinGameWindow() = default;

		PenguinSDLManager sdl_manager; // ORDER MATTERS -> sdl_manager is destructed last (so SDL_Quit() is called last)
		PenguinWindow window;
		PenguinRenderer renderer;
		PenguinTextRenderer text_renderer;
		PenguinTimer timer;
		PenguinEventHandler event_handler;
		PenguinInput input;
		int width;
		int height;

		void connect_game(std::unique_ptr<PenguinGame> game);
		void run();
		
	private:
		void init_events(const SDL_Event& p_event);
		std::unique_ptr<PenguinGame> game_instance; // Stores instance of the created game
	};
}

#endif // PENGUIN_GAME_WINDOW_HPP