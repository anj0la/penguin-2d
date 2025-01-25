#ifndef PONG_HPP
#define PONG_HPP

#include "penguin_game_window.hpp"
#include "rect2.hpp"

using namespace Penguin2D;

class PongGame : public PenguinGame {
public:
    PongGame(PenguinGameWindow& window) : 
        game_window(window), 
        first_player(Vector2<float>(10.0, 100.0)), 
        second_player(Vector2<float>(10.0, 100.0)), 
        velocity(Vector2<float>(0.0, 200.0)), 
        pong_ball(Vector2<float>(10.0, 10.0)),
        game_floor(Vector2<float>((float) game_window.width, 10.0)),
        game_ceiling(Vector2<float>((float)game_window.width, 10.0)) {}
    ~PongGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
    void quit() override;
private:
    PenguinGameWindow& game_window;
    Rect2<float> first_player;
    Rect2<float> second_player;
    Vector2<float> velocity;
    Rect2<float> pong_ball;
    Rect2<float> game_floor;
    Rect2<float> game_ceiling;

    void move_first_player(float delta_time);
    void move_second_player(float delta_time);
    void move_pong_ball(float delta_time);
    void handle_collision(float delta_time);
    void handle_out_of_bounds();
};

#endif // PONG_HPP