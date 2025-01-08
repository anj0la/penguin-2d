#include "penguin_2d.hpp"
#include <stdexcept>
#include <iostream>

using namespace Penguin2D;

// Displays text onto the screen. Ideally PenguinTextRenderer and PenguinRenderer would be a class / struct object, so that the text size can be passed.
// For the font, it could be passed as well.
void display_text(PenguinTextRenderer& text_engine, PenguinRenderer& renderer, const char* text_p, float size, Vector2<>position) {
    PenguinText text(text_engine, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\fonts\\pixelify_sans_regular.ttf", text_p, size);
    text.set_text_colour(Colours::WHITE);
    text.render_text(position);
}

int main(int argc, char* argv[]) {

    // Initialize SDL. -> Ideally will be abstracted further.
    Exception::throw_if(
        !SDL_Init(SDL_INIT_VIDEO),
        "Could not initialize SDL3.",
        INIT_ERROR
    );

    // Initialize SDL_TTF.
    Exception::throw_if(
        !TTF_Init(),
        "Could not initialize SDL_TTF.",
        INIT_ERROR
    );

    // Create an application window of size 640 by 480 that is useable with OpenGL.
    PenguinWindow window("A Penguin Window", Vector2<int>(640, 480), SDL_WINDOW_OPENGL);

    // Create a renderer that uses the above window.
    PenguinRenderer renderer(window, "");

    // ######## THE FOLLOWING CODE SHOULD BE ADDED INTO SOME CLASS LIKE PENGUINEVENT ########

    // Create an event handler and input (currently supports the UP, DOWN, LEFT, RIGHT, X and ESC keys).
    PenguinEventHandler event_handler;
    PenguinInput input;

    // Add the handle input event function as a listener to the event handler.
    event_handler.add_event_listener([&input](const SDL_Event& p_event) { // Probably will abstract this away (doing it automatically).
        input.handle_input_event(p_event);
        });

    // ################

    // Create the text renderer.
    PenguinTextRenderer text_engine(renderer);

    display_text(text_engine, renderer, "Hello Penguin 2D!", 24.0f, Vector2<>(480.0 / 2, 10));
    renderer.present();


    // So we should be updating text by creating a text object, then destroying it once it isn't needed anymore. It is still rendered onto the screen,
    // but the text object itself is destroyed. Maybe once I have created our Engine / Game class, I would provide such a function.

    bool game_running = true;

    while (game_running) { // would be changed to while (game_running), and quit would set the game's state to false.

        event_handler.poll_events();

        // Clear renderer for drawing
        renderer.clear();

        // Check if the game should be quit (i.e., close the window)
        if (event_handler.should_quit()) {
            game_running = false;
        }

        if (input.is_key_pressed(PenguinKey::KEY_A)) { // Render the rect onto the screen.
            renderer.draw_rect(Rect2<float>(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0)), Colours::WHITE, Colours::RED);
        }
        if (input.is_key_pressed(PenguinKey::ESC)) {
            game_running = false; // Close the window.
        }
        if (input.is_key_pressed(PenguinKey::KEY_X)) {
            display_text(text_engine, renderer, "You pressed the X button!", 24.0f, Vector2<>(480.0 / 2, 400));
        }

        // Present renderer after finishing drawing
        renderer.present();

    }

    // Clean up.
    TTF_Quit(); // Cleans up SDL_ttf related items.
    SDL_Quit(); // Cleans up SDL related items.
    // TTF_CloseFont(font);
    return 0;
}