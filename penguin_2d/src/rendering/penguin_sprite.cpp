///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_sprite.cpp                                               ///
///                                                                             ///
/// PenguinSprite represents a sprite, providing functionality for loading		///
/// textures, getting sprite dimensions, and drawing the sprite to the screen.	///
///                                                                             ///
/// WARNING: Ensure that the file path is valid.					            ///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_sprite.hpp"

using namespace Penguin2D;

/// @brief Constructs a PenguinSprite from the given file path and renderer.            
///                                                                             
/// This function loads the sprite texture from the specified file and attaches 
/// it to the provided renderer. If the sprite cannot be loaded, an exception
/// is thrown.                                         
///                                                                             
/// @param renderer: The renderer to associate with the sprite.                  
/// @param path: The file path to the sprite texture.
PenguinSprite::PenguinSprite(PenguinRenderer& renderer, const std::string& path)
	: renderer(renderer), // Initializes the member reference with the parameter
		sprite(IMG_LoadTexture(
		renderer.get_renderer(), 
		path.c_str()),
		&SDL_DestroyTexture) {

	// Throw an exception if the sprite was not intialized.
	Exception::throw_if(!sprite, "The sprite was not initialized. Ensure that the file path is a valid path.", RENDERER_ERROR); // TODO: Expand to add SDL_Error() for more information.
}

/// @brief Retrieves the width of the sprite.                           
///                                                                             
/// This function returns the width of the sprite texture.                                     
///                                                                          
/// @return int: The width of the sprite texture. 
int PenguinSprite::get_sprite_width() {
	return sprite.get()->w;
}

/// @brief Retrieves the height of the sprite.                                  
///                                                                             
/// This function returns the height of the sprite texture.
///                                                                             
/// @return The height of the sprite texture.
int PenguinSprite::get_sprite_height() {
	return sprite.get()->h;
}

/// @brief Retrieves the internal SDL_Texture pointer.                          
///                                                                             
/// This function returns a pointer to the internal SDL_Texture representation.
///                                                                             
/// @return A pointer to the internal SDL_Texture.    
SDL_Texture* PenguinSprite::get_sprite_ptr() {
	return sprite.get();
}

/// @brief Draws the sprite to the screen at a specified position.               
///                                                                             
/// This function renders the sprite at the given position using the attached
/// renderer. If the sprite fails to render, an exception is thrown.            
///                                                                           
/// @param position: The position to draw the sprite on the screen.            
void PenguinSprite::draw_sprite(Rect2<float>position) {
	auto sdl_position = (SDL_FRect)position;
	Exception::throw_if(
		!SDL_RenderTexture(renderer.get_renderer(), sprite.get(), NULL, &sdl_position),
		"Failed to render the sprite to the screen.",
		RENDERER_ERROR
	);
}

/// @brief Draws a region of the sprite to the screen at a specified position.
///                                                                             
/// This function renders a specified region of the sprite to the given
/// position. If the sprite region fails to render, an exception is thrown.   
///                                                                             
/// @param clip_region: The region of the sprite to draw.                       
/// @param position: The position to draw the sprite region on the screen.     
void PenguinSprite::draw_sprite_region(Rect2<float> clip_region, Rect2<float>position) {
	auto sdl_clip_region = (SDL_FRect)clip_region;
	auto sdl_position = (SDL_FRect)position;
	Exception::throw_if(
		!SDL_RenderTexture(renderer.get_renderer(), sprite.get(), &sdl_clip_region, &sdl_position),
		"Failed to render the sprite region to the screen.",
		RENDERER_ERROR
	);
}