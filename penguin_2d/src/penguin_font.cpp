#include "penguin_font.hpp"

using namespace Penguin2D;

PenguinFont::PenguinFont(const std::string& font_path, float font_size)
	: font(TTF_OpenFont(font_path.c_str(), font_size), &TTF_CloseFont) {

	Exception::throw_if(
		!font,
		"The font could not be initialized. Please ensure that the file path exists in the project.",
		TEXT_ERROR
	);
}

TTF_Font* PenguinFont::get_font() {
	Exception::throw_if(
		!font,
		"The font has not been initialized.",
		TEXT_ERROR
	);

	return font.get();
}

void PenguinFont::set_font_size(float font_size) {
	Exception::throw_if(
		!TTF_SetFontSize(font.get(), font_size),
		"The font size could not be changed. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);
}

float PenguinFont::get_font_size() {
	float font_size = TTF_GetFontSize(font.get());
	Exception::throw_if(
		font_size == 0.0f,
		"The font size could not be retrieved. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);

	return font_size;
}

void PenguinFont::set_font_outline_size(int outline_size) {
	Exception::throw_if(
		!TTF_SetFontOutline(font.get(), outline_size),
		"The font outline could not be changed. This error might've occurred due to the font not being initialized.",
		TEXT_ERROR
	);
}

int PenguinFont::get_font_outline_size() {
	return TTF_GetFontOutline(font.get());
}

void PenguinFont::add_font_style(PenguinFontStyle style) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());
	current_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	TTF_SetFontStyle(font.get(), current_styles);
}

void PenguinFont::add_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	// OR together all font styles
	for (auto style : styles) {
		current_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	}

	TTF_SetFontStyle(font.get(), current_styles);
}

void PenguinFont::set_font_style(PenguinFontStyle style) {
	TTF_SetFontStyle(font.get(), static_cast<TTF_FontStyleFlags>(style));
}

void PenguinFont::set_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags combined_styles = TTF_STYLE_NORMAL;

	// OR together all font styles
	for (auto style : styles) {
		combined_styles |= static_cast<TTF_FontStyleFlags>(style); // ORing the new style to the existing styles
	}

	TTF_SetFontStyle(font.get(), combined_styles);
}

void PenguinFont::remove_font_style(PenguinFontStyle style) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	current_styles &= ~static_cast<TTF_FontStyleFlags>(style);
	TTF_SetFontStyle(font.get(), current_styles);
}

void PenguinFont::remove_font_styles(std::initializer_list<PenguinFontStyle> styles) {
	TTF_FontStyleFlags current_styles = TTF_GetFontStyle(font.get());

	for (auto style : styles) {
		current_styles &= ~static_cast<TTF_FontStyleFlags>(style);
	}
	TTF_SetFontStyle(font.get(), current_styles);
}