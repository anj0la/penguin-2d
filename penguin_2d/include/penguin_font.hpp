#ifndef PENGUIN_FONT_HPP
#define PENGUIN_FONT_HPP

#include <iostream>
#include <memory>
#include <string>
#include "exception.hpp"

#include <SDL3_ttf/SDL_ttf.h>


namespace Penguin2D {

    enum class PenguinFontStyle {
        NORMAL          = TTF_STYLE_NORMAL,
        BOLD            = TTF_STYLE_BOLD,
        ITALIC          = TTF_STYLE_ITALIC,
        UNDERLINE       = TTF_STYLE_UNDERLINE,
        STRIKETHROUGH   = TTF_STYLE_STRIKETHROUGH
    };

    class PenguinFont {
    public:
        PenguinFont(std::string font_name, float font_size);
        TTF_Font* get_font();

        // Setter and getter for the font size. 
        void set_font_size(float font_size); // -> extern SDL_DECLSPEC bool SDLCALL TTF_SetFontSize(TTF_Font *font, float ptsize);
        float get_font_size(); // -> TTF_GetFontSize

        // Setter and getter for the font outline.
        void set_font_outline_size(int outline_size);
        int get_font_outline_size();

        // The following methods keep existing (added) font styles.

        void add_font_style(PenguinFontStyle style);
        void add_font_styles(std::initializer_list<PenguinFontStyle> styles);

        // The following methods overwrite existing font styles.

        void set_font_style(PenguinFontStyle style); // Overwrites existing font styles
        void set_font_styles(std::initializer_list<PenguinFontStyle> styles);

        // The following methods remove font styles.

        void remove_font_style(PenguinFontStyle style);
        void remove_font_styles(std::initializer_list<PenguinFontStyle> styles);

    private:
        std::unique_ptr<TTF_Font, void(*)(TTF_Font*)> font;
    };
}

#endif // PENGUIN_FONT_HPP
