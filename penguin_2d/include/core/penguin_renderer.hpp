///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_renderer.cpp												///
///                                                                             ///
/// Defines the PenguinRenderer class, which manages rendering for a window.	///
///                                                                             ///
/// This class creates and maintains a rendering context, allowing other		///
/// classes (e.g., PenguinSprite, PenguinTextRenderer) to render objects.		///
///                                                                             ///
/// It provides functions for clearing and presenting frames, drawing shapes	///
/// (lines, rectangles, circles, ellipses), and modifying drawing colors.		///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_RENDERER_HPP
#define PENGUIN_RENDERER_HPP

// Penguin2D related include files
#include "penguin_window.hpp"
#include "colour.hpp"
#include "rect2.hpp"
#include "exception.hpp"

// SDL related include files
#include <SDL3/SDL_render.h>

// C++ library files
#include <memory>
#include <string>
#include <vector>

namespace Penguin2D {
    /// @brief Manages rendering operations for a given window.
    ///
    /// This class handles the creation and management of a rendering
    /// context, allowing for drawing operations such as rendering shapes,
    /// clearing frames, and presenting rendered content. It serves as the
    /// primary interface for graphical rendering in the Penguin2D framework.
	class PenguinRenderer {
	public:
		/// @brief Constructs a PenguinRenderer for the given window.
		/// @param window The PenguinWindow instance to render onto.
		/// @param driver_name The name of the rendering driver (optional).
		explicit PenguinRenderer(PenguinWindow& window, const std::string& driver_name = "");

        /// @brief Clears the renderer, preparing it for new drawing operations.
        void clear();

        /// @brief Draws a line between two points.
        /// @param vect_a: The starting point of the line.
        /// @param vect_b: The ending point of the line.
        /// @param colour: The color of the line.
        void draw_line(Vector2<float> vect_a, Vector2<> vect_b, Colour colour = Colours::WHITE);

        /// @brief Draws a single pixel at the specified position.
        /// @param vect: The position of the pixel.
        /// @param colour: The color of the pixel.
        void draw_pixel(Vector2<float> vect, Colour colour = Colours::WHITE);

        /// @brief Draws the outline of a rectangle.
        /// @param rect: The rectangle dimensions.
        /// @param outline: The outline color.
        void draw_rect(Rect2<float> rect, Colour outline = Colours::WHITE);

        /// @brief Draws a filled rectangle.
        /// @param rect: The rectangle dimensions.
        /// @param fill: The fill color.
        void draw_filled_rect(Rect2<float> rect, Colour fill = Colours::WHITE);

        /// @brief Draws the outline of a circle.
        /// @param center: The center of the circle.
        /// @param radius: The radius of the circle.
        /// @param outline: The outline color.
        void draw_circle(Vector2<float> center, int radius, Colour outline = Colours::WHITE);

        /// @brief Draws a filled circle.
        /// @param center: The center of the circle.
        /// @param radius: The radius of the circle.
        /// @param fill: The fill color.
        void draw_filled_circle(Vector2<float> center, int radius, Colour fill = Colours::WHITE);

        /// @brief Draws the outline of an ellipse.
        /// @param center: The center of the ellipse.
        /// @param radius_x: The horizontal radius.
        /// @param radius_y: The vertical radius.
        /// @param outline: The outline color.
        void draw_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour outline = Colours::WHITE);

        /// @brief Draws a filled ellipse.
        /// @param center: The center of the ellipse.
        /// @param radius_x: The horizontal radius.
        /// @param radius_y: The vertical radius.
        /// @param fill: The fill color.
        void draw_filled_ellipse(Vector2<float> center, int radius_x, int radius_y, Colour fill = Colours::WHITE);

        /// @brief Presents the rendered content to the window.
        void present();

        /// @brief Sets the current drawing color.
        /// @param: colour The color to set.
        void set_colour(Colour colour);

        /// @brief Resets the drawing color to its default value.
        void reset_colour();

        /// @brief Retrieves the SDL_Renderer instance.
        /// @return A pointer to the SDL_Renderer.
        SDL_Renderer* get_renderer();


	private:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
		void draw_horizontal_line(float x1, float x2, float y, Colour colour);
	};
}

#endif // PENGUIN_RENDERER_HPP