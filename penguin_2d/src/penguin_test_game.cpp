#include "penguin_test_game.hpp"
#include <filesystem>

void MyGame::init() {
    // TODO: Add your own initialization logic.
    timer.set_fps_cap(true);
}

void MyGame::update(double delta_time) {
    elapsed_time += delta_time;
    if (elapsed_time > 1.0) {
        //std::cout << "One second has passed." << std::endl;
        elapsed_time = 0.0;
    }
    // TODO: Add your own update logic.
}
    
void MyGame::draw(double delta_time) {
    // Create a rect2 object.
    Rect2<float> rect(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0));
    Vector2<float> circle1(300.0, 300.0);
    Vector2<float> circle2(450.0, 400.0);

    if (std::filesystem::exists("C:/Users/anjol/source/repos/penguin_2d/penguin_2d/pixelify_sans_regular.ttf")) {
        std::cout << "It exists." << std::endl;
    }
    PenguinText text(text_renderer, "C:/Users/anjol/source/repos/penguin_2d/penguin_2d/pixelify_sans_regular.ttf.ttf", "Hello World!", 24.0f);

    //text.render_text(Vector2<float>(300.0, 20.0));

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