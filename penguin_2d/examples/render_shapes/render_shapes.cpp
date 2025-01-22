#include "penguin_test_game.hpp"

void MyGame::init() {
    // TODO: Add your own initialization logic.
    timer.set_fps_cap(true);
    text.set_text_string("Hello World!");
    text.font.set_font_size(24.0f);
}

void MyGame::update(double delta_time) {
    // TODO: Add your own update logic.
}
    
void MyGame::draw(double alpha) {
    Rect2<float> rect(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0));
    Vector2<float> circle1(300.0, 300.0);
    Vector2<float> circle2(450.0, 400.0);

    text.render_text(Vector2<float>(300.0, 20.0));

    // Render a red rect with a white outline onto the screen.
    //renderer.draw_circle(circle1, 50, Colours::WHITE);
    //renderer.draw_filled_circle(circle2, 50, Colours::WHITE);
    renderer.draw_filled_ellipse(circle1, 50, 60);
    renderer.draw_rect(rect, Colours::WHITE);

    // TODO: Add your own draw logic.
}

void MyGame::quit() {
    // TODO: Add your own quit logic.
 }