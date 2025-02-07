///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_sprite.hpp												///
///                                                                             ///
/// Defines the PenguinSprite class, which represents a drawable 2D sprite.		///
///                                                                             ///
/// This class loads an image as a texture and provides functions to render it	///
/// onto the screen. It supports full sprite rendering as well as rendering a	///
/// clipped region from the texture. It depends on PenguinRenderer for drawing.	///
///////////////////////////////////////////////////////////////////////////////////

#ifndef PENGUIN_SPRITE_HPP
#define PENGUIN_SPRITE_HPP

// Penguin2D related include files
#include "penguin_renderer.hpp"
#include "exception.hpp"
#include "rect2.hpp"

// SDL related include files
#include <SDL3_image/SDL_image.h>

// C++ library files
#include <memory>
#include <string>

namespace Penguin2D {

	/// @brief [EXPERIMENTAL] Handles the loading and rendering of sprites.
	/// 
	/// PenguinSprite is in an experimental phase and has not been thoroughly tested. Use at your own risk.
	/// 
	/// This class provides functionality to load and draw images (sprites).
	/// It also supports drawing specific regions of a sprite.
	class PenguinSprite {
	public:
		/// @brief Constructs a PenguinSprite object.
		/// @param renderer: The PenguinRenderer used for rendering the sprite.
		/// @param path: The file path to the sprite image.
		PenguinSprite(PenguinRenderer& renderer, const std::string& path);
		~PenguinSprite() = default;

		/// @brief Retrieves the width of the sprite.
		/// @return The width of the sprite in pixels.
		int get_sprite_width();

		/// @brief Retrieves the height of the sprite.
		/// @return The height of the sprite in pixels.
		int get_sprite_height();

		/// @brief Retrieves the SDL texture used for rendering the sprite.
		/// @return A pointer to the SDL_Texture.
		SDL_Texture* get_sprite_ptr();

		/// @brief Draws the sprite at a specified position.
		/// @param position: The position to render the sprite at.
		void draw_sprite(Rect2<float> position);

		/// @brief Draws a specific region of the sprite.
		/// @param clip_region: The region of the sprite to be drawn.
		/// @param position: The position to render the clipped sprite region at.
		void draw_sprite_region(Rect2<float> clip_region, Rect2<float> position);

	private:
		PenguinRenderer& renderer; /// Reference to the PenguinRenderer used for drawing the sprite.
		std::unique_ptr < SDL_Texture, void(*)(SDL_Texture*)> sprite;

	};
}

#endif // PENGUIN_SPRITE_HPP
