#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL3/SDL_events.h>
#include <unordered_map>
#include "exception.hpp"


namespace Penguin2D {

    enum class PenguinKey {
        UNKNOWN,            // 0 
        RETURN,             // '\r'
        ESC,                // '\x1B'
        BACKSPACE,          // '\b'
        TAB,                // '\t'
        SPACE,              // ' '
        EXCLAIM,            // '!'
        AT,                 // '@'
        HASH,               // '#'
        DOLLAR,             // '$'
        PERCENT,            // '%'
        CARET,              // '^'
        AMPERSAND,          // '&'
        ASTERISK,           // '*'
        LBRACKET,           // '('
        RBRACKET,           // ')'
        MINUS,              // '-'
        PLUS,               // '+'
        KEY_0,              // '0'
        KEY_1,              // '1' 
        KEY_2,              // '2'
        KEY_3,              // '3'
        KEY_4,              // '4'
        KEY_5,              // '5'
        KEY_6,              // '6'
        KEY_7,              // '7'
        KEY_8,              // '8'
        KEY_9,              // '9'
        UNDERSCORE,         // '_'
        EQUAL_SIGN,         // '='
        GREATER,            // '>'
        LESS,               // '<'
        LBRACE,             // '{'
        RBRACE,             // '}'
        LSQUARE_BRACKET,    // '['
        RSQUARE_BRACKET,    // ']'
        QUESTION,           // '?'
        SLASH,              // '/'
        BACKSLASH,          // '\\'
        PIPE,               // '|'
        COMMA,              // ','
        PERIOD,             // '.'
        COLON,              // ':'
        SEMICOLON,          // ';'
        DQUOTE,             // '"'
        SQUOTE,             // '\''
        GRAVE,              // '`'
        TIDLE,              // '~'
        KEY_A,              // 'A'
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_W,
        KEY_V,
        KEY_X,
        KEY_Y,
        KEY_Z,
        DELETE,
        PLUSMINUS,
        CAPSLOCK,
        KEY_F1,
        KEY_F2,
        KEY_F3,
        KEY_F4,
        KEY_F5,
        KEY_F6,
        KEY_F7,
        KEY_F8,
        KEY_F9,
        KEY_F10,
        KEY_F11,
        KEY_F12,
        PRINT_SCREEN,
        SCROLL_LOCK,
        PAUSE,
        INSERT,
        HOME,
        PAGE_UP,
        PAGE_DOWN,
        END,
        RIGHT,
        LEFT,
        DOWN,
        UP,
        KEYPAD_DIVIDE,
        KEYPAD_MULTIPLY,
        KEYPAD_MINUS,
        KEYPAD_PLUS,
        KEYPAD_ENTER,
        KEYPAD_0,
        KEYPAD_1,
        KEYPAD_2,
        KEYPAD_3,
        KEYPAD_4,
        KEYPAD_5,
        KEYPAD_6,
        KEYPAD_7,
        KEYPAD_8,
        KEYPAD_9,
        KEYPAD_PERIOD,
        KEYPAD_EQUAL_SIGN,
        APPLICATION,
        UNDO,
        CUT,
        COPY,
        PASTE,
        FIND,
        MUTE,
        VOLUME_UP,
        VOLUME_DOWN,
        ALT_ERASE,
        CANCEL,
        CLEAR,
        LCTRL,
        LSHIFT,
        LALT,
        LGUI,
        RCTRL,
        RSHIFT,
        RALT,
        RGUI
    };

    class PenguinInput {
    public:
        PenguinInput() = default;
        ~PenguinInput() = default;
        void handle_input_event(const SDL_Event& p_event);
        bool is_key_pressed(PenguinKey key);

    private:
        std::unordered_map<SDL_Keycode, PenguinKey> key_map = {
            { SDLK_UNKNOWN, PenguinKey::UNKNOWN },
            { SDLK_RETURN, PenguinKey::RETURN },
            { SDLK_ESCAPE, PenguinKey::ESC },
            { SDLK_BACKSPACE, PenguinKey::BACKSPACE },
            { SDLK_TAB, PenguinKey::TAB },
            { SDLK_SPACE, PenguinKey::SPACE },
            { SDLK_EXCLAIM, PenguinKey::EXCLAIM },
            { SDLK_AT, PenguinKey::AT },
            { SDLK_HASH, PenguinKey::HASH },
            { SDLK_DOLLAR, PenguinKey::DOLLAR },
            { SDLK_PERCENT, PenguinKey::PERCENT },
            { SDLK_CARET, PenguinKey::CARET },
            { SDLK_AMPERSAND, PenguinKey::AMPERSAND },
            { SDLK_ASTERISK, PenguinKey::ASTERISK },
            { SDLK_LEFTPAREN, PenguinKey::LBRACKET },
            { SDLK_RIGHTPAREN, PenguinKey::RBRACKET },
            { SDLK_MINUS, PenguinKey::MINUS },
            { SDLK_PLUS, PenguinKey::PLUS },
            { SDLK_0, PenguinKey::KEY_0 },
            { SDLK_1, PenguinKey::KEY_1 },
            { SDLK_2, PenguinKey::KEY_2 },
            { SDLK_3, PenguinKey::KEY_3 },
            { SDLK_4, PenguinKey::KEY_4 },
            { SDLK_5, PenguinKey::KEY_5 },
            { SDLK_6, PenguinKey::KEY_6 },
            { SDLK_7, PenguinKey::KEY_7 },
            { SDLK_8, PenguinKey::KEY_8 },
            { SDLK_9, PenguinKey::KEY_9 },
            { SDLK_UNDERSCORE, PenguinKey::UNDERSCORE },
            { SDLK_EQUALS, PenguinKey::EQUAL_SIGN },
            { SDLK_GREATER, PenguinKey::GREATER },
            { SDLK_LESS, PenguinKey::LESS },
            { SDLK_LEFTBRACE, PenguinKey::LBRACE },
            { SDLK_RIGHTBRACE, PenguinKey::RBRACE },
            { SDLK_LEFTBRACKET, PenguinKey::LSQUARE_BRACKET },
            { SDLK_RIGHTBRACKET, PenguinKey::RSQUARE_BRACKET },
            { SDLK_QUESTION, PenguinKey::QUESTION },
            { SDLK_SLASH, PenguinKey::SLASH },
            { SDLK_BACKSLASH, PenguinKey::BACKSLASH },
            { SDLK_PIPE, PenguinKey::PIPE },
            { SDLK_COMMA, PenguinKey::COMMA },
            { SDLK_PERIOD, PenguinKey::PERIOD },
            { SDLK_COLON, PenguinKey::COLON },
            { SDLK_SEMICOLON, PenguinKey::SEMICOLON },
            { SDLK_APOSTROPHE, PenguinKey::DQUOTE },
            { SDLK_DBLAPOSTROPHE, PenguinKey::SQUOTE},
            { SDLK_GRAVE, PenguinKey::GRAVE },
            { SDLK_TILDE, PenguinKey::TIDLE },
            { SDLK_A, PenguinKey::KEY_A },
            { SDLK_B, PenguinKey::KEY_B },
            { SDLK_C, PenguinKey::KEY_C },
            { SDLK_D, PenguinKey::KEY_D },
            { SDLK_E, PenguinKey::KEY_E },
            { SDLK_F, PenguinKey::KEY_F },
            { SDLK_G, PenguinKey::KEY_G },
            { SDLK_H, PenguinKey::KEY_H },
            { SDLK_I, PenguinKey::KEY_I },
            { SDLK_J, PenguinKey::KEY_J },
            { SDLK_K, PenguinKey::KEY_K },
            { SDLK_L, PenguinKey::KEY_L },
            { SDLK_M, PenguinKey::KEY_M },
            { SDLK_N, PenguinKey::KEY_N },
            { SDLK_O, PenguinKey::KEY_O },
            { SDLK_P, PenguinKey::KEY_P },
            { SDLK_Q, PenguinKey::KEY_Q },
            { SDLK_R, PenguinKey::KEY_R },
            { SDLK_S, PenguinKey::KEY_S },
            { SDLK_T, PenguinKey::KEY_T },
            { SDLK_U, PenguinKey::KEY_U },
            { SDLK_V, PenguinKey::KEY_V },
            { SDLK_W, PenguinKey::KEY_W },
            { SDLK_X, PenguinKey::KEY_X },
            { SDLK_Y, PenguinKey::KEY_Y },
            { SDLK_Z, PenguinKey::KEY_Z },
            { SDLK_DELETE, PenguinKey::DELETE },
            { SDLK_PLUSMINUS, PenguinKey::PLUSMINUS },
            { SDLK_CAPSLOCK, PenguinKey::CAPSLOCK },
            { SDLK_F1, PenguinKey::KEY_F1 },
            { SDLK_F2, PenguinKey::KEY_F2 },
            { SDLK_F3, PenguinKey::KEY_F3 },
            { SDLK_F4, PenguinKey::KEY_F4 },
            { SDLK_F5, PenguinKey::KEY_F5 },
            { SDLK_F6, PenguinKey::KEY_F6 },
            { SDLK_F7, PenguinKey::KEY_F7 },
            { SDLK_F8, PenguinKey::KEY_F8 },
            { SDLK_F9, PenguinKey::KEY_F9 },
            { SDLK_F10, PenguinKey::KEY_F10 },
            { SDLK_F11, PenguinKey::KEY_F11 },
            { SDLK_F12, PenguinKey::KEY_F12 },
            { SDLK_PRINTSCREEN, PenguinKey::PRINT_SCREEN },
            { SDLK_SCROLLLOCK, PenguinKey::SCROLL_LOCK },
            { SDLK_PAUSE, PenguinKey::PAUSE },
            { SDLK_INSERT, PenguinKey::INSERT },
            { SDLK_HOME, PenguinKey::HOME },
            { SDLK_PAGEUP, PenguinKey::PAGE_UP },
            { SDLK_PAGEDOWN, PenguinKey::PAGE_DOWN },
            { SDLK_END, PenguinKey::END },
            { SDLK_RIGHT, PenguinKey::RIGHT },
            { SDLK_LEFT, PenguinKey::LEFT },
            { SDLK_DOWN, PenguinKey::DOWN },
            { SDLK_UP, PenguinKey::UP },
            { SDLK_KP_DIVIDE, PenguinKey::KEYPAD_DIVIDE },
            { SDLK_KP_MULTIPLY, PenguinKey::KEYPAD_MULTIPLY },
            { SDLK_KP_MINUS, PenguinKey::KEYPAD_MINUS },
            { SDLK_KP_PLUS, PenguinKey::KEYPAD_PLUS },
            { SDLK_KP_ENTER, PenguinKey::KEYPAD_ENTER },
            { SDLK_KP_0, PenguinKey::KEYPAD_0 },
            { SDLK_KP_1, PenguinKey::KEYPAD_1 },
            { SDLK_KP_2, PenguinKey::KEYPAD_2 },
            { SDLK_KP_3, PenguinKey::KEYPAD_3 },
            { SDLK_KP_4, PenguinKey::KEYPAD_4 },
            { SDLK_KP_5, PenguinKey::KEYPAD_5 },
            { SDLK_KP_6, PenguinKey::KEYPAD_6 },
            { SDLK_KP_7, PenguinKey::KEYPAD_7 },
            { SDLK_KP_8, PenguinKey::KEYPAD_8 },
            { SDLK_KP_9, PenguinKey::KEYPAD_9 },
            { SDLK_KP_PERIOD, PenguinKey::KEYPAD_PERIOD },
            { SDLK_KP_EQUALS, PenguinKey::KEYPAD_EQUAL_SIGN },
            { SDLK_APPLICATION, PenguinKey::APPLICATION },
            { SDLK_UNDO, PenguinKey::UNDO },
            { SDLK_CUT, PenguinKey::CUT },
            { SDLK_COPY, PenguinKey::COPY },
            { SDLK_PASTE, PenguinKey::PASTE },
            { SDLK_FIND, PenguinKey::FIND },
            { SDLK_MUTE, PenguinKey::MUTE },
            { SDLK_VOLUMEUP, PenguinKey::VOLUME_UP },
            { SDLK_VOLUMEDOWN, PenguinKey::VOLUME_DOWN },
            { SDLK_ALTERASE, PenguinKey::ALT_ERASE },
            { SDLK_CANCEL, PenguinKey::CANCEL },
            { SDLK_CLEAR, PenguinKey::CLEAR },
            { SDLK_LCTRL, PenguinKey::LCTRL },
            { SDLK_LSHIFT, PenguinKey::LSHIFT },
            { SDLK_LALT, PenguinKey::LALT },
            { SDLK_LGUI, PenguinKey::LGUI },
            { SDLK_RCTRL, PenguinKey::RCTRL },
            { SDLK_RSHIFT, PenguinKey::RSHIFT },
            { SDLK_RALT, PenguinKey::RALT },
            { SDLK_RGUI, PenguinKey::RGUI },
        };
        std::unordered_map<PenguinKey, bool> key_pressed_states;
    };
}

#endif // INPUT_HPP