#ifndef PENGUIN_MAIN_HPP
#define PENGUIN_MAIN_HPP

#include "penguin_init.hpp"
#include <SDL3/SDL_main.h>
#include <iostream>

using namespace Penguin2D;

// The game's entry point
extern int PenguinMain();

// SDL requires a main function
int main(int argc, char* argv[]) {
    try {
        // Initialize Penguin2D
        PenguinInit();

        // Run the user-defined game logic
        int result = PenguinMain();

        // Cleanup Penguin2D
        PenguinQuit();
        return result;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;

        // Ensure cleanup in case of exceptions
        Penguin2D::PenguinQuit();
        return -1;
    }
}

#endif // PENGUIN_MAIN_HPP
