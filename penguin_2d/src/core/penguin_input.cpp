/// File name: penguin_input.cpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinInput handles all input-related events.
/// 
/// This class handles keyboard input events. It provides a callback function, handle_input_event, to handle key presses.
/// 


#include "penguin_input.hpp"

using namespace Penguin2D;

/// <summary>
/// Handles key presses.
/// </summary>
/// <param name="p_event"> - the SDL event containing the SDL key that was pressed.</param>
void PenguinInput::handle_input_event(const SDL_Event& p_event) {
    if (p_event.type == SDL_EVENT_KEY_DOWN) {
        auto it = key_map.find(p_event.key.key); // Maps SDL key to PenguinKey
        if (it != key_map.end()) {
            key_pressed_states[it->second] = p_event.key.down; // The key was pressed
        }

        // Otherwise, we throw an exception to indicate that the key pressed has no mapping to a PenguinKey.
        Exception::throw_if(
            it == key_map.end(),
            "The following key is not supported.",
            INPUT_ERROR
        );
    }
    else if (p_event.type == SDL_EVENT_KEY_UP) {
        auto it = key_map.find(p_event.key.key); // Maps SDL key to PenguinKey
        if (it != key_map.end()) {
            key_pressed_states[it->second] = false; // The key was released
        }

        // Otherwise, we throw an exception to indicate that the key pressed has no mapping to a PenguinKey.
        Exception::throw_if(
            it == key_map.end(),
            "The following key is not supported.",
            INPUT_ERROR
        );
    }
}

/// <summary>
/// Checks if a key has been pressed.
/// </summary>
/// <param name="key"> - the key to check if it was pressed.</param>
/// <returns>bool - true if the key is pressed, false otherwise.</returns>
bool PenguinInput::is_key_pressed(PenguinKey key) {
    auto it = key_pressed_states.find(key);
    return it != key_pressed_states.end() && it->second; // true and false == false, true and true == true
}

/// <summary>
/// Checks if any key has been pressed.
/// </summary>
/// <returns>bool - true if any key has been pressed, false otherwise.</returns>
bool PenguinInput::is_any_key_pressed() {
    for (const auto& key_pair : key_pressed_states) {
        if (key_pair.second) { // Check if any value (key state) is true
            return true;
        }
    }
    return false;
}