#ifndef PONG_HPP
#define PONG_HPP

// Penguin2D related include files
#include "penguin_base_game.hpp"
#include "penguin_text.hpp"
#include "rect2.hpp"

// C++ library files
#include <numbers>

using namespace Penguin2D;

struct Player {
    Player() : paddle(Vector2<float>(10.0, 100.0)), velocity(Vector2<float>(0.0, 200.0)) {}
    ~Player() = default;

    Rect2<float> paddle;
    Vector2<float> velocity;
    int points = 0;
};

struct Ball {
    Ball() : ball_rect(Vector2<float>(10.0f, 10.0f)), velocity(200.0f, 150.0f) {}
    ~Ball() = default;

    Rect2<float> ball_rect;
    Vector2<float> velocity;
    const float BALL_SPEED = 400.0f;
};

class PongGame : public PenguinBaseGame {
public:
    PongGame(PenguinGameWindow& window) : 
        PenguinBaseGame(window), 
        game_floor(Vector2<float>((float) game_window.width, 10.0f)),
        game_ceiling(Vector2<float>((float)game_window.width, 10.0f)),
        points_first_player(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf"), 
        points_second_player(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf"),
        game_over_text(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "GAME OVER", 96.0f),
        pong_game_title(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "PONG GAME", 96.0f),
        one_player_text(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "ONE PLAYER", 48.0f),
        two_player_text(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "TWO PLAYER", 32.0f),
        enter_text(game_window.text_renderer, "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\examples\\pong\\fonts\\pixelify_sans_regular.ttf", "USE ARROW KEYS TO SELECT MODE, PRESS ENTER TO START", 16.0f) {}
    ~PongGame() = default;
protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
private:
    Player first_player;
    Player second_player;
    Ball pong_ball;
    Rect2<float> game_floor;
    Rect2<float> game_ceiling;
    PenguinText points_first_player;
    PenguinText points_second_player;
    PenguinText game_over_text;
    PenguinText pong_game_title;
    PenguinText one_player_text;
    PenguinText two_player_text;
    PenguinText enter_text;
    bool is_two_player = false;
    bool is_playing = false;
    const int GOAL_POINTS = 11;
    const float MIN_DIFF = 10.0f;

    void update_title_screen();
    void display_title_screen();
    void run_two_player_logic(float delta_time);
    void run_one_player_logic(float delta_time);
    void move_left_paddle(float delta_time);
    void move_right_paddle_ai(float delta_time);
    void move_right_paddle(float delta_time);
    void move_pong_ball(float delta_time);
    void handle_collision();
    void handle_paddle_collision(Rect2<float>& paddle_rect, bool is_first_player);
    void handle_wall_collision();
    void handle_out_of_bounds();
    void reset_ball_velocity(bool to_second_player);
    bool close_game();
};

#endif // PONG_HPP