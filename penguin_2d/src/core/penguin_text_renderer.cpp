#include "penguin_text_renderer.hpp"

using namespace Penguin2D;

PenguinTextRenderer::PenguinTextRenderer(PenguinRenderer& p_renderer)
	: text_renderer(TTF_CreateRendererTextEngine(p_renderer.get_renderer()), &TTF_DestroyRendererTextEngine) {

	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);
}

TTF_TextEngine* PenguinTextRenderer::get_text_renderer() {

	// Throw error if the text renderer has not been initialized.
	Exception::throw_if(!text_renderer, "The text renderer could not be initalized.", RENDERER_ERROR);

	return text_renderer.get();
}