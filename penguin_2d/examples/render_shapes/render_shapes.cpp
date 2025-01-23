#include "render_shapes.hpp"

void MyGame::init() {
    // TODO: Add your own initialization logic.
}

void MyGame::update(double delta_time) {
    // TODO: Add your own update logic.
    Vector2<float> velocity(10.0, 0.0); // Velocity in pixels per second (movement ONLY on the x-axis)

    // Move the rect to the left
    if (input.is_key_pressed(PenguinKey::KEY_A)) {
        rect -= velocity * delta_time;

        // Clipping rect's position to start of the screen
        if (rect.position < Vector2<float>(0.0, 0.0)) {
            rect.position = Vector2<float>(0.0, 0.0);
        }
    }

    // Move the rect to the right
    if (input.is_key_pressed(PenguinKey::KEY_D)) {
        rect += velocity * delta_time;

        // Clipping rect's position to end of the screen
        // TODO: Change magic word (640.0) to constant width / hidth variables stored in PenguinWindow
        if (rect.position > Vector2<float>(640.0, 0.0)) {
            rect.position = Vector2<float>(640.0, 0.0);
        }
    }
}
    
void MyGame::draw(double alpha) {
    // Render the rect onto the screen.
    renderer.draw_rect(rect, Colours::WHITE);
    // TODO: Add your own draw logic.
}

void MyGame::quit() {
    // TODO: Add your own quit logic.
 }