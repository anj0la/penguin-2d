#ifndef PENGUIN_MAIN_HPP
#define PENGUIN_MAIN_HPP

#include <SDL3/SDL_main.h>

// The game's entry point
extern int PenguinMain();

// SDL requires a main function
int main(int argc, char* argv[]) {
    return PenguinMain();
}

#endif // PENGUIN_MAIN_HPP
