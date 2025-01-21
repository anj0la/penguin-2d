#ifndef PENGUIN_MAIN_HPP
#define PENGUIN_MAIN_HPP

#include <SDL3/SDL_main.h>

// The game's entry point
extern int PenguinMain(int argc, char* argv[]);

// SDL requires a main function
int main(int argc, char* argv[]) {
    return PenguinMain(argc, argv);
}

#endif // PENGUIN_MAIN_HPP
