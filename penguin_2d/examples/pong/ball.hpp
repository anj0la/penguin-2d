#ifndef BALL_HPP
#define BALL_HPP

#include "rect2.hpp"

struct Ball {
    Ball() : ball_rect(Vector2<float>(10.0f, 10.0f)), velocity(0.0f, 0.0f) {}
    ~Ball() = default;

    Rect2<float> ball_rect; 
    Vector2<float> velocity;
    const float BALL_SPEED = 10.0f;
};

#endif // BALL_HPP