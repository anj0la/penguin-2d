///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_text.hpp                                                 ///
///                                                                             ///
/// Defines the PenguinText class, which represents a renderable text object.   ///
///                                                                             ///
/// This class allows manipulation of text properties such as string content,   ///
/// color, font size, and position. It utilizes a font loaded via PenguinFont   ///
/// and is rendered through PenguinTextRenderer.                                ///
///////////////////////////////////////////////////////////////////////////////////

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

    /// @brief A class for rendering and managing text.
    ///
    /// This class allows for the creation and rendering of text using a specified font.
    /// It provides functions for updating text properties such as color, position, and content.
    class PenguinText {
    public:
        /// @brief Constructs a PenguinText object.
        /// @param text_renderer: The PenguinTextRenderer responsible for rendering text.
        /// @param font_path: The file path to the font used for rendering.
        /// @param text_str: The initial string of text (optional, defaults to an empty string).
        /// @param font_size: The size of the font in pixels (optional, defaults to 12.0f).
        /// @param colour: The color of the text (optional, defaults to white).
        /// @param position: The position of the text in the window (optional, defaults to (0,0)).
        PenguinText(PenguinTextRenderer& text_renderer, const std::string& font_path, const std::string& text_str = "", float font_size = 12.0f, Colour colour = Colours::WHITE, Vector2<int> position = Vector2<int>(0, 0));

        /// @brief Draws the text at a specified position.
        /// @param position: The position to render the text at.
        void draw_text(Vector2<float> position);

        /// @brief Sets the text string to be displayed.
        /// @param new_text: The new text content.
        void set_text_string(const std::string& new_text);

        /// @brief Sets the color of the text.
        /// @param new_colour: The new color of the text.
        void set_text_colour(Colour new_colour);

        /// @brief Sets the position of the text.
        /// @param position: The new position of the text.
        void set_text_position(Vector2<int> position);

        PenguinFont font; /// The font used for rendering text.
    private:
        std::unique_ptr<TTF_Text, void(*)(TTF_Text*)> text;
    };

}

#endif // PENGUIN_TEXT_HPP