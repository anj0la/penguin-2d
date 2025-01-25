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

    // 2) Check for collision with the ball and the following objects: the players, floor and ceiling
    handle_collision(delta_time);

    // 3) Check if the ball went out of bounds, and increment the score
    handle_out_of_bounds();

    // 4) Check to see if any player has reached the required score

    // 5) Move the ball
    move_pong_ball(delta_time);
}

void PongGame::draw(double alpha) {
    // Draw pong ball onto the screen
    game_window.renderer.draw_filled_rect(pong_ball, Colours::WHITE);

    // Draw floor and ceiling to the screen
    game_window.renderer.draw_filled_rect(game_floor, Colours::WHITE);
    game_window.renderer.draw_filled_rect(game_ceiling, Colours::WHITE);

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

// Private functions used for the Pong game to work (can be moved into own separate file, aka pong_logic.cpp)

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

void PongGame::handle_collision(float delta_time) {
    // If the pong ball intersects with the first player, change the direction to move towards the second player
// velocity.x increases, velocity.y can increase / decrease
    if (pong_ball.has_intersection(first_player)) {
        // Change direction of the ball

        // Set velocity via formula
    }
    else if (pong_ball.has_intersection(second_player)) {

    }
    else if (pong_ball.has_intersection(game_floor)) {

    }
    else if (pong_ball.has_intersection(game_ceiling)) {

    }
}

void PongGame::handle_out_of_bounds() {
    // Pong ball goes out of the screen on the left-hand side
    if (pong_ball.position.x < 0.0) {
        // Give player 2 a point (need to abstract into their own classes tbh)
        // second_player.point++;
        pong_ball.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); // reset back to middle of screen
    }
    // Pong ball goes out of the screen on the right-hand side
    else if (pong_ball.position.x > game_window.width) {
        // Give player 1 a point
        // first_player.point++;
        pong_ball.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); // reset back to middle of screen
    }
}