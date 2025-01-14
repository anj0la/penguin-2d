#ifndef PENGUIN_TEST_GAME_HPP
#define PENGUIN_TEST_GAME_HPP

#include "penguin_game.hpp"
#include "penguin_text.hpp"
#include "rect2.hpp"

using namespace Penguin2D;

class MyGame : public PenguinGame {
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