///////////////////////////////////////////////////////////////////////////////////
/// File: penguin_input.cpp                                                     ///
///                                                                             ///
/// PenguinInput handles all input-related events.                              ///
///                                                                             ///
/// This class processes keyboard input events. It provides functions to        ///
/// handle key presses and check for pressed keys.                              ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_input.hpp"

using namespace Penguin2D;

/// @brief Handles key press and release events.
///
/// This function updates the key state based on whether a key was pressed or
/// released. If the key is not mapped in key_map, an exception is thrown.
/// @param p_event: The SDL event containing the key that was pressed or released.
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

/// @brief Checks if a specific key is currently pressed.
/// 
/// This function returns whether a specific key is currently in a pressed state.
/// @param key: The key to check.
/// @return True if the key is pressed, false otherwise.
bool PenguinInput::is_key_pressed(PenguinKey key) {
    auto it = key_pressed_states.find(key);
    return it != key_pressed_states.end() && it->second; // true and false == false, true and true == true
}

/// @brief Checks if any key is currently pressed.
/// 
/// This function iterates through the key states and returns true if any key 
/// is currently in a pressed state.
/// @return True if any key is pressed, false otherwise.
bool PenguinInput::is_any_key_pressed() {
    for (const auto& key_pair : key_pressed_states) {
        if (key_pair.second) { // Check if any value (key state) is true
            return true;
        }
    }
    return false;
}