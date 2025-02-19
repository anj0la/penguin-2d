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

### Example Game
- **Pong Game**: A functional Pong implementation with:
  - Two-player input handling via `PenguinInput`.
  - Score display using `PenguinText`.
  
### Rendering
- **2D Rendering**:
  - Render basic shapes like rectangles, circles, ellipses, lines, and points using the `PenguinRenderer`.

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
- Sprite rendering functions are in development, and will only support a few file formats to reduce  and experimental.

## Getting Started
> **Note**: The setup instructions are outdated and will be updated soon.

## Example Usage
> **Note**: The setup instructions are outdated and will be updated soon.

## Roadmap
### Planned Features
- Add support for textures.
- Add support for audio/sound playback.
- Develop a "Flappy Penguin" demo game as a proof of concept.
- Expand rendering capabilities to include sprite tiling.
- Extend event handling to include additional SDL3 event types.
- Streamline asset management for textures and sounds.
- Add mouse and joystick input handling.
- Investigate support for Dear ImGui for debugging overlays.

## License
Currently, Penguin2D is a personal project in active development and is not yet open source. All rights to the source code are retained by me. While you're welcome to explore the project and use it as inspiration, you are not permitted to reproduce, distribute, or create derivative works based on the code.
