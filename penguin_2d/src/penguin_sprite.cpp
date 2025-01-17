#include "penguin_sprite.hpp"

using namespace Penguin2D;

PenguinSprite::PenguinSprite(PenguinRenderer& renderer, const std::string& path)
	: sprite(IMG_LoadTexture(
		renderer.get_renderer(), 
		path.c_str()),
		&SDL_DestroyTexture) {

	// Throw an exception if the sprite was not intialized.
	Exception::throw_if(!sprite, "The sprite was not initialized. Ensure that the file path is a valid path.", RENDERER_ERROR); // TODO: Expand to add SDL_Error() for more information.
}

int PenguinSprite::get_sprite_width() {
	return sprite.get()->w;
}

int PenguinSprite::get_sprite_height() {
	return sprite.get()->h;
}

// Returns a pointer to the internal representation of the sprite (SDL_Texture).
SDL_Texture* PenguinSprite::get_sprite_ptr() {
	return sprite.get();
}