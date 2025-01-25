#ifndef PENGUIN_INIT_HPP
#define PENGUIN_INIT_HPP

#include "exception.hpp"

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
