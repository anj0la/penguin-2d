#include "penguin_timer.hpp"
#include <iostream>

using namespace Penguin2D;

void PenguinTimer::update_frame_time() {
    // Calculate frame time and update accumulator.
    auto curr_time = penguin_clock::now();
    double frame_time = std::chrono::duration<double>(curr_time - prev_time).count();
    if (frame_time > 0.25) {
        frame_time = 0.25;
    }
    prev_time = curr_time;
    accumulator += frame_time;

}

void PenguinTimer::consume_time() {
    // Consume a fixed timestep from the accumulator.
    accumulator -= delta_time;
    // Increment running time.
    running_time += delta_time;
}

bool PenguinTimer::should_update() const {
    // Check if enough time has accumulated for an update.
    return accumulator >= delta_time;
}

double PenguinTimer::get_alpha() const {
    // Return the interpolation factor for rendering.
    return accumulator / delta_time;
}
double PenguinTimer::get_delta_time() const {
    return delta_time;
}

double PenguinTimer::get_fps() const {
    return fps;
}