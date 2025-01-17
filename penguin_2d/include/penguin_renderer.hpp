#ifndef PENGUIN_RENDERER_HPP
#define PENGUIN_RENDERER_HPP

#include "penguin_window.hpp"
#include "penguin_sprite.hpp"
#include "colour.hpp"
#include "rect2.hpp"
#include "exception.hpp"

#include <SDL3/SDL_render.h>
#include <memory>
#include <string>
#include <vector>

namespace Penguin2D {

	class PenguinRenderer {
	public:
		explicit PenguinRenderer(PenguinWindow& p_window, const std::string& p_name = "");
		
		void clear();
		void draw_line(Vector2<float> vect_a, Vector2<> vect_b, Colour colour = Colours::WHITE);
		void draw_pixel(Vector2<float> vect, Colour colour = Colours::WHITE);
		void draw_rect(Rect2<float> rect, Colour outline = Colours::WHITE);
		void draw_filled_rect(Rect2<float> rect, Colour fill = Colours::WHITE);
		void draw_circle(Vector2<float> center, int radius, Colour outline = Colours::WHITE);
		void draw_filled_circle(Vector2<float> center, int radius, Colour fill = Colours::WHITE);
		void draw_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour outline = Colours::WHITE);
		void draw_filled_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour fill = Colours::WHITE);
		void draw_sprite(PenguinSprite sprite, Rect2<float>position);
		void draw_sprite_region(PenguinSprite sprite, Rect2<float> clip_region, Rect2<float>position);
		void present();
		void set_colour(Colour colour);
		void reset_colour();
		SDL_Renderer* get_renderer();

	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;

		void draw_horizontal_line(float x1, float x2, float y, Colour colour);
	};
}

#endif // PENGUIN_RENDERER_HPP