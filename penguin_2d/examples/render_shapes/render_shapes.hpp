#ifndef RENDER_SHAPES_HPP
#define RENDER_SHAPES_HPP

#include "penguin_game.hpp"
#include "rect2.hpp"

using namespace Penguin2D;

class MyGame : public PenguinGame {
public:
    using PenguinGame::PenguinGame; // Inherit constructors
    MyGame() : rect(Vector2<float>(100.0, 100.0)) {}
    ~MyGame() = default;

protected:
    void init() override;
    void update(double delta_time) override;
    void draw(double alpha) override;
    void quit() override;
private:
    Rect2<float> rect;
};

#endif // RENDER_SHAPES_HPP