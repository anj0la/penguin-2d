///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_font.cpp                                                 ///
///                                                                             ///
/// PenguinFont represents a font, providing functionality for loading fonts,   ///
/// setting font size, and retrieving font properties.                          ///
///                                                                             ///
/// WARNING: Functions related to font styles (bold, italic, etc.) are unsafe   ///
/// and untested. Using them may cause unexpected behavior.                     ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_font.hpp"

using namespace Penguin2D;

/// @brief Constructs a PenguinFont from the given file path and size.
/// 
/// This function loads the font from the specified file and sets its initial size.
/// If the font cannot be loaded, an exception is thrown.
/// 
/// @param font_path: The file path to the font.
/// @param font_size: The desired font size.
PenguinFont::PenguinFont(const std::string& font_path, float font_size)
	: font(TTF_OpenFont(font_path.c_str(), font_size), &TTF_CloseFont) {

	Exception::throw_if(
		!font,
		"The font could not be initialized. Please ensure that the file path exists in the project.", // Change to SDL for more info
		TEXT_ERROR
	);
}

/// @brief Retrieves the internal SDL font object.
/// 
/// This function returns a pointer to the loaded font. If the font has not been 
/// initialized, an exception is thrown.
/// 
/// @return A pointer to the internal TTF_Font object.
TTF_Font* PenguinFont::get_font() {
	Exception::throw_if(
		!font,
		"The font has not been initialized.",
		TEXT_ERROR
	);

	return font.get();
}

/// @brief Sets the font size.
/// 
/// This function modifies the size of the loaded font. If the operation fails, 
/// an exception is thrown.
/// 
/// @param font_size: The new font size.
void PenguinFont::set_font_size(float font_size) {
	Exception::throw_if(
		!TTF_SetFontSize(font.get(), font_size),
		"The font size could not be changed. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);
}

/// @brief Retrieves the current font size.
/// 
/// If the font size cannot be determined, an exception is thrown.
/// 
/// @return The current font size.
float PenguinFont::get_font_size() {
	float font_size = TTF_GetFontSize(font.get());
	Exception::throw_if(
		font_size == 0.0f,
		"The font size could not be retrieved. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);

	return font_size;
}

/// @brief Sets the font outline size.
/// 
/// This function changes the outline size of the font. If the operation fails, 
/// an exception is thrown.
/// 
/// @param outline_size: The new outline size.
void PenguinFont::set_font_outline_size(int outline_size) {
	Exception::throw_if(
		!TTF_SetFontOutline(font.get(), outline_size),
		"The font outline could not be changed. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);
}

/// @brief Retrieves the current font outline size.
/// 
/// @return The current outline size of the font.
int PenguinFont::get_font_outline_size() {
	return TTF_GetFontOutline(font.get());
}

/// @brief Adds a font style (bold, italic, etc.).
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function applies an additional style to the font without removing existing styles.
/// 
/// @param style: The font style to apply.
void PenguinFont::add_font_style(PenguinFontStyle style) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());
	current_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	TTF_SetFontStyle(font.get(), current_styles);
}

/// @brief Adds multiple font styles.
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function applies multiple styles to the font without removing existing styles.
/// 
/// @param styles: A list of font styles to apply.
void PenguinFont::add_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	// OR together all font styles
	for (auto style : styles) {
		current_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	}

	TTF_SetFontStyle(font.get(), current_styles);
}

/// @brief Sets the font style, replacing any existing styles.
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function applies a single style to the font, replacing any previously set styles.
/// 
/// @param style: The font style to set.
void PenguinFont::set_font_style(PenguinFontStyle style) {
	TTF_SetFontStyle(font.get(), static_cast<TTF_FontStyleFlags>(style));
}

/// @brief Sets multiple font styles, replacing any existing styles.
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function applies multiple styles to the font, replacing any previously set styles.
/// 
/// @param styles: A list of font styles to set.
void PenguinFont::set_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags combined_styles = TTF_STYLE_NORMAL;

	// OR together all font styles
	for (auto style : styles) {
		combined_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	}

	TTF_SetFontStyle(font.get(), combined_styles);
}

/// @brief Removes a font style.
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function removes a specific style from the font while keeping other styles intact.
/// 
/// @param style: The font style to remove.
void PenguinFont::remove_font_style(PenguinFontStyle style) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	current_styles &= ~static_cast<TTF_FontStyleFlags>(style);
	TTF_SetFontStyle(font.get(), current_styles);
}

/// @brief Removes multiple font styles.
/// 
/// WARNING: This function is unsafe and untested. Using it may cause unexpected behavior.
/// 
/// This function removes multiple styles from the font while keeping other styles intact.
/// 
/// @param styles: A list of font styles to remove.
void PenguinFont::remove_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	for (auto style : styles) {
		current_styles &= ~static_cast<TTF_FontStyleFlags>(style);
	}
	TTF_SetFontStyle(font.get(), current_styles);
}