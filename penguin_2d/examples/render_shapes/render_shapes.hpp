#ifndef PENGUIN_TEST_GAME_HPP
#define PENGUIN_TEST_GAME_HPP

#include "penguin_game.hpp"
#include "penguin_text.hpp"
#include "rect2.hpp"

using namespace Penguin2D;

class MyGame : public PenguinGame {
public:
    MyGame() : text(text_renderer, "C:/Users/anjol/source/repos/penguin_2d/penguin_2d/fonts/pixelify_sans_regular.ttf") {}
    ~MyGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
    void quit() override;
private:
    double elapsed_time = 0.0;
    PenguinText text;
};

#endif // PENGUIN_TEST_GAME_HPP