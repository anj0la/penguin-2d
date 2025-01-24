#include "main.hpp"

int PenguinMain() {

    // Create the game window
    PenguinGameWindow game_window("Render Shapes Example", Vector2<int>(800, 800));

    // Create the game and connect it to the game window
    auto my_game = std::make_unique<MyGame>(game_window); // connect_game() expects a unique instance of the game
    game_window.connect_game(std::move(my_game));

    // Run the game
    game_window.run();

    return 0;
}