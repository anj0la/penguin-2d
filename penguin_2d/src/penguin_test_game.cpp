#include "penguin_test_game.hpp"

void MyGame::init() {
    // TODO: Add your own initialization logic.
}

void MyGame::update(float delta_time) {
    // TODO: Add your own update logic.
}
    
void MyGame::draw(float delta_time) {
    renderer.clear();
    Rect2<float> rect(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0));
    renderer.draw_rect(rect, Colours::WHITE, Colours::RED);
    renderer.present();

    // TODO: Add your own draw logic.
}

void MyGame::quit() {
    // TODO: Add your own quit logic.
 }