#include "pong.hpp"
#include <iostream>

//////////////////////////////////////////////////////////////
// Required function implementations from PenguinGame ////////
//////////////////////////////////////////////////////////////

void PongGame::init() {    
    // Set initial position of the players
    first_player.paddle.position = Vector2<float>(0.0f, game_window.height / 2 - 50.0f);
    second_player.paddle.position = Vector2<float>(game_window.width - 10.0f, game_window.height / 2 - 50.0f);

    // Set initial position of the ball, floor and ceiling
    pong_ball.ball_rect.position = Vector2<float>(game_window.width / 2, game_window.height / 2);
    game_floor.position = Vector2<float>(0.0f, game_window.height - 10.0f);
    game_ceiling.position = Vector2<float>(0.0f, 0.0f);

    // Set the initial scores of the two players
    score_first_player.set_text_string(std::to_string(0));
    score_first_player.font.set_font_size(64.0f);

    score_second_player.set_text_string(std::to_string(0));
    score_second_player.font.set_font_size(64.0f);
}

void PongGame::update(double delta_time) {

    if (first_player.score < 11 && second_player.score < 11) {
        // Move the ball.
        move_pong_ball(delta_time);

        // Check for collision with the ball.
        handle_collision();

        // Check if the ball went out of bounds, and increment the score.
        handle_out_of_bounds();

        // Check for input and move players accordingly.
        move_first_player(delta_time); // moves with W & S keys
        move_second_player(delta_time); // moves with UP & DOWN keys
    }
    else { // Check for input to close the game window.
        if (close_game()) {
            game_window.stop_game();
        }
    }
}

void PongGame::draw(double alpha) {
    // Draw pong ball onto the screen
    game_window.renderer.draw_filled_rect(pong_ball.ball_rect, Colours::WHITE);

    // Draw floor and ceiling to the screen
    game_window.renderer.draw_filled_rect(game_floor, Colours::WHITE);
    game_window.renderer.draw_filled_rect(game_ceiling, Colours::WHITE);

    // Draw middle line onto the screen
    game_window.renderer.draw_line(Vector2<float>((float)game_window.width / 2 + 4.0f, 0.0f), Vector2<float>((float)game_window.width / 2 + 4.0f, (float) game_window.height), Colours::WHITE);
    
    // Draw the players onto the screen
    game_window.renderer.draw_filled_rect(first_player.paddle, Colours::WHITE);
    game_window.renderer.draw_filled_rect(second_player.paddle, Colours::WHITE);

    // Draw player scores
    score_first_player.render_text(Vector2<float>(game_window.width / 4 - 10.0f, 20.0f));
    score_second_player.render_text(Vector2<float>(game_window.width / 1.5 + 40.0f, 20.0f));

    // Draw the game over text if the game is over
    if (first_player.score == 11 || second_player.score == 11) {
        game_over_text.render_text(Vector2<float>(game_window.width / 9, game_window.height / 2.75));
    }
}

void PongGame::quit() {}

//////////////////////////////////////////////////////////////
// Private function implementations for PongGame /////////////
//////////////////////////////////////////////////////////////

void PongGame::move_first_player(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::KEY_W)) {
        first_player.paddle.position -= first_player.velocity * delta_time;

        // Clip first player to the game window (avoiding going out of bounds)
        if (first_player.paddle.position.y < 0.0f) {
            first_player.paddle.position.y = 0.0f;
        }

    }
    if (game_window.input.is_key_pressed(PenguinKey::KEY_S)) {
        first_player.paddle.position += first_player.velocity * delta_time;

        // Clip second player to the game window (avoiding going out of bounds)
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
    pong_ball.ball_rect.position.x += pong_ball.velocity.x * delta_time;
    pong_ball.ball_rect.position.y += pong_ball.velocity.y * delta_time;
}

void PongGame::handle_collision() {
    if (pong_ball.ball_rect.has_intersection(first_player.paddle)) {
        handle_paddle_collision(first_player.paddle, true);
    }
    else if (pong_ball.ball_rect.has_intersection(second_player.paddle)) {
        handle_paddle_collision(second_player.paddle, false);
    }
    else if (pong_ball.ball_rect.has_intersection(game_floor)) {
        handle_wall_collision();
    }
    else if (pong_ball.ball_rect.has_intersection(game_ceiling)) {
        handle_wall_collision();
    }
}

void PongGame::handle_paddle_collision(Rect2<float>& paddle_rect, bool is_first_player) {
    float paddle_center_y = paddle_rect.position.y + (paddle_rect.size.y / 2);
    float ball_center_y = pong_ball.ball_rect.position.y + (pong_ball.ball_rect.size.y / 2);

    // Calculate the relative intersection
    float relative_intersect_y = ball_center_y - paddle_center_y;

    // Normalize the intersection (ranges between -1.0 and 1.0)
    float normalized_intersect = relative_intersect_y / (paddle_rect.size.y / 2);

    // Calculate the bounce angle
    float max_bounce_angle = std::numbers::pi / 3.0f; // 60 degrees
    float bounce_angle = normalized_intersect * max_bounce_angle;

    // Set the new velocity
    pong_ball.velocity.x = pong_ball.BALL_SPEED * cos(bounce_angle);
    pong_ball.velocity.y = pong_ball.BALL_SPEED * sin(bounce_angle);

    // Ensure the ball moves away from the paddle
    if (is_first_player) { // Left paddle
        pong_ball.velocity.x = std::abs(pong_ball.velocity.x);
    }
    else { // Right paddle
        pong_ball.velocity.x = -std::abs(pong_ball.velocity.x); 
    }
}


void PongGame::handle_wall_collision() {
    pong_ball.velocity.y *= -1.0f;
}

void PongGame::handle_out_of_bounds() {
    // Pong ball goes out of the screen on the left-hand side
    if (pong_ball.ball_rect.position.x < 0.0) {
        // Give player 2 a point
        second_player.score++;
        score_second_player.set_text_string(std::to_string(second_player.score));

        // Reset ball back to the middle of ths screen
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); 
        reset_ball_velocity(false); // ball moves towards player 1
    }
    // Pong ball goes out of the screen on the right-hand side
    else if (pong_ball.ball_rect.position.x > game_window.width) {
        // Give player 1 a point
        first_player.score++;
        score_first_player.set_text_string(std::to_string(first_player.score));

        // Reset ball back to the middle of ths screen
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2, (float)game_window.height / 2); 
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

bool PongGame::close_game() {
    if (game_window.input.is_any_key_pressed()) {
        return true;
    }
    return false;
}
