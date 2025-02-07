///////////////////////////////////////////////////////////////////////////////////
/// File: penguin_timer.cpp                                                     ///
///                                                                             ///
/// PenguinTimer manages frame rate for the game and allows for capping the     ///
/// FPS at a specific framerate (e.g., 60 FPS or 30 FPS).                       ///
///                                                                             ///
/// This class is used internally in PenguinGameWindow to update and render     ///
/// the game by using functions such as consume_time() and update_frame_time(). ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_timer.hpp"

using namespace Penguin2D;

/// @brief Calculates the frame time and updates the accumulator.
///
/// This function determines the time elapsed since the last frame and updates
/// the accumulator accordingly. It also ensures that the frame time does not
/// exceed a threshold to prevent excessive updates due to lag.
void PenguinTimer::update_frame_time() {
    auto curr_time = penguin_clock::now();
    double frame_time = std::chrono::duration<double>(curr_time - prev_time).count();
    if (frame_time > 0.25) {
        frame_time = 0.25;
    }
    prev_time = curr_time;
    accumulator += frame_time;

}

/// @brief Updates the FPS counter.
///
/// This function tracks the number of frames rendered within a second and calculates
/// the frames per second (FPS) accordingly. It resets the counter after each interval.
void PenguinTimer::update_fps() {
    // Increment frame count.
    frame_count++;

    // Measure elapsed time since last FPS update.
    auto curr_time = penguin_clock::now();
    double elapsed_time = std::chrono::duration<double>(curr_time - fps_start_time).count();

    if (elapsed_time >= 1.0) {
        // Calculate FPS and reset for the next interval.
        fps = frame_count / elapsed_time;
        frame_count = 0;
        fps_start_time = curr_time;
    }
}

/// @brief Consumes a fixed timestep from the accumulator and updates running time.
///
/// This function removes a fixed delta time from the accumulator to keep time
/// progression consistent with the game loop's update rate.
void PenguinTimer::consume_time() {
    accumulator -= delta_time;
    running_time += delta_time;
}

/// @brief Enables or disables FPS capping and sets the target frame rate.
/// 
/// /// If FPS capping is enabled, the function sets the target frame duration
/// based on the desired FPS value.
/// @param enable: Whether to cap the FPS.
/// @param fps: The target FPS value.
void PenguinTimer::set_fps_cap(bool enable, double fps) {
    // Cap FPS to the fps parameter (if enabled == true).
    cap_fps = enable;
    if (enable) {
        target_fps = fps;
        target_frame_time = 1.0 / target_fps;
    }
}

/// @brief Delays execution to maintain a consistent frame rate.
///
/// This function ensures that the frame rate does not exceed the specified cap
/// by pausing execution for the required duration.
void PenguinTimer::cap_frame_rate() const {
    if (!cap_fps) return; // No capping needed if disabled.

    auto curr_time = penguin_clock::now();
    double elapsed_time = std::chrono::duration<double>(curr_time - prev_time).count();

    // Enforce target frame rate.
    if (elapsed_time < target_frame_time) {
        double sleep_time = target_frame_time - elapsed_time;
        std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
    }
}

/// @brief Determines if enough time has accumulated for an update.
/// @return True if an update should occur, otherwise false.
bool PenguinTimer::should_update() const {
    return accumulator >= delta_time;
}

/// @brief Returns the interpolation factor for rendering.
/// 
/// This function calculates the alpha value used for rendering interpolation,
/// helping smooth motion between fixed timestep updates.
/// @return The interpolation factor as a double.
double PenguinTimer::get_alpha() const {
    return accumulator / delta_time;
}

/// @brief Retrieves the delta time value.
/// @return The delta time as a double.
double PenguinTimer::get_delta_time() const {
    return delta_time;
}

/// @brief Retrieves the current FPS value.
/// @return The current FPS as a double.
double PenguinTimer::get_fps() const {
    return fps;
}

/// @brief Delays execution for a specified amount of milliseconds.
/// 
/// This function pauses execution for the specified duration.
/// It can be used to introduce artificial delays in certain situations.
/// @param ms: The amount of time to delay execution for, in milliseconds.
void PenguinTimer::delay(double ms) {
    SDL_Delay(ms);
}