///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_init.hpp                                                 ///
///                                                                             ///
/// Defines functions for initializing and quitting Penguin2D and its required  ///
/// libraries. These functions are used internally in penguin_main.hpp to       ///
/// initialize SDL and SDL_TTF. Custom initialization logic can be added in     ///
/// penguin_main.hpp.                                                           ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_INIT_HPP
#define PENGUIN_INIT_HPP

// Penguin2D related include files
#include "exception.hpp"

// SDL related include files
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace Penguin2D {
    
    /// @brief Initializes Penguin2D and its required libraries (SDL3 and SDL_TTF).
    /// 
    /// This function initializes the SDL3 video subsystem and the SDL_TTF library,
    /// both essential for the proper functioning of Penguin2D. If any initialization 
    /// step fails, an exception is thrown with an appropriate error message.
    /// 
    /// @throws std::exception If SDL_Init or TTF_Init fails, an exception is thrown
    ///         with a message indicating which library failed to initialize.
    /// 
    /// @note This function should be called before using any other Penguin2D features.
    ///       It should only be called once, typically at the start of the application.
    inline void PenguinInit() {

        Exception::throw_if(
            !SDL_Init(SDL_INIT_VIDEO),
            "Failed to initialize SDL3: " + std::string(SDL_GetError()),
            INIT_ERROR
        );

        Exception::throw_if(
            !TTF_Init(),
            "Failed to initialize SDL_TTF: " + std::string(SDL_GetError()),
            INIT_ERROR
        );
    }

    /// @brief Cleans up all resources used by Penguin2D and its libraries (SDL3 and SDL_TTF).
    /// 
    /// This function shuts down the SDL_TTF library and SDL3, releasing any resources 
    /// acquired during the initialization process. It is called to perform cleanup 
    /// operations before the application exits.
    /// 
    /// @note This function should be called once, typically at the end of the application,
    ///       to ensure that all resources are properly freed.
    inline void PenguinQuit() {
        TTF_Quit();
        SDL_Quit();
    }
}
#endif // PENGUIN_INIT_HPP
