#ifndef PENGUIN_SDL_MANAGER
#define PENGUIN_SDL_MANAGER

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Penguin2D {

    class PenguinSDLManager {
    public:
        PenguinSDLManager() {

            Exception::throw_if(
                    !SDL_Init(SDL_INIT_VIDEO),
                    "Failed to initialize SDL3.",
                    INIT_ERROR
            );

            Exception::throw_if(
                !TTF_Init(),
                "Failed to initialize SDL_TTF.",
                INIT_ERROR
            );
        }

        ~PenguinSDLManager() {
            TTF_Quit();
            SDL_Quit();
        }

        // Prevent copying and assignment
        PenguinSDLManager(const PenguinSDLManager&) = delete;
        PenguinSDLManager& operator=(const PenguinSDLManager&) = delete;
    };

}
#endif // PENGUIN_SDL_MANAGER