/// File name: penguin_main.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinMain defines the entry point of the Penguin2D.
/// 
/// The file implements a main function required by SDL, calling the required main function PenguinMain to execute game logic. It handles exceptions 
/// in case any SDL library has not been initialized correctly. It also handles at a very high level, exceptions that may occur in PenguinMain. Note that
/// this may not be the case in the future, and that exception handling may be removed in a future update.
/// 

#ifndef PENGUIN_MAIN_HPP
#define PENGUIN_MAIN_HPP

// Penguin2D related include files
#include "penguin_init.hpp"

// SDL related include files
#include <SDL3/SDL_main.h>

// C++ library files
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
        PenguinQuit();
        return -1;
    }
}

#endif // PENGUIN_MAIN_HPP
