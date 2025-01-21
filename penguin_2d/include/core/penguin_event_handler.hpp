#ifndef PENGUIN_EVENT_HPP
#define PENGUIN_EVENT_HPP

#include <SDL3/SDL_events.h>
#include <vector>
#include <functional>

namespace Penguin2D {
	class PenguinEventHandler {
	public:
		PenguinEventHandler() = default;
		~PenguinEventHandler() = default;
		void poll_events();
		void add_event_listener(const std::function<void(const SDL_Event&)>& callback_function);
		bool should_quit() const;
	private:
		std::vector<std::function<void(const SDL_Event&)>> callback_functions; // Stores all callback functions related to the event.
		bool quit = false;
	};
}

#endif // PENGUIN_EVENT_HPP