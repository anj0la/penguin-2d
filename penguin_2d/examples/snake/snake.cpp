#include "snake.hpp"

void SnakeGame::init() {
	// Set initial position of the snake
	Rect2<float> snake_head(game_window.width / 2, game_window.height / 2, 25.0f, 25.0f);
	snake.push_front(snake_head);

    // Set initial position of the food
    spawn_food(food);

    // Set seed for random generation
    std::srand(std::time(nullptr));
}

void SnakeGame::update(double delta_time) {
    move_snake(delta_time);

    //if (check_wall_collision() || check_snake_collision()) {
    //    close_game();
    //}

    check_food_collision(food);
}

void SnakeGame::draw(double alpha) {
	// Draw the snake onto the screen
    for (size_t i = 0; i < snake.size(); i++) {
        game_window.renderer.draw_filled_rect(snake[i], Colours::GREEN);
    }

    // Draw the food
    game_window.renderer.draw_filled_rect(food, Colours::RED);
}

void SnakeGame::move_snake(float delta_time) {
    // Move the snake up (negative y dir)
    if (game_window.input.is_key_pressed(PenguinKey::UP) || game_window.input.is_key_pressed(PenguinKey::KEY_W)) {
        velocity.y -= 100.0f * delta_time;
    }
    // Move the snake down (positive y dir)
    if (game_window.input.is_key_pressed(PenguinKey::DOWN) || game_window.input.is_key_pressed(PenguinKey::KEY_S)) {
        velocity.y += 100.0f * delta_time;
    }
    // Move the snake left (negative x dir)
    if (game_window.input.is_key_pressed(PenguinKey::LEFT) || game_window.input.is_key_pressed(PenguinKey::KEY_A)) {
        velocity.x -= 100.0f * delta_time;
    }
    // Move the snake right (positive x dir)
    if (game_window.input.is_key_pressed(PenguinKey::RIGHT) || game_window.input.is_key_pressed(PenguinKey::KEY_D)) {
        velocity.x += 100.0f * delta_time;
    }

    // Add new head to snake
    Rect2<float> new_head(velocity, Vector2<float>(25.0f, 25.0f));
    snake.push_front(new_head);
    if (!growing) {
        snake.pop_back();
    }
}

bool SnakeGame::check_wall_collision() {
    Rect2<float> head = snake.front();
    return (head.position.x < 0 || head.position.y < 0 || head.position.x >= game_window.width || head.position.y >= game_window.height);
}

bool SnakeGame::check_snake_collision() {
    Rect2<float> head = snake.front();
    for (size_t i = 1; i < snake.size(); i++) {
        if (head.has_intersection(snake[i])) {
            return true;  // Collision with itself
        }
        //if (head.position.x == snake[i].position.x && head.position.y == snake[i].position.y) {
        //    return true;  // Collision with itself
        //}
    }
    return false;
}

void SnakeGame::check_food_collision(Rect2<float>& food) {
    if (snake.front().has_intersection(food)) {
        growing = true; // Allow snake to grow
        spawn_food(food); // New food location
    }
    /*if (snake.front().position.x == food.position.x && snake.front().position.y == food.position.y) {
        
    }*/
}

void SnakeGame::spawn_food(Rect2<float>& food) {
    do {
        food.position.x = rand() % game_window.width;
        food.position.y = rand() % game_window.height;
    } while (is_food_on_snake(food)); // Ensure food is not inside the snake
}

bool SnakeGame::is_food_on_snake(Rect2<float>& food) {
    for (const auto& part : snake) {
        if (part.has_intersection(food)) {
            return true;// Food is inside snake, retry
        }
    }
    return false;
}

void SnakeGame::close_game() {
    while (!game_window.input.is_any_key_pressed()) {} // Waiting for any input to close the game.
    game_window.stop_game();
}