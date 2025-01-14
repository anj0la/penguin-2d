#include "penguin_timer.hpp"
#include <iostream>

using namespace Penguin2D;

// Calculates the frame time and updates the accumulator.
void PenguinTimer::update_frame_time() {
    auto curr_time = penguin_clock::now();
    double frame_time = std::chrono::duration<double>(curr_time - prev_time).count();
    if (frame_time > 0.25) {
        frame_time = 0.25;
    }
    prev_time = curr_time;
    accumulator += frame_time;

}

// Updates the FPS by incrementing the frame count, measuring the elasped time since the last update and calculating the FPS.
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

        // std::cout << "FPS: " << fps << std::endl; // FOR DEBUGGING PURPOSES
    }
}

// Consumes a fixed timestep from the accumulator and increments the running time.
void PenguinTimer::consume_time() {
    accumulator -= delta_time;
    running_time += delta_time;
}

void PenguinTimer::set_fps_cap(bool enable, double fps) {
    // Cap FPS to the fps parameter (if enabled == true).
    cap_fps = enable;
    if (enable) {
        target_fps = fps;
        target_frame_time = 1.0 / target_fps;
    }
}

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

// Checks if enough time has accumulated for an update.
bool PenguinTimer::should_update() const {
    return accumulator >= delta_time;
}

// Returns the interpolation factor for rendering.
double PenguinTimer::get_alpha() const {
    return accumulator / delta_time;
}
double PenguinTimer::get_delta_time() const {
    return delta_time;
}

double PenguinTimer::get_fps() const {
    return fps;
}