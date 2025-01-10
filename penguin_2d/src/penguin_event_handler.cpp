#include "penguin_event_handler.hpp"

using namespace Penguin2D;

// Polls events.
void PenguinEventHandler::poll_events() {
	SDL_Event sdl_event;
	while (SDL_PollEvent(&sdl_event)) {

		// Check for quit event.
		if (sdl_event.type == SDL_EVENT_QUIT) {
			quit = true; // Request to close the window
		}

		// Call other functions to handle specific events.
		for (auto& callback_function : callback_functions) {
			callback_function(sdl_event);
		}
	}
}

// Adds an event listener.
void PenguinEventHandler::add_event_listener(const std::function<void(const SDL_Event&)>& callback_function) {
	callback_functions.push_back(callback_function);
}

bool PenguinEventHandler::should_quit() const {
	return quit;
}
