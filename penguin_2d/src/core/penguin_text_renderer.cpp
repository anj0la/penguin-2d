/// File name: penguin_text_renderer.cpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinTextRenderer initializes the text renderer required for rendering text onto the screen.
/// 
/// This class should only be used when creating a PenguinText, by passing the text renderer as a parameter.
///
#include "penguin_text_renderer.hpp"

using namespace Penguin2D;

/// <summary>
/// Creates a text renderer for rendering text onto the screen. 
/// </summary>
/// <param name="p_renderer">- the renderer connected to the main window.</param>
PenguinTextRenderer::PenguinTextRenderer(PenguinRenderer& p_renderer)
	: text_renderer(TTF_CreateRendererTextEngine(p_renderer.get_renderer()), &TTF_DestroyRendererTextEngine) {

	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);
}

/// <summary>
/// Gets the raw pointer of the text renderer.
/// </summary>
/// <returns>TTF_TextEngine* - the underlying SDL text engine.</returns>
TTF_TextEngine* PenguinTextRenderer::get_text_renderer() {

	// Throw error if the text renderer has not been initialized.
	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);

	return text_renderer.get();
}