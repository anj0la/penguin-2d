#include "pong.hpp"

// Required function implementations from PenguinGame

void PongGame::init() {    
    // Set initial position of the players
    first_player.position = Vector2<float>(10.0, game_window.height / 2);
    second_player.position = Vector2<float>((float)game_window.width - 10.0, game_window.height / 2);

    // Set initial position of the ball, floor and ceiling
    pong_ball.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2);
    game_floor.position = Vector2<float>(0.0, (float) game_window.height - 10.0);
    game_ceiling.position = Vector2<float>(0.0, 0.0);
}

void PongGame::update(double delta_time) {
    // 1) Check for input and move players accordingly.
    move_first_player(delta_time); // moves with W & S keys
    move_second_player(delta_time); // moves with UP & DOWN keys
    
    // 2) Move the ball (TODO: Add physics to move ball at correct location)


    // 3) Check for collision with the ball and the following objects: the players, floor and ceiling

    // If the pong ball intersects with the first player, change the direction to move towards the second player
    // velocity.x increases, velocity.y can increase / decrease
    if (pong_ball.has_intersection(first_player)) {

    }

    // 2) Handle collision detection 
    // Need to make game_window.running = false;
}

void PongGame::draw(double alpha) {
    // Draw pong ball onto the screen
    game_window.renderer.draw_filled_rect(pong_ball, Colours::WHITE);

    // Draw middle line onto the screen
    game_window.renderer.draw_line(Vector2<float>(10.0, 0.0), Vector2<float>(10.0, game_window.height), Colours::WHITE);
    
    // Draw the players onto the screen
    game_window.renderer.draw_filled_rect(first_player, Colours::WHITE);
    game_window.renderer.draw_filled_rect(second_player, Colours::WHITE);

    // TODO: Add your own draw logic.
}

void PongGame::quit() {
    // TODO: Add your own quit logic.
}

// Private functions used for the Pong game to work

void PongGame::move_first_player(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::KEY_W)) {
        first_player.position -= velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (first_player.position < Vector2<float>(0.0, 100.0)) {
            first_player.position = Vector2<float>(0.0, 100.0);
        }

    }
    if (game_window.input.is_key_pressed(PenguinKey::KEY_S)) {
        first_player.position += velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (first_player.position > Vector2<float>(0.0, (float)game_window.height - 100.0)) {
            first_player.position = Vector2<float>(0.0, (float)game_window.height - 100.0);
        }
    }
}

void PongGame::move_second_player(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::UP)) {
        second_player.position -= velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (second_player.position < Vector2<float>(0.0, 100.0)) {
            second_player.position = Vector2<float>(0.0, 100.0);
        }

    }
    if (game_window.input.is_key_pressed(PenguinKey::DOWN)) {
        second_player.position += velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (second_player.position > Vector2<float>(0.0, (float)game_window.height - 100.0)) {
            second_player.position = Vector2<float>(0.0, (float)game_window.height - 100.0);
        }
    }
}

void PongGame::move_pong_ball(float delta_time) {
    Vector2<float> ball_velocity(50.0, 0.0); // Also need to store ball direction
}