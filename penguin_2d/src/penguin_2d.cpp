// penguin_2d.cpp : Defines the entry point for the application.
//

#include "penguin_2d.hpp"

// Example program:
// Using SDL3 to create an application window

using namespace Penguin2D;

int main(int argc, char* argv[]) {

    Exception::throw_if(
        !SDL_Init(SDL_INIT_VIDEO),
        "Could not initialize SDL3.",
        INIT_ERROR);
    
    // Create an application window of size 640 by 480, with OpenGL.
    PenguinWindow window("A Penguin Window", Vector2<int>(640, 480), SDL_WINDOW_OPENGL);

    // Create a renderer that uses the above window.
    PenguinRenderer renderer(window, ""); 


    // Event handler. TODO - MOVE INTO OWN CLASS (like PenguinWindow and PenguinRenderer)
    SDL_Event e; // instance variable in class
    bool quit = false; // instance variable in class

    while (!quit) { // would be changed to while (game_running), and quit would set the game's state to false.

        // Poll event loop
        while (SDL_PollEvent(&e)) {
            // User requests to quit game.
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }

            // User presses a key.
            else if (e.type == SDL_EVENT_KEY_DOWN) {
                // Choose what to do.
                switch (e.key.key) {
                // Quit the game by pressing ESC.
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                // Render the rect onto the screen.
                case SDLK_X:
                    renderer.clear();
                    renderer.draw_rect(Rect2<float>(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0)), Colours::WHITE, Colours::RED);
                    renderer.present();
                    break;
                }
            }
        }
    }

    // Clean up.
    SDL_Quit();
    return 0;
}