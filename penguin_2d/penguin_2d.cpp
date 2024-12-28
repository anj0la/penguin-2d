// penguin_2d.cpp : Defines the entry point for the application.
//

#include "penguin_2d.hpp"

// Example program:
// Using SDL3 to create an application window

#include <SDL3/SDL.h>

using namespace Penguin2D;

int main(int argc, char* argv[]) {

    // SDL_Window* window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL3
   
    // Create an application window with the following settings:
    PenguinWindow window("A Penguin Window", Vector2<int>(640, 480), SDL_WINDOW_OPENGL);

   //  PenguinWindow window = PenguinWindow("An SDL3 Window", 640, 480, SDL_WINDOW_OPENGL);

    // PenguinRenderer renderer(window.get(), NULL); -> then what's the point of PenguinWindow(?)

    PenguinRenderer renderer(window, ""); // Moves the ownership of the window to Renderer

    renderer.clear();
    renderer.draw_rect();

    // But renderer 

    // Bruh, honestly, it seems like it would be so much easier to use raw pointers

    // Because when I move the ownership of window to renderer, when the renderer is destroyed, so should the window.

    // But when creating a window, I create a unique ptr to the Window.

    // Now, Renderer needs the window to actual be able to render anything onto the screen.

    // So, we transfer ownership of window from MAIN to PenguinRenderer. There, the window variable is pointed to the window inside 
    // PenguinRenderer.

    // But then to actually get the underlying pointer, we must use .get_window() to get the raw pointer.
    // Doesn't that meean that we have a pointer connecting to window in the SDL_CreateRender, and then the other pointer that has been transferred?

    // Honestly, if I was just encapsulating them in classes and using the destroy functions in the destructor, kinda like the smart pointer,
    // it would be easier.



    //window = SDL_CreateWindow(
    //    "An SDL3 window",                  // window title
    //    640,                               // width, in pixels
    //    480,                               // height, in pixels
    //    SDL_WINDOW_OPENGL                  // flags - see below
    //);

    //// Check that the window was successfully created
    //if (window == NULL) {
    //    // In the case that the window could not be made...
    //    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    //    return 1;
    //}

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    // SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}