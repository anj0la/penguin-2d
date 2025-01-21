#include "penguin_input.hpp"

using namespace Penguin2D;

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

bool PenguinInput::is_key_pressed(PenguinKey key) {
    auto it = key_pressed_states.find(key);
    return it != key_pressed_states.end() && it->second; // true and false == false, true and true == true
}