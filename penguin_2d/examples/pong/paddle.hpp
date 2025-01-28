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

};

#endif // PADDLE_HPP