#include "penguin_test_game.hpp"

void MyGame::init() {
    // TODO: Add your own initialization logic.
}

void MyGame::update(float delta_time) {
    // TODO: Add your own update logic.
}
    
void MyGame::draw(float delta_time) {
    // Create a rect2 object.
    Rect2<float> rect(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0));

    Vector2<float> center(300.0, 300.0);

    // Render a red rect with a white outline onto the screen.
    renderer.clear();
    renderer.draw_circle(center, 50, Colours::TRANSPARENT, Colours::BLUE);
    renderer.draw_rect(rect, Colours::WHITE, Colours::RED);
    renderer.present();

    // TODO: Add your own draw logic.
}

void MyGame::quit() {
    // TODO: Add your own quit logic.
 }