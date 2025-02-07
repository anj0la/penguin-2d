///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_text.cpp                                                 ///
///                                                                             ///
/// PenguinText represents a text, with functions for manipulating the text,    ///
/// such as the text colour, position, string, font size, and style.            ///
///                                                                             ///
/// This is the implementation file of the PenguinText class, which handles all ///
/// text operations.                                                            ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_text.hpp"

using namespace Penguin2D;

/// @brief Creates a PenguinText object from the text renderer.
/// 
/// This constructor initializes a text object that can be rendered onto the game window.
/// It loads the specified font and sets the text string, color, and position.
/// 
/// @param text_renderer: The text renderer responsible for managing text rendering.
/// @param font_path: The file path to the font to be used.
/// @param text_str: The initial string of text (optional, defaults to an empty string).
/// @param font_size: The size of the font in pixels (optional, defaults to 12.0f).
/// @param colour: The color of the text (optional, defaults to white).
/// @param position: The position of the text in the window (optional, defaults to (0,0)).
PenguinText::PenguinText(PenguinTextRenderer& text_renderer, const std::string& font_path, const std::string& text_str, float font_size, Colour colour, Vector2<int> position)
    : font(font_path, font_size), 
      text(nullptr, &TTF_DestroyText) {

    // Initialize the text pointer
    text.reset(TTF_CreateText(
        text_renderer.get_text_renderer(),
        font.get_font(),
        text_str.c_str(),
        0));

    Exception::throw_if(
        !text,
        "The text could not be created due to one of the following objects: PenguinTextRenderer.",
        INIT_ERROR
    );

    // Set the text colour.
    set_text_colour(colour);

    // Set the text position
    set_text_position(position);
}

/// @brief Draws the text onto the renderer.
/// 
/// This function renders the text onto the game window at the specified position.
/// @param position: The position to draw the text.
void PenguinText::draw_text(Vector2<float> position) {
    Exception::throw_if(
        !TTF_DrawRendererText(text.get(), position.x, position.y),
        "The text could not be rendered onto the screen.",
        TEXT_ERROR
    );
}

/// @brief Sets the text content.
/// 
/// Updates the displayed text to a new string.
/// @param new_text: The new string to be displayed.
void PenguinText::set_text_string(const std::string& new_text) {
    Exception::throw_if(
        !TTF_SetTextString(text.get(), new_text.c_str(), 0),
        "The contents of the text could not be changed.",
        TEXT_ERROR
    );
}

/// @brief Sets the text color.
/// 
/// Changes the color of the displayed text.
/// @param new_colour: The new color of the text.
void PenguinText::set_text_colour(Colour new_colour) {
    Exception::throw_if(
        !TTF_SetTextColor(text.get(), new_colour.red, new_colour.green, new_colour.blue, new_colour.alpha),
        "The colour of the text could not be changed.",
        TEXT_ERROR
    );
}

/// @brief Sets the text position.
/// 
/// Updates the position of the text on the screen.
/// @param position: The new position of the text.
void PenguinText::set_text_position(Vector2<int> position) {
    Exception::throw_if(
        !TTF_SetTextPosition(text.get(), position.x, position.y),
        "The position of the text could not be changed.",
        TEXT_ERROR
    );
}