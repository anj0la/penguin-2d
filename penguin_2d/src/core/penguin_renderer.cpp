///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_renderer.cpp                                             ///
///                                                                             ///
/// This file implements the PenguinRenderer class, which provides a set of		///
/// functions for rendering shapes, lines, and pixels using SDL.				///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_renderer.hpp"

using namespace Penguin2D;

/// @brief Constructs a renderer from the specified window.
/// 
/// This function initializes a PenguinRenderer for the given PenguinWindow and driver. 
/// If the PenguinRenderer cannot be created, an exception is thrown.
/// 
/// @param window: The PenguinWindow to create a rendering context.
/// @param driver_name: The driver name for the renderer, defaults to an empty string for automatic selection.
PenguinRenderer::PenguinRenderer(PenguinWindow& window, const std::string& driver_name) 
: renderer(SDL_CreateRenderer(
	window.get_window(),
	driver_name.empty() ? NULL : driver_name.c_str()), // If empty, allow SDL to handle getting the driver.
	&SDL_DestroyRenderer) {

	// Throw an exception if the renderer was not intialized.
	Exception::throw_if(!renderer, "The renderer was not initialized.", RENDERER_ERROR);
}

/// @brief Clears the renderer.
///
/// If an error occurs during this process, an exception is thrown.
void PenguinRenderer::clear() {
	reset_colour();
	Exception::throw_if(
		!SDL_RenderClear(renderer.get()),
		"Failed to set clear renderer from window.",
		RENDERER_ERROR
	);
}

/// @brief Updates the window with the current rendering content.
/// 
/// If an error occurs during this process, an exception is thrown.
void PenguinRenderer::present() {
	Exception::throw_if(
		!SDL_RenderPresent(renderer.get()),
		"Failed to set present renderer to window.",
		RENDERER_ERROR
	);
}

/// @brief Sets the drawing colour for rendering objects.
/// 
/// @param colour: The colour to set for the renderer.
void PenguinRenderer::set_colour(Colour colour) {
	Exception::throw_if(
		!SDL_SetRenderDrawColor(renderer.get(), colour.red, colour.green, colour.blue, colour.alpha),
		"Failed to set renderer draw colour.",
		RENDERER_ERROR
	);
}

/// @brief Draws a line to the renderer.
/// 
/// This function draws a line between the specified start and end points.
/// If an error occurs while drawing the line, an exception is thrown.
/// 
/// @param vect_a: The starting point of the line.
/// @param vect_b: The ending point of the line.
/// @param colour: The colour of the line to draw (optional, defaults to WHITE).
void PenguinRenderer::draw_line(Vector2<> vect_a, Vector2<> vect_b, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderLine(renderer.get(), vect_a.x, vect_a.y, vect_b.x, vect_b.y),
		"Failed to draw a line to the renderer.",
		RENDERER_ERROR
	);
}


/// @brief Draws a pixel to the renderer.
/// 
/// This function draws a single pixel at the specified location.
/// If an error occurs while drawing the pixel, an exception is thrown.
/// 
/// @param vect: The coordinates of the pixel to draw.
/// @param colour: The colour of the pixel (optional, defaults to WHITE).
void PenguinRenderer::draw_pixel(Vector2<> vect, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderPoint(renderer.get(), vect.x, vect.y),
		"Failed to draw a line to the renderer.",
		RENDERER_ERROR
	);
}

/// @brief Draws a rectangle to the renderer.
/// 
/// This function draws a rectangle at the specified location with the given outline color.
/// If an error occurs while drawing the rectangle, an exception is thrown.
/// 
/// @param rect: The rectangle object to draw.
/// @param outline: The colour of the rectangle's outline (defaults to WHITE).
void PenguinRenderer::draw_rect(Rect2<float> rect, Colour outline) {
	set_colour(outline);
	auto sdl_rect = (SDL_FRect)rect;
	Exception::throw_if(
		!SDL_RenderRect(renderer.get(), &sdl_rect),
		"Failed to draw the rect to the renderer.",
		RENDERER_ERROR
	);

}

/// @brief Draws a filled rectangle to the renderer.
/// 
/// This function draws a filled rectangle at the specified location with the given fill color.
/// If an error occurs while drawing the filled rectangle, an exception is thrown.
/// 
/// @param rect: The rectangle object to draw.
/// @param fill: The colour of the rectangle's fill (optional, defaults to WHITE).
void PenguinRenderer::draw_filled_rect(Rect2<float> rect, Colour fill) {
	set_colour(fill);
	auto sdl_rect = (SDL_FRect)rect;
	Exception::throw_if(
		!SDL_RenderFillRect(renderer.get(), &sdl_rect),
		"Failed to draw the filled rect to the renderer.",
		RENDERER_ERROR
	);
}

/// @brief Draws a circle to the renderer.
/// 
/// This function draws a circle at the specified location with the given color.
/// If an error occurs while drawing the circle, an exception is thrown.
/// 
/// @param vect: The center coordinates of the circle.
/// @param radius: The radius of the circle.
/// @param outline: The colour of the circle's outline (optional, defaults to WHITE).
void PenguinRenderer::draw_circle(Vector2<float> center, int radius, Colour outline) {
	// Initial points and decision variable.
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1); // (radius << 1 = diameter)

	// Vector for points to be rendered onto screen.
	std::vector<SDL_FPoint> points;

	// Fill all the 8 octances.
	while (x >= y) {
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x - x, center.y - y });
		points.push_back({ center.x + y, center.y + x });
		points.push_back({ center.x + y, center.y - x });
		points.push_back({ center.x - y, center.y + x });
		points.push_back({ center.x - y, center.y - x });

		if (err <= 0) {
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0) {
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}

	// Draw the circle.
	set_colour(outline);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a circle to the renderer.",
		RENDERER_ERROR
	);
}


/// @brief Draws a filled circle to the renderer.
/// 
/// This function draws a filled circle at the specified location with the given color.
/// If an error occurs while drawing the filled circle, an exception is thrown.
/// 
/// @param vect: The center coordinates of the circle.
/// @param radius: The radius of the circle.
/// @param fill: The colour of the filled circle (optional, defaults to WHITE).
void PenguinRenderer::draw_filled_circle(Vector2<float> center, int radius, Colour fill) {
	// Initial points and decision variable.
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1); // (radius << 1 = diameter)

	while (x >= y) {
		draw_horizontal_line(center.x - x, center.x + x, center.y + y, fill); // Top span
		draw_horizontal_line(center.x - x, center.x + x, center.y - y, fill); // Bottom span

		// Left and right spans.
		draw_horizontal_line(center.x - y, center.x + y, center.y + x, fill); // Right span
		draw_horizontal_line(center.x - y, center.x + y, center.y - x, fill); // Left span

		if (err <= 0) {
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0) {
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}

/// @brief Draws an ellipse to the renderer.
/// 
/// This function renders an ellipse at the specified position with the given radii.
/// The function ensures symmetry and accuracy by computing points for each region.
/// If rendering fails, an exception is thrown.
/// 
/// @param center: The center coordinates of the ellipse.
/// @param radius_x: The horizontal radius of the ellipse.
/// @param radius_y: The vertical radius of the ellipse.
/// @param outline: The colour of the ellipse outline (optional, defaults to WHITE).
void PenguinRenderer::draw_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour outline) {
	// Squares of the radii for the ellipse.
	int rx2 = radius_x * radius_x;
	int ry2 = radius_y * radius_y;

	// Initial points and decision variable for region 1.
	int x = 0;
	int y = radius_y;
	int dx = 2 * ry2 * x;
	int dy = 2 * rx2 * y;
	int err = ry2 - (rx2 * radius_y) + (rx2 / 4);

	// Vector for points to be rendered onto the screen.
	std::vector<SDL_FPoint> points;

	// |slope| < 1 (region 1).
	while (dx < dy) {
		// Symmetrical points.
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y - y });

		if (err < 0) {
			x++;
			dx += 2 * ry2;
			err += dx + ry2;
		}
		else {
			x++;
			y--;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + ry2;
		}
	}

	err = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

	// |slope| >= 1 (region 2).
	while (y >= 0) {
		// Symmetrical points.
		points.push_back({ center.x + x, center.y + y });
		points.push_back({ center.x - x, center.y + y });
		points.push_back({ center.x + x, center.y - y });
		points.push_back({ center.x - x, center.y - y });

		if (err > 0) {
			y--;
			dy -= 2 * rx2;
			err += rx2 - dy;
		}
		else {
			y--;
			x++;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + rx2;
		}
	}

	// Draw the ellipse.
	set_colour(outline);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a circle to the renderer.",
		RENDERER_ERROR
	);
}

/// @brief Draws a filled ellipse to the renderer.
/// 
/// This function renders a filled ellipse at the specified position.
/// It fills horizontal lines across the ellipse to ensure a solid fill.
/// If rendering fails, an exception is thrown.
/// 
/// @param center: The center coordinates of the ellipse.
/// @param radius_x: The horizontal radius of the ellipse.
/// @param radius_y: The vertical radius of the ellipse.
/// @param fill: The fill colour of the ellipse (optional, defaults to WHITE).
void PenguinRenderer::draw_filled_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour fill) {
	// Squares of the radii for the ellipse.
	int rx2 = radius_x * radius_x;
	int ry2 = radius_y * radius_y;

	// Initial points and decision variable for region 1.
	int x = 0;
	int y = radius_y;
	int dx = 2 * ry2 * x;
	int dy = 2 * rx2 * y;
	int err = ry2 - (rx2 * radius_y) + (rx2 / 4);

	// Vector for points to be rendered onto the screen.
	std::vector<SDL_FPoint> points;

	// |slope| < 1 (region 1).
	while (dx < dy) {
		// Fill horizontal lines for symmetrical points.
		for (int i = center.x - x; i <= center.x + x; i++) {
			points.push_back({ (float)i, center.y + y });
			points.push_back({ (float)i, center.y - y });
		}

		if (err < 0) {
			x++;
			dx += 2 * ry2;
			err += dx + ry2;
		}
		else {
			x++;
			y--;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + ry2;
		}
	}

	err = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

	// |slope| >= 1 (region 2).
	while (y >= 0) {
		// Fill horizontal lines for symmetrical points.
		for (int i = center.x - x; i <= center.x + x; i++) {
			points.push_back({ (float)i, center.y + y });
			points.push_back({ (float)i, center.y - y });
		}

		if (err > 0) {
			y--;
			dy -= 2 * rx2;
			err += rx2 - dy;
		}
		else {
			y--;
			x++;
			dx += 2 * ry2;
			dy -= 2 * rx2;
			err += dx - dy + rx2;
		}
	}

	// Draw the filled ellipse.
	set_colour(fill);
	Exception::throw_if(
		!SDL_RenderPoints(renderer.get(), points.data(), points.size()),
		"Failed to draw a filled ellipse to the renderer.",
		RENDERER_ERROR
	);
}

/// @brief Resets the rendering color to the default value.
/// 
/// This function resets the renderer's drawing color to black.
void PenguinRenderer::reset_colour() {
	set_colour(Colours::BLACK); 
}

/// @brief Retrieves the underlying SDL renderer.
/// 
/// This function provides access to the internal SDL_Renderer pointer used for rendering.
/// 
/// @return SDL_Renderer*: A pointer to the SDL_Renderer instance.
SDL_Renderer* PenguinRenderer::get_renderer() {
	return renderer.get();
}

/// @brief Draws a horizontal line to the renderer.
/// 
/// This function draws a straight horizontal line at a specified y-coordinate
/// from x1 to x2. If rendering fails, an exception is thrown.
/// 
/// @param x1: The x-coordinate of the start position.
/// @param x2: The x-coordinate of the end position.
/// @param y: The y-coordinate of the line.
/// @param colour: The colour of the line.
void PenguinRenderer::draw_horizontal_line(float x1, float x2, float y, Colour colour) {
	set_colour(colour);
	Exception::throw_if(
		!SDL_RenderLine(renderer.get(), x1, y, x2, y),
		"Failed to render a line to the screen.",
		RENDERER_ERROR
	);
}