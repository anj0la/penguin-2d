#include "pong.hpp"

void PongGame::init() {    
    // Set initial position of the players
    first_player.position = Vector2<float>(10.0, game_window.height / 2);
    second_player.position = Vector2<float>((float)game_window.width - 10.0, game_window.height / 2);
}

void PongGame::update(double delta_time) {
    // Player 1 uses W and S to move up and down
    // Player 2 uses UP and DOWN arrow keys to move up and down


    // Steps
    // 1) Check for input and move accordingly

    // 2) Handle collision detection 
    // Need to make game_window.running = false;
}

void PongGame::draw(double alpha) {
    // game_window.renderer.draw_filled_rect(rect, Colours::WHITE);
    
    // Draw the players onto the screen
    game_window.renderer.draw_filled_rect(first_player, Colours::WHITE);
    game_window.renderer.draw_filled_rect(second_player, Colours::WHITE);

    // TODO: Add your own draw logic.
}

void PongGame::quit() {
    // TODO: Add your own quit logic.
}