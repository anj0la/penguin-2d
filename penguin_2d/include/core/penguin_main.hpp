///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_main.hpp                                                 ///
///                                                                             ///
/// Defines the entry point of Penguin2D. Implements the main function required ///
/// by SDL and handles initialization and cleanup of SDL libraries. It calls    ///
/// PenguinMain to execute game logic and handles exceptions during the process.///
/// Exception handling may be removed in future updates.                        ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_MAIN_HPP
#define PENGUIN_MAIN_HPP

// Penguin2D related include files
#include "penguin_init.hpp"

// SDL related include files
#include <SDL_main.h>

// C++ library files
#include <iostream>

using namespace Penguin2D;

/// The game's entry point.
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
