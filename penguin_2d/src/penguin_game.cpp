#include "penguin_game.hpp"

using namespace Penguin2D;

PenguinGame::PenguinGame()
    : sdl_manager(),                        // SDL is initialized here
    window(Vector2<int>(640.0, 480.0)),     // SDL-dependent objects follow
    renderer(window) {

    // Add listener for the input to the event handler
    event_handler.add_event_listener([this](const SDL_Event& p_event) {
        init_events(p_event);
        });
}

void PenguinGame::init() {}

void PenguinGame::init_events(const SDL_Event& p_event) {
    input.handle_input_event(p_event);
}

void PenguinGame::run() {

    // Initialize the game with your own game values.
    init();

    // PenguinTimer timer();

    bool running = true;

    // Game loop
    while (running) {

        // timer.

        event_handler.poll_events();

        float delta_time = 0.0f; // Placeholder until framerate calculation (i.e., fixed / variable timestemp) is added.

        update(delta_time);
        draw(delta_time);

        if (event_handler.should_quit()) {
            running = false;
        }

    }

    // Clean up game processes (e.g., saving game objects, closing other third-party libraries
    quit();

} // The destructor will clean up the SDL_related resources.

void PenguinGame::update(float delta_time) {}

void PenguinGame::draw(float delta_time) {}

void PenguinGame::quit() {}