/// File name: penguin_text.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinText represents a text, with functions for manipulating the text, such as the text colour, position, string, font size and style.
/// 
/// This class creates a text that can be rendered onto the screen with the draw_text() function.
/// The font can be accessed with the font variable to manipulate the font associated with the text.
///

#ifndef PENGUIN_TEXT_HPP
#define PENGUIN_TEXT_HPP

// Penguin2D related include files
#include "exception.hpp"
#include "penguin_text_renderer.hpp"
#include "penguin_font.hpp"
#include "colour.hpp"
#include "vector2.hpp"

// SDL related include files
#include <SDL3_ttf/SDL_ttf.h>

// C++ library files
#include <iostream>
#include <memory>
#include <string>

namespace Penguin2D {

    class PenguinText {
    public:
        PenguinText(PenguinTextRenderer& text_renderer, const std::string& font_path, const std::string& text_str = "", float font_size = 12.0f, Colour colour = Colours::WHITE, Vector2<int> position = Vector2<int>(0, 0));

        void draw_text(Vector2<float> position);
        void set_text_string(const std::string& new_text);
        void set_text_colour(Colour new_colour);
        void set_text_position(Vector2<int> position);

        PenguinFont font;
    private:
        std::unique_ptr<TTF_Text, void(*)(TTF_Text*)> text;
    };

}

#endif // PENGUIN_TEXT_HPP