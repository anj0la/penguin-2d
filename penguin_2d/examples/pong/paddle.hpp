#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "penguin_input.hpp"
#include "rect2.hpp"

struct Paddle {
    Paddle() : paddle(Vector2<float>(10.0, 100.0)), velocity(Vector2<float>(0.0, 200.0)) {}
    ~Paddle() = default;

    Rect2<float> paddle;
    Vector2<float> velocity;
    int score = 0;

    //inline void move_paddle(float delta_time, PenguinInput& input, float height) {
    //    if (input.is_key_pressed(PenguinKey::UP)) {
    //        paddle.position -= velocity * delta_time;

    //        // Clipping player to the game window (avoiding going out of bounds)
    //        if (paddle.position.y < 0.0f) {
    //            paddle.position.y = 0.0f;
    //        }

    //    }
    //    if (input.is_key_pressed(PenguinKey::DOWN)) {
    //        paddle.position += velocity * delta_time;

    //        // Clipping player to the game window (avoiding going out of bounds)
    //        if (paddle.position.y > height - 100.0f) {
    //            paddle.position.y = height - 100.0f;
    //        }
    //    }
    //}


};

#endif // PADDLE_HPP