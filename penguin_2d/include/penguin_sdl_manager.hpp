#ifndef PENGUIN_SDL_MANAGER
#define PENGUIN_SDL_MANAGER

#include <SDL3/SDL.h>

namespace Penguin2D {

    class PenguinSDLManager {
    public:
        PenguinSDLManager() {

            Exception::throw_if(
                    !SDL_Init(SDL_INIT_VIDEO),
                    "Could not initialize SDL3.",
                    INIT_ERROR
            );
        }

        ~PenguinSDLManager() {
            SDL_Quit();
        }

        // Prevent copying and assignment
        PenguinSDLManager(const PenguinSDLManager&) = delete;
        PenguinSDLManager& operator=(const PenguinSDLManager&) = delete;
    };

}
#endif // PENGUIN_SDL_MANAGER