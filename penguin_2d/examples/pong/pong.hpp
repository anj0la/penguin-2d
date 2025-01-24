#ifndef PONG_HPP
#define PONG_HPP

#include "penguin_game_window.hpp"
#include "rect2.hpp"

using namespace Penguin2D;

class PongGame : public PenguinGame {
public:
    PongGame(PenguinGameWindow& window) : game_window(window), first_player(Vector2<float>(10.0, 100.0)), second_player(Vector2<float>(10.0, 100.0)) {}
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

};

#endif // PONG_HPP