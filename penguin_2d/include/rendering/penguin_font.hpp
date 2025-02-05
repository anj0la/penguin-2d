/// File name: penguin_font.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinFont represents a font, with functions for manipulating the font, such as the font size and style.
/// 
/// This class is used internally in PenguinText to create a text. Currently the font size can be changed, along with the outline size and font styles.
/// Changing a font once it has been set is currently not supported.
/// 
/// The structure PenguinFontStyle is used to apply styles to the font. They map to the corresponding SDL_TTF font styles.
///

#ifndef PENGUIN_FONT_HPP
#define PENGUIN_FONT_HPP

// Penguin2D related include files
#include "exception.hpp"

// SDL related include files
#include <SDL3_ttf/SDL_ttf.h>

// C++ library files
#include <iostream>
#include <memory>
#include <string>

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
        PenguinFont(const std::string& font_path, float font_size);
        TTF_Font* get_font();

        void set_font_size(float font_size);
        float get_font_size();

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
