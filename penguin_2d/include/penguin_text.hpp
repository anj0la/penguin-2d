#ifndef PENGUIN_TEXT_HPP
#define PENGUIN_TEXT_HPP

#include <iostream>
#include <memory>
#include <string>

#include "exception.hpp"
#include "penguin_text_renderer.hpp"
#include "penguin_font.hpp"
#include "colour.hpp"
#include "vector2.hpp"

#include <SDL3_ttf/SDL_ttf.h>

namespace Penguin2D {
    class PenguinText {
    public:
        PenguinText(PenguinTextRenderer& text_renderer, const std::string& font_path, const std::string& text_str, float font_size, Colour colour = Colours::WHITE, Vector2<int> position = Vector2<int>(0, 0));
        // PenguinText(PenguinTextRenderer& text_renderer, TTF_Font* font, const std::string& text_str, Colour colour = Colours::WHITE, Vector2<int> position = Vector2<int>(0, 0));
        void render_text(Vector2<float> position);
        void set_text_string(const std::string& new_text);
        void set_text_colour(Colour new_colour);
        void set_text_position(Vector2<int> position);

    private:
        std::unique_ptr<TTF_Text, void(*)(TTF_Text*)> text;
        PenguinFont font;
    };

}

#endif // PENGUIN_TEXT_HPP