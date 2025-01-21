#ifndef PENGUIN_SPRITE_HPP
#define PENGUIN_SPRITE_HPP

#include "penguin_renderer.hpp"
#include "exception.hpp"

#include <memory>
#include <string>

#include <SDL3_image/SDL_image.h>

namespace Penguin2D {
	class PenguinSprite {
	public:
		PenguinSprite(PenguinRenderer& renderer, const std::string& path);
		~PenguinSprite() = default;

		int get_sprite_width();
		int get_sprite_height();
		SDL_Texture* get_sprite_ptr();

	private:
		std::unique_ptr < SDL_Texture, void(*)(SDL_Texture*)> sprite;
	};
}

#endif // PENGUIN_SPRITE_HPP
