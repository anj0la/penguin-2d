///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_timer.hpp												///
///                                                                             ///
/// Defines the PenguinTimer class, which manages frame timing and FPS capping. ///
///                                                                             ///
/// This class is responsible for handling frame rate control, ensuring smooth  ///
/// and consistent frame timing. It provides methods for updating frame time,   ///
/// capping FPS, delaying execution, and checking if an update should occur.    ///
///                                                                             ///
/// The class is used internally in PenguinGameWindow to regulate game updates  ///
/// and rendering cycles. Modifications to this class impact the game's timing  ///
/// structure and should be made cautiously.                                    ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_TIMER_HPP
#define PENGUIN_TIMER_HPP

// SDL related include files
#include <SDL_timer.h>

// C++ library files
#include <chrono>
#include <thread>

namespace Penguin2D {

    /// @brief Manages game timing, frame rate control, and updates.
    ///
    /// This class is responsible for handling delta time calculations,
    /// managing frame updates, and optionally capping the frame rate. It provides
    /// methods for synchronizing game updates, retrieving FPS, and enforcing delays
    /// to maintain a stable frame rate.
	class PenguinTimer {
	public:
        /// @brief Constructs a PenguinTimer with the given delta time, fps cap and target fps.
        /// @param dt: The delta time value (optional, defaults to 1.0 / 60.0).
        /// @param should_cap_fps: Enables or disables FPS capping (optional, defaults to false).
        /// @param fps_target: Target FPS value (optional, defaults to 60.0).
		PenguinTimer(double dt = 1.0 / 60.0, bool should_cap_fps = false, double fps_target = 60.0)
			: delta_time(dt), cap_fps(should_cap_fps), target_fps(fps_target) {}
		~PenguinTimer() = default;

        /// @brief Updates the frame timing and accumulates elapsed time.
        void update_frame_time();

        /// @brief Updates the FPS counter.
        void update_fps();

        /// @brief Consumes accumulated time to synchronize game updates with the frame rate.
        void consume_time();

        /// @brief Enables or disables FPS capping and sets the target FPS.
        /// @param enable: True to enable FPS capping, false to disable.
        /// @param fps: Target FPS value (default is 60.0).
        void set_fps_cap(bool enable, double fps = 60.0);

        /// @brief Caps the frame rate by enforcing a delay if the frame time is too short.
        void cap_frame_rate() const;

        /// @brief Checks whether the game should update based on the accumulated time.
        /// @return True if an update should occur, otherwise false.
        bool should_update() const;

        /// @brief Gets the interpolation factor (alpha) used for rendering.
        /// @return The alpha value between the last and current update.
        double get_alpha() const;

        /// @brief Retrieves the fixed delta time used for physics updates.
        /// @return The delta time value.
        double get_delta_time() const;

        /// @brief Retrieves the current frames per second (FPS).
        /// @return The FPS value.
        double get_fps() const;

        /// @brief Delays execution for a specified amount of time.
        /// @param ms: Time in milliseconds to pause execution.
        void delay(double ms);

	private:
		using penguin_clock = std::chrono::steady_clock;
		double delta_time;
		bool cap_fps;
		double target_fps;  
		double target_frame_time = 1.0 / target_fps; 
		double running_time = 0.0;
		double accumulator = 0.0;
		int frame_count = 0;
		double fps = 0.0;
		penguin_clock::time_point prev_time = penguin_clock::now();
		penguin_clock::time_point fps_start_time = prev_time;
	};
}

#endif // PENGUIN_TIMER_HPP