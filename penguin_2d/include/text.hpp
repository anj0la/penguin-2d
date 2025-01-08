#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include "penguin_text.hpp"
#include "penguin_text_renderer.hpp"

namespace Penguin2D {
	
	struct Styles {
		bool normal = true;
		bool bold = false;
		bool italic = false;
		bool underline = false;
		bool strikethrough = false;
	};

	struct Text {
		std::string text;
		std::string font_path;
		float font_size;
		Vector2<> position;
		Styles font_styles;

		// Constructors

		Text(const std::string& p_text, const std::string& p_font = "C:\\Users\\anjol\\source\\repos\\penguin_2d\\penguin_2d\\fonts\\pixelify_sans_regular.ttf", float p_font_size = 12.0f, Vector2<float> p_position = Vector2<float>(0.0, 0.0)) : text{ p_text }, font_path{ p_font }, font_size{ p_font_size }, position{ p_position } {}
		Text() : text{ "" }, font_path{ "" }, font_size{ 0.0f }, position{ Vector2<float>(0.0, 0.0) } {}

	};

}

#endif // TEXT_HPP