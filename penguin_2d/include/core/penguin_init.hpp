/// File name: penguin_init.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinInit is used to initialize Penguin2D and the libraries it depends on.
/// 
/// The defined functions are only used internally, in penguin_main.hpp to initialize SDL, and SDL_TTF, which are required for the library to function.
/// This file is not to be changed, adding custom initialization logic can be done in penguin_main.hpp.
/// 

#ifndef PENGUIN_INIT_HPP
#define PENGUIN_INIT_HPP

// Penguin2D related include files
#include "exception.hpp"

// SDL related include files
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace Penguin2D {
    
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

    inline void PenguinQuit() {
        TTF_Quit();
        SDL_Quit();
    }

}
#endif // PENGUIN_INIT_HPP
