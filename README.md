# Penguin2D

Penguin2D is a lightweight and modern game framework built with C++ and SDL3, designed to help developers create simple and fun 2D games. By wrapping SDL3's C functionality into modern C++ constructs, Penguin2D ensures efficient memory management, enhanced safety, and developer-friendly APIs.

## Current Features
Penguin2D provides the following capabilities to game developers:

### Rendering
- **2D Rendering**: Render basic shapes like rectangles, circles, ellipses, lines, and points using the `PenguinRenderer` and `PenguinWindow` classes. These classes manage SDL resources safely with smart pointers, ensuring automatic cleanup.
- **Sprite Rendering**:
  - `PenguinSprite` stores an SDL texture as a `std::unique_ptr`. It allows developers to retrieve the sprite's width and height.
  - `draw_sprite(position)`: Draws the full sprite at a specific position on the screen.
  - `draw_sprite_region(clip_region, position)`: Draws a region of the sprite onto the target.
  > **Note**: These functions are currently untested and considered experimental.

### Game Loop
- **Customizable Game Loop**:
  - `init()`: Load assets and initialize game objects.
  - `update(delta_time)`: Core game logic (e.g., movement, collisions).
  - `draw(alpha)`: Render objects onto the screen.
  - `quit()`: Clean up resources on exit.
  - **Experimental Framerate Support**:
    - Implemented fixed time step for updates, ensuring consistent game logic execution.
    - Added extrapolated state rendering for smoother visuals, with an `alpha` variable in place for potential linear interpolation in future updates.
  - **FPS Management**:
    - `set_fps_cap`: Limit the maximum frames per second for more predictable performance and reduced hardware strain.
    - `get_fps`: Access the current FPS value for debugging, logging, or other development purposes.

### Game Objects
- **Vector2**: A utility class for representing 2D positions or directions.
- **Rect2**: A rectangle composed of a `Vector2` for position and another `Vector2` for size.
- **Colour**: A simple RGBA color representation, mapping directly to SDL's color values.

### Event Handling
- **Keyboard Input**:
  - Track key press and release states using a custom keyboard input system.
  - Easily check if specific keys are pressed or released via `PenguinKey`.
- **Event System**:
  - Built with callback functions, allowing modular handling of different types of events. Currently supports input events, with the framework designed to support other event types (e.g., window events, display events) in future updates.

### Fonts
- **Font Rendering**:
  - Integrates the SDL_ttf library for basic text rendering via `PenguinText`.

### Error Handling
- **Custom Exception Class**:
  - Wraps SDL3 functions to throw exceptions when errors occur, improving readability and debugging.

## Current Limitations
- Only input events are fully implemented in the event-handling system; other event types will be added in future iterations.
- Sprite rendering functions are untested and experimental.

## Getting Started
### Prerequisites
- A C++ compiler supporting C++20 or later.
- CMake for building the project.

### Building the Framework
1. Clone the repository:

```bash
git clone https://github.com/yourusername/penguin2d.git
```

2. Navigate to the project directory:
```bash
cd penguin2d
```

3. Build the framework using CMake:
```bash
mkdir build
cd build  
cmake ..  
make
```
 > **Note**: If using Visual Studio, the framework will be built automatically when you run the project.

## Example Usage

Here's how to use Penguin2D to create a simple game.

### Define a Custom Game Class

```cpp
#define game.hpp
#include "penguin_game.hpp"

using namespace Penguin2D;

class MyGame : public PenguinGame {
public:
    void init() override {
        // TODO: Add your own initialization logic.
    }

    void update(float delta_time) override {
        // TODO: Add your own update logic.
    }

    void draw(float alpha) override {
        // Create a Rect2 object.
        Rect2<float> rect(Vector2<float>(100.0, 100.0), Vector2<float>(100.0, 100.0));

        // Render a rect with a white outline onto the screen.
        renderer.draw_rect(rect, Colours::WHITE);

        // TODO: Add your own draw logic.
    }

    void quit() override {
        // TODO: Add your own quit logic.
    }
};
```

### Run the Game

```cpp
#include "game.hpp"
#include "penguin_main.hpp"

int PenguinMain(int argc, char* argv[]) {
    MyGame game;
    game.run();
    return 0;
}
```

## Roadmap
### Planned Features
- Implement the folllowing examples on using the framework: rendering shapes, text and sprites.
- Develop a simple game, "Flappy Penguin," as a proof of concept for the framework, including support for game objects such as `PenguinTransformable` and `PenguinDrawable`.
- Implement audio/sounds.
- Expand rendering capabilities to include tiling for sprites.
- Expand the event system by supporting additional SDL3 event types, such as window and display events.
- Streamline loading and managing textures, sounds, and other assets.
- Simplify game development by eliminating the need to modify the main function when deriving from PenguinGame, streamlining the setup process.
- Add mouse and joystick input event handling to support a wider range of input devices.
- Potential support for Dear ImGui to enable in-game development tools such as debugging overlays and real-time property editing.

## License

Currently, Penguin2D is a personal project in active development and is not yet open source. All rights to the source code are retained by me. This means that while you're welcome to explore the project and use it as inspiration, you are not permitted to reproduce, distribute, or create derivative works based on the code.
