#ifndef PENGUIN_TEST_GAME_HPP
#define PENGUIN_TEST_GAME_HPP

#include "penguin_game.hpp"
#include "rect2.hpp"

class MyGame : public Penguin2D::PenguinGame {
public:
    MyGame() = default;
    ~MyGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double delta_time) override;
    void quit() override;
private:
    double elapsed_time = 0.0;
};

#endif // PENGUIN_TEST_GAME_HPP