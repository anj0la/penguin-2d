# Penguin2D

Penguin2D is a lightweight and modern game framework built with C++ and SDL3, designed to help developers create simple and fun 2D games. By wrapping SDL3's C functionality into modern C++ constructs, Penguin2D ensures efficient memory management, enhanced safety, and developer-friendly APIs.

## Current Features
Penguin2D provides the following capabilities to game developers:

### Core Framework
- **PenguinGameWindow**: Manages the game loop, framerate, rendering, and updating automatically.
  - Stores width and height for tracking window size.
  - Functions to close the window and stop the game loop.
  - `connect_game()` associates the game instance with the framework.
- **PenguinGame (Virtual Class)**: Acts as a base class for all games, requiring implementations for:
  - `init()`: Load assets and initialize game objects.
  - `update(float delta_time)`: Core game logic (e.g., movement, collisions).
  - `draw(float alpha)`: Render objects onto the screen.
  - `quit()`: Clean up resources on exit.
- **PenguinBaseGame**: Extends `PenguinGame` and serves as a simplified starting point for game development. It provides default empty implementations for all virtual functions (`init()`, `update()`, `draw()`, `quit()`), so derived classes can override only the functions they need, reducing boilerplate code.

### Example Games
- **Render Shapes**: Demonstrates rendering basic shapes.
- **Pong Game**: A functional Pong implementation with:
  - Two-player input handling via `PenguinInput`.
  - Score display using `PenguinText`.
  
### Rendering
- **2D Rendering**:
  - Render basic shapes like rectangles, circles, ellipses, lines, and points using the `PenguinRenderer`.
- **Sprite Rendering**:
  - `PenguinSprite` stores an SDL texture as a `std::unique_ptr`.
  - `draw_sprite(position)`: Draws the full sprite at a specific position.
  - `draw_sprite_region(clip_region, position)`: Draws a region of the sprite onto the target.
  > **Note**: These functions remain experimental.

- **Event System**:
  - Built with callback functions, allowing modular handling of different types of events.

### Input Handling
- **Keyboard Input**:
  - `PenguinInput` tracks key press and release states.
  - `is_key_pressed(PenguinKey key)`: Checks if a key is currently pressed.
  - `is_any_key_pressed()`: Checks if any key is currently pressed.

### Timing
- **Frame Timing and Delays**:
  - `PenguinTimer` provides a `delay(float ms)` function for precise timing control.

### Font Rendering
- Integrates SDL_ttf for text rendering via `PenguinText`.

### Error Handling
- **Custom Exception Class**:
  - Wraps SDL3 functions to throw exceptions when errors occur, improving readability and debugging.

## Current Limitations
- Only input events are fully implemented; other event types (e.g., window events) are planned.
- Sprite rendering functions are untested and experimental.

## Getting Started
> **Note**: The setup instructions are outdated and will be updated soon.
> **Note**: Once a binary for the project has been built, you will be able to download it, which will include SDL3 pre-built for Windows.

### Prerequisites
- A C++ compiler supporting C++20 or later.
- SDL3, SD3_ttf and SDL_image downloaded.
- CMake for building the project.

### Building the Framework
1. Clone the repository:

```bash
git clone https://github.com/yourusername/penguin2d.git
```
2. Add SDL3-related folders in an external/ folder under the root folder of the project.
> **Note**: If not using pre-built SDL3 binaries, you will need build SDL3 yourself and follow their installation steps.
3. Navigate to the project directory:
```bash
cd penguin2d
```
4. Build the framework using CMake:
```bash
mkdir build
cd build  
cmake ..  
make
```
 > **Note**: If using Visual Studio, the framework will be built automatically when you run the project.

## Example Usage
> **Note**: The setup instructions are outdated and will be updated soon.

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
- Implement more example projects using the framework.
- Add support for audio/sound playback.
- Develop a "Flappy Penguin" demo game as a proof of concept.
- Expand rendering capabilities to include sprite tiling.
- Extend event handling to include additional SDL3 event types.
- Streamline asset management for textures and sounds.
- Add mouse and joystick input handling.
- Investigate support for Dear ImGui for debugging overlays.

## License
Currently, Penguin2D is a personal project in active development and is not yet open source. All rights to the source code are retained by me. While you're welcome to explore the project and use it as inspiration, you are not permitted to reproduce, distribute, or create derivative works based on the code.
