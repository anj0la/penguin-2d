///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_event_handler.hpp                                        ///
///                                                                             ///
/// Defines the PenguinEventHandler class, which manages SDL event handling.	///
///																				///
/// It allows for polling events, registering event listeners, and checking the ///
/// application's quit state.													///
///																				///
/// The event handler stores callback functions that process SDL events when	///
/// polled, enabling flexible event handling, such as user input through		///
/// PenguinInput. It also tracks whether the user has requested to close the	///
///	window.																		///
///																				///
/// Reference: https://github.com/aardhyn/sdl3-template-project/tree/main       ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_EVENT_HPP
#define PENGUIN_EVENT_HPP

// SDL related include files
#include <SDL_events.h>

// C++ standard library files
#include <vector>
#include <functional>

namespace Penguin2D {
	/// @brief Manages window event polling and event listener callbacks.
	///
	/// This class is responsible for handling window events,
	/// invoking registered event listener callbacks, and tracking whether a quit
	/// event has been requested. It allows external components to register event
	/// listeners that will be triggered whenever an event is polled.
	class PenguinEventHandler {
	public:
		PenguinEventHandler() = default;
		~PenguinEventHandler() = default;

		/// @brief Polls events and invokes all registered event listener callbacks.
		void poll_events();

		/// @brief Adds an event listener to be triggered during event polling.
		/// 
		/// @param callback_function: Function to be called when an event occurs.
		void add_event_listener(const std::function<void(const SDL_Event&)>& callback_function);

		/// @brief Checks if the user has requested to close the application.
		/// 
		/// @return True if a quit event has been detected, otherwise false.
		bool should_quit() const;
	private:
		/// Stores all registered event callbacks.
		std::vector<std::function<void(const SDL_Event&)>> callback_functions; 

		/// Tracks whether a quit event has been received.
		bool quit = false; 
	};
}

#endif // PENGUIN_EVENT_HPP