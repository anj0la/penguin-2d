#ifndef PONG_HPP
#define PONG_HPP

#include "penguin_game_window.hpp"
#include "penguin_text.hpp"
#include "rect2.hpp"
#include "paddle.hpp"
#include "ball.hpp"

#include <numbers>

using namespace Penguin2D;

class PongGame : public PenguinGame {
public:
    PongGame(PenguinGameWindow& window) : 
        game_window(window), 
        game_floor(Vector2<float>((float) game_window.width, 10.0f)),
        game_ceiling(Vector2<float>((float)game_window.width, 10.0f)),
        score_first_player(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf"), 
        score_second_player(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf"),
        game_over_text(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "GAME OVER", 96.0f) { }
    ~PongGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
    void quit() override;
private:
    PenguinGameWindow& game_window;
    Paddle first_player;
    Paddle second_player;
    Ball pong_ball;
    Rect2<float> game_floor;
    Rect2<float> game_ceiling;
    PenguinText score_first_player;
    PenguinText score_second_player;
    PenguinText game_over_text;

    void move_first_player(float delta_time);
    void move_second_player(float delta_time);
    void move_pong_ball(float delta_time);
    void handle_collision();
    void handle_paddle_collision(Rect2<float>& paddle_rect, bool is_first_player);
    void handle_wall_collision();
    void handle_out_of_bounds();
    void reset_ball_velocity(bool to_second_player);
    bool close_game();
};

#endif // PONG_HPP