#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "penguin_game_window.hpp"
#include "rect2.hpp"

#include <deque>
#include <cstdlib> 
#include <ctime> 

using namespace Penguin2D;

struct SnakeSegment {
    Vector2<float> position;
    Vector2<float> size;
};

class SnakeGame : public PenguinGame {
public:
    SnakeGame(PenguinGameWindow& window) :
        game_window(window),
        food(Vector2<float>(25.0f, 25.0f)),
        velocity(Vector2<float>(0.0f, 0.0f)) {}
    ~SnakeGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
    void quit() override {};
private:
    PenguinGameWindow& game_window;
    std::deque<Rect2<float>> snake;
    Rect2<float> food;
    Vector2<float> velocity;
    bool growing = false;
    int food_size = 10;

    void move_snake(float delta_time);
    bool check_wall_collision();
    bool check_snake_collision();
    void check_food_collision(Rect2<float>& food);
    void spawn_food(Rect2<float>& food);
    bool is_food_on_snake(Rect2<float>& food);
    void close_game();
};

#endif // PADDLE_HPP