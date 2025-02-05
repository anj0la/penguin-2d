/// File name: penguin_text.cpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinText represents a text, with functions for manipulating the text, such as the text colour, position, string, font size and style.
/// 
/// This is the implementation file of the PenguinText class, which handles all text operations.
///

#include "penguin_text.hpp"

using namespace Penguin2D;

/// <summary>
/// Creates a text from the text renderer. Once created, it can be renderered onto the window with the draw_text() function.
/// </summary>
/// <param name="text_renderer"> - the text renderer.</param>
/// <param name="font_path"> - the path to the font.</param>
/// <param name="text_str"> - the initial text.</param>
/// <param name="font_size"> - the size of the text.</param>
/// <param name="colour"> - the colour of the text.</param>
/// <param name="position"> - the position of the text.</param>
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

/// <summary>
/// Draws the texet onto the renderer.
/// </summary>
/// <param name="position"> - the position to draw the text to.</param>
void PenguinText::draw_text(Vector2<float> position) {
    Exception::throw_if(
        !TTF_DrawRendererText(text.get(), position.x, position.y),
        "The text could not be rendered onto the screen.",
        TEXT_ERROR
    );
}

/// <summary>
/// Sets the text string.
/// </summary>
/// <param name="new_text"></param>
void PenguinText::set_text_string(const std::string& new_text) {
    Exception::throw_if(
        !TTF_SetTextString(text.get(), new_text.c_str(), 0),
        "The contents of the text could not be changed.",
        TEXT_ERROR
    );
}

void PenguinText::set_text_colour(Colour new_colour) {
    Exception::throw_if(
        !TTF_SetTextColor(text.get(), new_colour.red, new_colour.green, new_colour.blue, new_colour.alpha),
        "The colour of the text could not be changed.",
        TEXT_ERROR
    );
}

void PenguinText::set_text_position(Vector2<int> position) {
    Exception::throw_if(
        !TTF_SetTextPosition(text.get(), position.x, position.y),
        "The position of the text could not be changed.",
        TEXT_ERROR
    );
}