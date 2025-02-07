///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_text_renderer.cpp                                        ///
///                                                                             ///
/// This file implements the PenguinTextRenderer class, which is responsible	///
/// for rendering text using SDL_ttf.											///
///////////////////////////////////////////////////////////////////////////////////

#include "penguin_text_renderer.hpp"

using namespace Penguin2D;

/// @brief Constructs a text renderer for rendering text onto the screen.
/// 
/// This constructor initializes the text renderer using the provided renderer,
/// allowing text to be rendered onto the screen. If the text renderer cannot be initialized,
/// an exception is thrown.
/// 
/// @param renderer: The renderer connected to the main window, used to create the text renderer.
PenguinTextRenderer::PenguinTextRenderer(PenguinRenderer& renderer)
	: text_renderer(TTF_CreateRendererTextEngine(renderer.get_renderer()), &TTF_DestroyRendererTextEngine) {

	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);
}

/// @brief Retrieves the raw pointer of the text renderer.
/// 
/// This function returns the underlying SDL text engine used for text rendering.
/// If the text renderer has not been initialized, an exception is thrown.
/// 
/// @return TTF_TextEngine*: The raw pointer to the SDL text engine used for rendering text.
TTF_TextEngine* PenguinTextRenderer::get_text_renderer() {

	// Throw error if the text renderer has not been initialized.
	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);

	return text_renderer.get();
}