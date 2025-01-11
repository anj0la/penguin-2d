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
    Vector2<float> circle1(300.0, 300.0);
    Vector2<float> circle2(450.0, 400.0);


    // Render a red rect with a white outline onto the screen.
    renderer.clear();
    renderer.draw_circle(circle1, 50, Colours::WHITE);
    renderer.draw_filled_circle(circle2, 50, Colours::WHITE);
    renderer.draw_rect(rect, Colours::WHITE);
    renderer.present();

    // TODO: Add your own draw logic.
}

void MyGame::quit() {
    // TODO: Add your own quit logic.
 }