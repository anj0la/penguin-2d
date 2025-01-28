#ifndef BALL_HPP
#define BALL_HPP

#include "rect2.hpp"

struct Ball {
    Ball() : ball_rect(Vector2<float>(10.0f, 10.0f)), velocity(200.0f, 150.0f) {}
    ~Ball() = default;

    Rect2<float> ball_rect; 
    Vector2<float> velocity;
    const float BALL_SPEED = 200.0f;

    //inline void move_pong_ball(float delta_time) {
    //    ball_rect.position.x += velocity.x * delta_time;
    //    ball_rect.position.y += velocity.y * delta_time;
    //}
};

#endif // BALL_HPP