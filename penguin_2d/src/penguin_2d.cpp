#include "penguin_2d.hpp"
#include <stdexcept>
#include <iostream>

using namespace Penguin2D;

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

    // TTF_TextEngine* text_engine = TTF_CreateRendererTextEngine(renderer.get_renderer());

    TTF_Font* font = TTF_OpenFont("C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\fonts\\pixelify_sans_regular.ttf", 24.0f);

    TTF_Text* text = TTF_CreateText(text_engine.get_text_renderer(), font, "Hello world!", 0);
    bool success = TTF_SetTextColor(text, 255, 255, 255, 255);
    if (!success) {
        throw std::runtime_error(SDL_GetError());
    }

    // TEST - Create the font.
    //PenguinFont font("C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\fonts\\pixelify_sans_regular.ttf", 24.0f);

    // Create the text. ERROR OCCURS
    // PenguinText text(text_engine, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\fonts\\pixelify_sans_regular.ttf", "A test string!", 24.0f);

    // PenguinText text(text_engine, "fonts/pixelify_sans_regular.ttf", "A test string!", Colours::WHITE, Vector2<int>(0, 0));

    bool game_running = true;

    while (game_running) { // would be changed to while (game_running), and quit would set the game's state to false.

        event_handler.poll_events();

        // Check if the game should be quit (i.e., close the window)
        if (event_handler.should_quit()) {
            game_running = false;
        }

        if (input.is_key_pressed(PenguinKey::KEY_A)) { // Render the rect onto the screen.
            renderer.clear();
            renderer.draw_rect(Rect2<float>(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0)), Colours::WHITE, Colours::RED);
            // text.render_text(Vector2<float>(300.0, 300.0));
            renderer.present();
        }
        if (input.is_key_pressed(PenguinKey::ESC)) {
            game_running = false; // Close the window.
        }
        if (input.is_key_pressed(PenguinKey::KEY_X)) {
            // SDL_FlushRenderer(renderer.get_renderer());
            bool success = TTF_DrawRendererText(text, 200.0, 200.0);
            if (!success) {
                throw std::runtime_error(SDL_GetError());
            }
            renderer.present();

        }

    }

    // Closing the font (delete later)
    TTF_CloseFont(font);
    TTF_DestroyText(text);
    //TTF_DestroyRendererTextEngine(text_engine);

    // Clean up.
    TTF_Quit(); // Cleans up SDL_ttf related items.
    SDL_Quit(); // Cleans up SDL related items.
    return 0;
}