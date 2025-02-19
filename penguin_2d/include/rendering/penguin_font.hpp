///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_font.hpp                                                 ///
///                                                                             ///
/// Defines the PenguinFont class, which encapsulates a font object.            ///
///                                                                             ///
/// This class is used to load and manage fonts, allowing control over          ///
/// font size, outline size, and style. It supports font style modifications    ///
/// using the PenguinFontStyle enumeration, mapping directly to SDL_TTF styles. ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_FONT_HPP
#define PENGUIN_FONT_HPP

// Penguin2D related include files
#include "exception.hpp"

// SDL related include files
#include <SDL_ttf.h>

// C++ library files
#include <iostream>
#include <memory>
#include <string>

namespace Penguin2D {

    /// @brief Represents different styles that can be applied to fonts.
    ///
    /// Each enum value corresponds to a predefined font style in the SDL_ttf library.
    enum class PenguinFontStyle {
        NORMAL          = TTF_STYLE_NORMAL,
        BOLD            = TTF_STYLE_BOLD,
        ITALIC          = TTF_STYLE_ITALIC,
        UNDERLINE       = TTF_STYLE_UNDERLINE,
        STRIKETHROUGH   = TTF_STYLE_STRIKETHROUGH
    };

    /// @brief Manages font properties and rendering settings.
    ///
    /// This class provides functions for handling font sizes, outlines, and styles.
    /// It ensures proper resource management of the font.
    class PenguinFont {
    public:
        /// @brief Constructs a PenguinFont object.
        /// @param font_path: The file path to the font.
        /// @param font_size: The size of the font in pixels.
        PenguinFont(const std::string& font_path, float font_size);

        /// @brief Retrieves the underlying font object.
        /// @return A pointer to the TTF_Font used for rendering.
        TTF_Font* get_font();

        /// @brief Sets the font size.
        /// @param font_size: The new font size in pixels.
        void set_font_size(float font_size);

        /// @brief Gets the current font size.
        /// @return The font size in pixels.
        float get_font_size();

        /// @brief Sets the font outline size.
        /// @param outline_size: The new outline size in pixels.
        void set_font_outline_size(int outline_size);

        /// @brief Gets the current font outline size.
        /// @return The outline size in pixels.
        int get_font_outline_size();

        //////////////////////////////////////////////////////////////////////////////////
        /// UNSAFE FUNCTIONS                                                           ///
        //////////////////////////////////////////////////////////////////////////////////
        /// Note: The following functions have not been tested and may not work as     ///
        /// intended.                                                                  ///
        //////////////////////////////////////////////////////////////////////////////////

        /// @brief [UNSAFE] Adds a single font style without removing existing styles.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param style: The font style to be added.
        void add_font_style(PenguinFontStyle style);

        /// @brief [UNSAFE] Adds multiple font styles without removing existing styles.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param styles: A list of font styles to be added.
        void add_font_styles(std::initializer_list<PenguinFontStyle> styles);

        /// @brief [UNSAFE] Sets a single font style, overwriting existing styles.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param style: The font style to be applied.
        void set_font_style(PenguinFontStyle style);

        /// @brief [UNSAFE] Sets multiple font styles, overwriting existing styles.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param styles: A list of font styles to be applied.
        void set_font_styles(std::initializer_list<PenguinFontStyle> styles);

        /// @brief [UNSAFE] Removes a specific font style.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param style: The font style to be removed.
        void remove_font_style(PenguinFontStyle style);

        /// @brief [UNSAFE] Removes multiple font styles.
        /// 
        /// This function is untested and may not work correctly. Use with caution.
        /// @param styles: A list of font styles to be removed.
        void remove_font_styles(std::initializer_list<PenguinFontStyle> styles);

    private:
        std::unique_ptr<TTF_Font, void(*)(TTF_Font*)> font;
    };
}

#endif // PENGUIN_FONT_HPP
