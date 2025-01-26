#include "pong.hpp"

// Required function implementations from PenguinGame

void PongGame::init() {    
    // Set initial position of the players
    first_player.paddle.position = Vector2<float>(0.0f, game_window.height / 2);
    second_player.paddle.position = Vector2<float>(game_window.width - 10.0f, game_window.height / 2);

    // Set initial position of the ball, floor and ceiling
    pong_ball.ball_rect.position = Vector2<float>(game_window.width / 2, game_window.height / 2);
    game_floor.position = Vector2<float>(0.0f, game_window.height - 10.0f);
    game_ceiling.position = Vector2<float>(0.0f, 0.0f);
}

void PongGame::update(double delta_time) {
    // 1) Move the ball
    // move_pong_ball(delta_time);

    // 2) Check for collision with the ball and the following objects: the players, floor and ceiling
    handle_collision();

    // 3) Check if the ball went out of bounds, and increment the score
    handle_out_of_bounds();

    // 4) Check for input and move players accordingly
    move_first_player(delta_time); // moves with W & S keys
    move_second_player(delta_time); // moves with UP & DOWN keys
}

void PongGame::draw(double alpha) {
    // Draw pong ball onto the screen
    game_window.renderer.draw_filled_rect(pong_ball.ball_rect, Colours::WHITE);

    // Draw floor and ceiling to the screen
    game_window.renderer.draw_filled_rect(game_floor, Colours::WHITE);
    game_window.renderer.draw_filled_rect(game_ceiling, Colours::WHITE);

    // Draw middle line onto the screen
    game_window.renderer.draw_line(Vector2<float>((float)game_window.width / 2 + 4.0f, 0.0), Vector2<float>((float)game_window.width / 2 + 4.0f, (float) game_window.height), Colours::WHITE);
    
    // Draw the players onto the screen
    game_window.renderer.draw_filled_rect(first_player.paddle, Colours::WHITE);
    game_window.renderer.draw_filled_rect(second_player.paddle, Colours::WHITE);

    // TODO: Add your own draw logic.
}

void PongGame::quit() {
    // TODO: Add your own quit logic.
}

// Private functions used for the Pong game to work (can be moved into own separate file, aka pong_logic.cpp)

void PongGame::move_first_player(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::KEY_W)) {
        first_player.paddle.position -= first_player.velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (first_player.paddle.position.y < 0.0f) {
            first_player.paddle.position.y = 0.0f;
        }

    }
    if (game_window.input.is_key_pressed(PenguinKey::KEY_S)) {
        first_player.paddle.position += first_player.velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (first_player.paddle.position.y > (float)game_window.height - 100.0f) {
            first_player.paddle.position.y = (float)game_window.height - 100.0f;;
        }
    }
}

void PongGame::move_second_player(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::UP)) {
        second_player.paddle.position -= second_player.velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (second_player.paddle.position.y < 0.0f) {
            second_player.paddle.position.y = 0.0f;
        }

    }
    if (game_window.input.is_key_pressed(PenguinKey::DOWN)) {
        second_player.paddle.position += second_player.velocity * delta_time;

        // Clipping player to the game window (avoiding going out of bounds)
        if (second_player.paddle.position.y > (float)game_window.height - 100.0f) {
            second_player.paddle.position.y = (float)game_window.height - 100.0f;
        }
    }
}

void PongGame::move_pong_ball(float delta_time) {
    pong_ball.ball_rect.position.x = pong_ball.velocity.x;
    pong_ball.ball_rect.position.y = pong_ball.velocity.y;
}

void PongGame::handle_collision() {
    // Handle collision with the first player paddle
    if (pong_ball.ball_rect.has_intersection(first_player.paddle)) {
        handle_paddle_collision(first_player.paddle, true);
    }
    // Handle collision with the second player paddle
    else if (pong_ball.ball_rect.has_intersection(second_player.paddle)) {
        handle_paddle_collision(second_player.paddle, false);
    }
    // Handle collision with the floor
    else if (pong_ball.ball_rect.has_intersection(game_floor)) {
        handle_wall_collision();
    }
    // Handle collision with the ceiling
    else if (pong_ball.ball_rect.has_intersection(game_ceiling)) {
        handle_wall_collision();
    }
}

void PongGame::handle_paddle_collision(Rect2<float>& paddle_rect, bool is_first_player) {
    float paddle_center_y = paddle_rect.position.y + (paddle_rect.size.y / 2);
    float ball_center_y = pong_ball.ball_rect.position.y + (pong_ball.ball_rect.size.y / 2);

    // Calculate the relative intersection
    float relative_intersect_y = paddle_center_y - ball_center_y;

    // Normalize the relative intersection
    float normalized_intersect = relative_intersect_y / (paddle_rect.size.y / 2);

    // Calculate the bounce angle (max bounce angle = 75 degrees in radians)
    float max_bounce_angle = std::numbers::pi / 2.4f; // 75 degrees
    float bounce_angle = normalized_intersect * max_bounce_angle;

    // Set the new velocity
    pong_ball.velocity.x = pong_ball.BALL_SPEED * cos(bounce_angle);
    pong_ball.velocity.y = pong_ball.BALL_SPEED * -sin(bounce_angle);

    // Ensure the ball moves away from the paddle
    if (is_first_player && pong_ball.velocity.x > 0) {
        pong_ball.velocity.x *= -1;
    }
    else if (!is_first_player && pong_ball.velocity.x < 0) {
        pong_ball.velocity.x *= -1;
    }
}

void PongGame::handle_wall_collision() {
    pong_ball.velocity.y *= 1.0f;
}

void PongGame::handle_out_of_bounds() {
    // Pong ball goes out of the screen on the left-hand side
    if (pong_ball.ball_rect.position.x < 0.0) {
        // Give player 2 a point
        second_player.score++;
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); // reset back to middle of screen
        reset_ball_velocity(false); // ball moves towards player 1
    }
    // Pong ball goes out of the screen on the right-hand side
    else if (pong_ball.ball_rect.position.x > game_window.width) {
        // Give player 1 a point
        first_player.score++;
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); // reset back to middle of screen
        reset_ball_velocity(true); // ball moves towards player 2
    }
}

void PongGame::reset_ball_velocity(bool to_second_player) {
    // Set a default angle and speed
    float angle = (float)rand() / RAND_MAX * std::numbers::pi / 3 - std::numbers::pi / 6; // random angle between -30 and +30 degrees
    float speed = pong_ball.BALL_SPEED;

    // Determine direction based on scoring side
    pong_ball.velocity.x = to_second_player ? speed * cos(angle) : -speed * cos(angle);
    pong_ball.velocity.y = speed * sin(angle);
}