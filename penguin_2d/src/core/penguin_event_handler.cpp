/// File: penguin_event_handler.cpp
/// 
/// Description:
/// This file implements the PenguinEventHandler class, which is responsible for handling SDL events.
/// It processes event polling, manages callback functions, and detects quit requests.

#include "penguin_event_handler.hpp"

using namespace Penguin2D;

/// @brief Polls SDL events and executes all registered callback functions.
///
/// This function retrieves SDL events from the event queue and calls any registered event listeners.
/// If a quit event (SDL_EVENT_QUIT) is detected, the event handler marks the application for termination.
void PenguinEventHandler::poll_events() {
	SDL_Event sdl_event;
	while (SDL_PollEvent(&sdl_event)) {

		if (sdl_event.type == SDL_EVENT_QUIT) {
			quit = true; // Mark application for closure
		}

		// Notify all registered listeners of the event
		for (auto& callback_function : callback_functions) {
			callback_function(sdl_event); 
		}
	}
}

/// @brief Registers a new event listener callback.
/// @param callback_function: Function to be executed when an event occurs.
void PenguinEventHandler::add_event_listener(const std::function<void(const SDL_Event&)>& callback_function) {
	callback_functions.push_back(callback_function);
}

/// @brief Checks whether the application should terminate due to a quit event.
/// @return True if a quit event has been detected, otherwise false.
bool PenguinEventHandler::should_quit() const {
	return quit;
}
