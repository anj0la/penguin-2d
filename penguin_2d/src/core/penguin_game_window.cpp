#include "penguin_game_window.hpp"

using namespace Penguin2D;

PenguinGameWindow::PenguinGameWindow(const std::string& game_title, Vector2<int> window_size)
    : window(game_title, window_size),    
    renderer(window),
    text_renderer(renderer),
    timer() {

    // Add listener for the input to the event handler
    event_handler.add_event_listener([this](const SDL_Event& p_event) {
        init_events(p_event);
        });

    width = window_size.x;
    height = window_size.y;

    running = false;
    window_open = true;
}

// Default constructor. Sets window size to 640 x 480.
PenguinGameWindow::PenguinGameWindow()
    : window("A Penguin Window", Vector2<int>(640, 480)),
    renderer(window),
    text_renderer(renderer),
    timer() {

    // Add listener for the input to the event handler
    event_handler.add_event_listener([this](const SDL_Event& p_event) {
        init_events(p_event);
        });

    width = 640;
    height = 480;

    running = false;
    window_open = true;
}

void PenguinGameWindow::init_events(const SDL_Event& p_event) {
    input.handle_input_event(p_event);
}

void PenguinGameWindow::connect_game(std::unique_ptr<PenguinGame> game) {
    game_instance = std::move(game);
}

void PenguinGameWindow::run() {

    // Throw error if a game has NOT been connected to the window.
    Exception::throw_if(
        !game_instance,
        "A game has not been connected to the game window. Make sure to connect a game with connect_game(game) before calling this function",
        RUNTIME_ERROR
    );

    // Initalize the game with user defined values.
    game_instance->init();

    running = true;

    // Game loop.
    while (running) {

        event_handler.poll_events();

        timer.update_frame_time();

        while (timer.should_update()) {
            auto delta_time = timer.get_delta_time();
            game_instance->update(delta_time);
            timer.consume_time();
        }

        double alpha = timer.get_alpha();

        // Clear renderer for drawing.
        renderer.clear();

        game_instance->draw(alpha);

        // Display objects drawn onto renderer.
        renderer.present();

        // Close the window if the user specifies it.
        if (event_handler.should_quit()) {
            running = false;
        }

        timer.update_fps(); // Track the actual FPS
        timer.cap_frame_rate(); // If enabled, caps frame rate to target FPS
    }

    // Clean up game processes (e.g., saving game objects, closing other third-party libraries.
    game_instance->quit();

} // The destructor will clean up the SDL_related resources.

void PenguinGameWindow::stop_game() {
    running = false;
}

bool PenguinGameWindow::is_running() const {
    return running;
}

bool PenguinGameWindow::is_open() const {
    return window_open;
}

void PenguinGameWindow::close_window() {
    window_open = false;
}