#ifndef PENGUIN_RENDERER_HPP
#define PENGUIN_RENDERER_HPP

#include "penguin_window.hpp"
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
		void draw_circle(Vector2<float> center, int radius, int border, Colour outline = Colours::WHITE);
		void draw_filled_circle(Vector2<float> center, int radius, Colour fill = Colours::WHITE);
		void present();
		void set_colour(Colour colour);
		void reset_colour();
		SDL_Renderer* get_renderer();

	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;

		void x_line(int x1, int x2, int y, std::vector<SDL_FPoint>& points);
		void y_line(int x, int y1, int y2, std::vector<SDL_FPoint>& points);
		void draw_horizontal_line(float x1, float x2, float y, Colour colour);
	};
}

#endif // PENGUIN_RENDERER_HPP