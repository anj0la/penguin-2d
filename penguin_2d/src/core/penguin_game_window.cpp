///////////////////////////////////////////////////////////////////////////////////
/// File: penguin_game_window.cpp                                               ///
///                                                                             ///
/// This file implements the PenguinGameWindow class, which serves as the core  ///
/// window and rendering manager for a game using the Penguin2D engine. It      ///
/// initializes the game window, handles input events, manages the game loop,   ///
/// and ensures smooth frame updates.                                           ///
///                                                                             ///
/// The run function is central to this class, executing the main game loop. It ///
/// processes events, updates game logic, and renders frames while managing     ///
/// delta time and FPS to ensure consistent performance across different        ///
/// hardware. Additionally, it handles proper cleanup when the game terminates. ///
///                                                                             ///
/// The connect_game function is responsible for linking a PenguinGame instance ///
/// to the window. Once a game is connected, its lifecycle methods (init,       ///
/// update, draw, and quit) are executed within the run function. This ensures  ///
/// the game properly initializes, processes frame updates, renders smoothly,   ///
/// and cleans up resources when closing.                                       ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_game_window.hpp"

using namespace Penguin2D;

/// @brief Constructs a PenguinGameWindow with a given title and window size.
/// @param game_title: The title of the game window.
/// @param window_size: The size of the window as a Vector2 (int).
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

/// @brief Default constructor. Initializes the window with a default size of 640x480.
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

/// @brief Initializes event handling for the game window.
/// @param p_event: The SDL event to process.
void PenguinGameWindow::init_events(const SDL_Event& p_event) {
    input.handle_input_event(p_event);
}

/// @brief Connects a game instance to the game window.
/// @param game: A unique pointer to a PenguinGame instance.
void PenguinGameWindow::connect_game(std::unique_ptr<PenguinGame> game) {
    game_instance = std::move(game);
}

/// @brief Runs the game loop.
/// @throws Exception: if a game instance is not connected before calling this function.
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
        game_instance->draw(alpha);

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

/// @brief Stops the game loop.
void PenguinGameWindow::stop_game() {
    running = false;
}

/// @brief Checks if the game is currently running.
/// @return bool: True if the game is running, false otherwise.
bool PenguinGameWindow::is_running() const {
    return running;
}

/// @brief Checks if the game window is open.
/// @return bool: True if the window is open, false otherwise.
bool PenguinGameWindow::is_open() const {
    return window_open;
}

/// @brief Closes the game window.
void PenguinGameWindow::close_window() {
    window_open = false;
}