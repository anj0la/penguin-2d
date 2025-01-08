# Penguin2D

Penguin2D is a lightweight and modern game framework built with C++ and SDL3, designed to help developers create simple and fun 2D games. By wrapping SDL3's C functionality into modern C++ constructs, Penguin2D ensures efficient memory management, enhanced safety, and developer-friendly APIs.

## Current Features
Penguin2D provides the following capabilities to game developers:

### Rendering
- 2D Rendering: Render basic shapes like rectangles, lines, and points using the PenguinRenderer and PenguinWindow classes. These classes manage SDL resources safely with smart pointers, ensuring automatic cleanup.

### Game Objects
- Vector2: A utility class for representing 2D positions or directions.
- Rect2: A rectangle composed of a Vector2 for position and another Vector2 for size.
- Colour: A simple RGBA color representation, mapping directly to SDL's color values.

### Event Handling
#### Keyboard Input:
- Track key press and release states using a custom keyboard input system.
- Easily check if specific keys are pressed or released via PenguinKey.

#### Event System:
- Built with callback functions, allowing modular handling of different types of events.
 Currently supports input events, with the framework designed to support other event types (e.g., window events, display events) in future updates.

### Fonts (Experimental)
#### Font Rendering:
- Integrates the SDL_ttf library for basic text rendering.
- Fonts can be rendered to the screen, through the use of the display_text function to handle resource management.

### Error Handling
#### Custom Exception Class:
- Wraps SDL3 functions to throw exceptions when errors occur, improving readability and debugging.

## Current Limitations
- Only input events are fully implemented in the event-handling system; other event types will be added in future iterations.
- Font management requires the display_text function; it will be moved into a different class providing better functionality to use texts and fonts.

## Getting Started
### Prerequisites
- A C++ compiler supporting C++17 or later.
- SDL3 and SDL_ttf libraries installed on your system. They can be found here: https://github.com/libsdl-org/SDL, https://github.com/libsdl-org/SDL_ttf
- CMake for building the project.

### Building the Framework
1. Clone the repository:

```
git clone https://github.com/yourusername/penguin2d.git
```

2. Navigate to the project directory:
```
cd penguin2d
```

3. Build the framework using CMake:
```
mkdir build && cd build  
cmake ..  
make
```
Note: if using Visual Studio, the framework will be built automatically when you run the project.

### Example Usage
An example to render a rectangle using Penguin2D:

```cpp
#include "penguin_2d.hpp"

using namespace Penguin2D;

int main() {
    // Initialize SDL. 
    Exception::throw_if(
        !SDL_Init(SDL_INIT_VIDEO),
        "Could not initialize SDL3.",
        INIT_ERROR
    );

    // Create an application window of size 640 by 480 that is useable with OpenGL.
    PenguinWindow window("Penguin Game", Vector2<int>(640, 480), SDL_WINDOW_OPENGL);

    // Create a renderer that uses the above window with the default rendering driver (handled by SDL).
    PenguinRenderer renderer(window, "");

    // Create an event handler and input system.
    PenguinEventHandler event_handler;
    PenguinInput input;

    // Add the handle input event function as a listener to the event handler.
    event_handler.add_event_listener([&input](const SDL_Event& p_event) {
        input.handle_input_event(p_event);
        });

    // Create the rectangle to draw onto the screen.
    Rect2 rect(Vector2<>(100, 100), Vector2<>(200, 150));  // size, position as floating point values (Vector2 defaults to float)

    // Keep track of game state.
    bool game_running = true;

    while (game_running) {

        // Get all events.
        event_handler.poll_events();

        // Check if the game should be quit (i.e., close the window).
        if (event_handler.should_quit()) {
            game_running = false; 
        }

        // Another check to quit the game.
        if (input.is_key_pressed(PenguinKey::ESC)) {
            game_running = false;
        }

        // Render the rect onto the window.
        renderer.clear(); // clears everything currently on the window
        renderer.draw_rect(rect, Colours::WHITE, Colours::RED); // rect, outline, fill
        renderer.present(); // displays rect onto the window
    }

    // Clean up SDL related items.
    SDL_Quit(); 

    return 0;  
}
```

## Roadmap
- Expand rendering capabilities to include textures and sprites.
- Create a main game engine/framework class to abstract core systems, such as:
  - Initializing and shutting down SDL (e.g., wrapping SDL_Init and SDL_Quit).
  - Managing key subsystems like rendering, event handling, and timing in a single interface for ease of use.
  - Managing framerates for rendering with delta time.
- Add scrolling background functionality for parallax and infinite scrolling effects.
- Add support for Dear ImGui to enable in-game development tools such as debugging overlays and real-time property editing.
- Replace scrolling background functionality with a 2D Camera System, allowing developers to focus on specific parts of the game world.
- Add mouse and joystick input event handling to support a wider range of input devices.
- Add support for more event types (e.g., window events, display events).
- Introduce a potential Entity-Component System (ECS) for better modularity and scalability (long-term goal).
- Provide more utility classes and tools to streamline 2D game development.
