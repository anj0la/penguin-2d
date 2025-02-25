# Penguin2D Game Loop

The Penguin2D framework provides a simple and effective game loop structure for developers to build their 2D games. Here's a detailed explanation of how the game loop works:

## Flowchart

![penguin_game_flowchart](https://github.com/user-attachments/assets/5a0c568e-3ffe-49e1-a5b4-d6788efdc3fc)

## Initialization Phase

The game starts by initializing all the necessary objects for the game:
- **Window**: The game window where everything is displayed.
- **Renderer**: Used to draw objects onto the window.
- **Events and Input Systems**: Handle user interactions.

Once these objects are set up, the `init()` function is called. This function is the first customizable point in the game where developers can:
- Load assets (e.g., textures, fonts, sounds).
- Initialize variables or game objects (e.g., player positions, game states).
- Optionally draw onto the renderer using:
  - `renderer.clear()`
  - `renderer.draw_something()`
  - `renderer.present()`

## Main Game Loop

The `run()` function establishes the game loop and is the only function that needs to be called in the `main()` function. The game loop automatically handles:
- **Polling Events**: User inputs are processed, such as keyboard and mouse events.

There are three main functions that developers can override:

1. **`update(delta_time)`**  
   Used for core game logic, such as:
   - Moving sprites (e.g., player, enemies).
   - Handling collisions.
   - Managing game states.  

   > **Note**: Delta time support is not currently available, but framerate support is planned.

2. **`draw(delta_time)`**  
   Used to render game objects onto the screen. Developers must use:
   - `renderer.clear()`: Clears the current frame.
   - Drawing functions like `renderer.draw_rect()`.
   - `renderer.present()`: Presents the final frame to the screen.

3. **`quit()`**  
   Called when the game exits. Useful for:
   - Saving game states.
   - Cleaning up resources.

## Example Flow

1. **Initialization**: Setup objects and call `init()`.
2. **Game Loop**:
   - Poll events.
   - Update game logic (`update(delta_time)`).
   - Draw objects (`draw(delta_time)`).
3. **Exit**: Call `quit()` to handle cleanup.
