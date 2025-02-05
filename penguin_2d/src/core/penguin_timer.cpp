/// File name: penguin_timer.cpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinTimer manages frame rate for the game, and allows for capping the fps at a specific framerate (e.g., 60 FPS or 30 FPS).
/// 
/// This class is used internally in PenguinGameWindow to update and render the game by using functions such as consume_time() and update_frame_time().
///

#include "penguin_timer.hpp"

using namespace Penguin2D;

/// <summary>
/// Calculates the frame time and updates the accumulator.
/// </summary>
void PenguinTimer::update_frame_time() {
    auto curr_time = penguin_clock::now();
    double frame_time = std::chrono::duration<double>(curr_time - prev_time).count();
    if (frame_time > 0.25) {
        frame_time = 0.25;
    }
    prev_time = curr_time;
    accumulator += frame_time;

}
/// <summary>
/// Updates the FPS by incrementing the frame count, measuring the elasped time since the last update and calculating the FPS.
/// </summary>
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

/// <summary>
/// Consumes a fixed timestep from the accumulator and increments the running time.
/// </summary>
void PenguinTimer::consume_time() {
    accumulator -= delta_time;
    running_time += delta_time;
}

/// <summary>
/// Caps the FPS to the specified value.
/// </summary>
/// <param name="enable"> - whether to cap fps or not.</param>
/// <param name="fps"> - the value to cap the fps to.</param>
void PenguinTimer::set_fps_cap(bool enable, double fps) {
    // Cap FPS to the fps parameter (if enabled == true).
    cap_fps = enable;
    if (enable) {
        target_fps = fps;
        target_frame_time = 1.0 / target_fps;
    }
}

/// <summary>
/// Caps the frame rate until the target fps has been reached.
/// </summary>
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

/// <summary>
/// Checks if enough time has accumulated for an update.
/// </summary>
/// <returns>bool - true if enough time has been accumulated, false otherwise.</returns>
bool PenguinTimer::should_update() const {
    return accumulator >= delta_time;
}

/// <summary>
/// Returns the interpolation factor for rendering.
/// </summary>
/// <returns>double - the interpolation factor.</returns>
double PenguinTimer::get_alpha() const {
    return accumulator / delta_time;
}

/// <summary>
/// Returns the delta time.
/// </summary>
/// <returns>double - delta time.</returns>
double PenguinTimer::get_delta_time() const {
    return delta_time;
}

/// <summary>
/// Returns the fps.
/// </summary>
/// <returns>double - fps.</returns>
double PenguinTimer::get_fps() const {
    return fps;
}

/// <summary>
/// Delays execution for the specified amount of milliseconds.
/// </summary>
/// <param name="ms"> - the amount of time to delay execution for.</param>
void PenguinTimer::delay(double ms) {
    SDL_Delay(ms);
}