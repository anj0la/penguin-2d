#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL3/SDL_events.h>
#include <unordered_map>
#include "exception.hpp"

namespace Penguin2D {

    enum class PenguinKey {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ESC,
        X
    };

    class PenguinInput {
    public:
        PenguinInput();
        ~PenguinInput() = default;
        void handle_input_event(const SDL_Event& p_event);
        bool is_key_pressed(PenguinKey key);

    private:
        std::unordered_map<SDL_Keycode, PenguinKey> key_map;
        std::unordered_map<PenguinKey, bool> key_pressed_states;
    };
}

#endif // INPUT_HPP