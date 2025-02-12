///////////////////////////////////////////////////////////////////////////////////
/// File name: pong.cpp                                                         ///
///                                                                             ///
/// Implementation of the PongGame class, handling game initialization,         ///
/// updates, rendering, and player interactions. Supports both single-player    ///
/// (AI opponent) and two-player modes. Includes collision detection, scoring,  ///
/// and input handling.                                                         ///
///////////////////////////////////////////////////////////////////////////////////

#include "pong.hpp"

/////////////////////////////////////////////////////////////
///     Function implementations from PenguinBaseGame     ///
/////////////////////////////////////////////////////////////

/// @brief Initializes the Pong game by setting up player positions, ball, floor, ceiling, and initial scores.
void PongGame::init() { 
    // Set initial position of the players
    first_player.paddle.position = Vector2<float>(0.0f, game_window.height / 2 - 50.0f);
    second_player.paddle.position = Vector2<float>(game_window.width - 10.0f, game_window.height / 2 - 50.0f);

    // Set initial position of the ball, floor and ceiling
    pong_ball.ball_rect.position = Vector2<float>(game_window.width / 2.0f, game_window.height / 2.0f);
    game_floor.position = Vector2<float>(0.0f, game_window.height - 10.0f);
    game_ceiling.position = Vector2<float>(0.0f, 0.0f);

    // Set the initial points of the two players
    points_first_player.set_text_string(std::to_string(0));
    points_first_player.font.set_font_size(64.0f);
    points_second_player.set_text_string(std::to_string(0));
    points_second_player.font.set_font_size(64.0f);

    // Randomize the pong ball's direction and velocity
    reset_ball_velocity(true);
}

/// @brief Updates the game state, handling input, scoring, and game logic.
/// @param delta_time: Time elapsed since the last update.
void PongGame::update(double delta_time) {
    if (!is_playing) {
        update_title_screen();
    }
    else {
        // Wait for any input to close the game if score reached
        if (first_player.points == GOAL_POINTS || second_player.points == GOAL_POINTS) {
            if (close_game()) {
                game_window.close_window();
            }
        }
        // Handle logic for two player and one player modes separately
        else {
            move_pong_ball(delta_time);
            handle_collision();
            handle_out_of_bounds();
            move_left_paddle(delta_time); // Moves with W & S keys
            // Two player mode
            if (is_two_player) {
                move_right_paddle(delta_time); // Moves with up & down keys
            }
            else {
                move_right_paddle_ai(delta_time);
            }
        }
    }
}

/// @brief Draws the game objects onto the screen, including paddles, ball floor, ceiling, and score text.
/// @param alpha: Interpolation factor for smooth rendering (experimental).
void PongGame::draw(double alpha) {
    if (!is_playing) {
        display_title_screen();
    }
    else {
        // Clear renderer for drawing.
        game_window.renderer.clear();

        // Draw pong ball onto the screen
        game_window.renderer.draw_filled_rect(pong_ball.ball_rect, Colours::WHITE);

        // Draw floor and ceiling to the screen
        game_window.renderer.draw_filled_rect(game_floor, Colours::WHITE);
        game_window.renderer.draw_filled_rect(game_ceiling, Colours::WHITE);

        // Draw middle line onto the screen
        game_window.renderer.draw_line(Vector2<float>((float)game_window.width / 2.0f + 4.0f, 0.0f), Vector2<float>((float)game_window.width / 2.0f + 4.0f, (float)game_window.height), Colours::WHITE);

        // Draw the players onto the screen
        game_window.renderer.draw_filled_rect(first_player.paddle, Colours::WHITE);
        game_window.renderer.draw_filled_rect(second_player.paddle, Colours::WHITE);

        // Draw player scores
        points_first_player.draw_text(Vector2<float>(game_window.width / 4.0f - 10.0f, 20.0f));
        points_second_player.draw_text(Vector2<float>(game_window.width / 1.5f + 40.0f, 20.0f));

        // Draw the game over text if the game is over
        if (first_player.points == GOAL_POINTS || second_player.points == GOAL_POINTS) {
            game_over_text.draw_text(Vector2<float>(game_window.width / 9.0f, game_window.height / 2.75f));
        }

        // Display objects drawn onto renderer.
        game_window.renderer.present();
    }
}

/////////////////////////////////////////////////////////////
///     Function implementations from PongGame            ///
/////////////////////////////////////////////////////////////

/// @brief Handles the title screen logic, switching between single-player and two-player mode selection.
void PongGame::update_title_screen() {
    if (game_window.input.is_key_pressed(PenguinKey::KEY_W) || game_window.input.is_key_pressed(PenguinKey::UP)) {
        is_two_player = false;
        one_player_text.font.set_font_size(48.0f);
        two_player_text.font.set_font_size(32.0f);
    }
    if (game_window.input.is_key_pressed(PenguinKey::KEY_S) || game_window.input.is_key_pressed(PenguinKey::DOWN)) {
        is_two_player = true;
        one_player_text.font.set_font_size(32.0f);
        two_player_text.font.set_font_size(48.0f);
    }
    if (game_window.input.is_key_pressed(PenguinKey::ENTER)) {
        is_playing = true;
    }
}

/// @brief Displays the title screen with the game title and mode selection options.
void PongGame::display_title_screen() {
    // Draw updated text to the screen
    game_window.renderer.clear();
    pong_game_title.draw_text(Vector2<float>(game_window.width / 8.0f, 40.0f));
    enter_text.draw_text(Vector2<float>(game_window.width / 5.0f, game_window.height - 40.0f));

    if (is_two_player) {
        one_player_text.draw_text(Vector2<float>(game_window.width / 2.75f, game_window.height / 2.25f));
        two_player_text.draw_text(Vector2<float>(game_window.width / 3.50f, game_window.height / 1.80f));
    }
    // Play against simple AI player
    else {
        one_player_text.draw_text(Vector2<float>(game_window.width / 3.25f, game_window.height / 2.25f));
        two_player_text.draw_text(Vector2<float>(game_window.width / 2.75f, game_window.height / 1.65f));
    }
    game_window.renderer.present();
}

/// @brief Moves the left paddle based on player input, ensuring it stays within game bounds.
/// @param delta_time: Time elapsed since the last update.
void PongGame::move_left_paddle(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::KEY_W)) {
        first_player.paddle.position -= first_player.velocity * delta_time;
    }
    if (game_window.input.is_key_pressed(PenguinKey::KEY_S)) {
        first_player.paddle.position += first_player.velocity * delta_time;
    }
    // Check for movement with up & down arrow keys if playing against AI
    if (!is_two_player) {
        if (game_window.input.is_key_pressed(PenguinKey::UP)) {
            first_player.paddle.position -= first_player.velocity * delta_time;
        }
        if (game_window.input.is_key_pressed(PenguinKey::DOWN)) {
            first_player.paddle.position += first_player.velocity * delta_time;
        }
    }
    // Ensure player stays out of bounds
    first_player.paddle.position.y = std::max(0.0f, std::min(first_player.paddle.position.y, (float)game_window.height - first_player.paddle.size.y));
}

/// @brief Moves the AI-controlled right paddle to track the ball's position.
/// @param delta_time: Time elapsed since the last update.
void PongGame::move_right_paddle_ai(float delta_time) {
    // Ball is moving towards the AI paddle (right paddle)
    if (pong_ball.velocity.x > 0) {

        float ai_center = second_player.paddle.position.y + (second_player.paddle.size.y / 2);
        float ball_center = pong_ball.ball_rect.position.y + (pong_ball.ball_rect.size.y / 2);

        // Ball is above the AI paddle, move it up
        if (ball_center < ai_center && std::abs(ball_center - ai_center) > MIN_DIFF) {
            second_player.paddle.position -= second_player.velocity * delta_time;
        }
        // Ball is below the AI paddle, move it down
        else if (ball_center > ai_center && std::abs(ball_center - ai_center) > MIN_DIFF) {
            second_player.paddle.position += second_player.velocity * delta_time;
        }

        // Ensure AI paddle stays within game bounds
        second_player.paddle.position.y = std::max(0.0f,
            std::min(second_player.paddle.position.y,
                (float)game_window.height - second_player.paddle.size.y));
    }
}
/// @brief Moves the right paddle based on player input in two-player mode.
/// @param delta_time: Time elapsed since the last update.
void PongGame::move_right_paddle(float delta_time) {
    if (game_window.input.is_key_pressed(PenguinKey::UP)) {
        second_player.paddle.position -= second_player.velocity * delta_time;
    }
    if (game_window.input.is_key_pressed(PenguinKey::DOWN)) {
        second_player.paddle.position += second_player.velocity * delta_time;
    }
    // Ensure player stays out of bounds
    second_player.paddle.position.y = std::max(0.0f, std::min(second_player.paddle.position.y, (float)game_window.height - second_player.paddle.size.y));
}

/// @brief Moves the Pong ball according to its velocity.
/// @param delta_time: Time elapsed since the last update.
void PongGame::move_pong_ball(float delta_time) {
    pong_ball.ball_rect.position += pong_ball.velocity * delta_time;
}

/// @brief Handles collisions between the ball and paddles or walls.
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

/// @brief Adjusts the ball's velocity based on paddle collision.
void PongGame::handle_paddle_collision(Rect2<float>& paddle_rect, bool is_first_player) {
    float paddle_center_y = paddle_rect.position.y + (paddle_rect.size.y / 2.0f);
    float ball_center_y = pong_ball.ball_rect.position.y + (pong_ball.ball_rect.size.y / 2.0f);

    float relative_intersect_y = ball_center_y - paddle_center_y;
    float normalized_intersect = relative_intersect_y / (paddle_rect.size.y / 2.0f);
    float max_bounce_angle = std::numbers::pi / 3.0f; // 60 degrees
    float bounce_angle = normalized_intersect * max_bounce_angle;

    pong_ball.velocity.x = pong_ball.BALL_SPEED * cos(bounce_angle);
    pong_ball.velocity.y = pong_ball.BALL_SPEED * sin(bounce_angle);
    pong_ball.velocity.x = is_first_player ? std::abs(pong_ball.velocity.x) : -std::abs(pong_ball.velocity.x); // Ensures the ball moves away from the paddle
}

/// @brief Reverses the ball's vertical velocity when it hits a wall.
void PongGame::handle_wall_collision() {
    pong_ball.velocity.y *= -1.0f;
}

/// @brief Handles when the ball goes out of bounds, updates scores, and resets the ball.
void PongGame::handle_out_of_bounds() {
    // Pong ball goes out of the screen on the left-hand side
    if (pong_ball.ball_rect.position.x < 0.0f) {
        second_player.points++;
        points_second_player.set_text_string(std::to_string(second_player.points));

        // Reset ball back to the middle of the screen
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2.0f, (float)game_window.height / 2.0f); 
        reset_ball_velocity(false); // Ball moves towards player 1
    }
    // Pong ball goes out of the screen on the right-hand side
    else if (pong_ball.ball_rect.position.x > game_window.width) {
        first_player.points++;
        points_first_player.set_text_string(std::to_string(first_player.points));

        // Reset ball back to the middle of the screen
        pong_ball.ball_rect.position = Vector2<float>((float)game_window.width / 2.0f, (float)game_window.height / 2.0f); 
        reset_ball_velocity(true); // Ball moves towards player 2
    }
}

/// @brief Resets the ball's velocity and direction after a point is scored.
/// @param to_second_player: If true, the ball moves toward the second player (right side), otherwise, it moves toward the first player (left side).
void PongGame::reset_ball_velocity(bool to_second_player) {
    float angle = (float)rand() / RAND_MAX * std::numbers::pi / 3.0f - std::numbers::pi / 6.0f; // Random angle between -30 and +30 degrees
    float speed = pong_ball.BALL_SPEED / 1.5f; // Slows down the game

    // Determine direction based on scoring side
    pong_ball.velocity.x = to_second_player ? speed * cos(angle) : -speed * cos(angle);
    pong_ball.velocity.y = speed * sin(angle);
}

/// @brief Checks if the game should be closed based on user input.
/// @return bool: True if any key is pressed, false otherwise.
bool PongGame::close_game() {
    if (game_window.input.is_any_key_pressed()) {
        return true;
    }
    return false;
}
