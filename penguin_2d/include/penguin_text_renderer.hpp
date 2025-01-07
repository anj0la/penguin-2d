#ifndef PENGUIN_TEXT_ENGINE_HPP
#define PENGUIN_TEXT_ENGINE_HPP

#include <memory>
#include <string>
#include "exception.hpp"
#include "penguin_renderer.hpp"

#include <SDL3_ttf/SDL_textengine.h>


namespace Penguin2D {

    class PenguinTextRenderer {
    public:
        PenguinTextRenderer(PenguinRenderer& p_renderer);
        TTF_TextEngine* get_text_renderer();

    private:
        std::unique_ptr<TTF_TextEngine, void(*)(TTF_TextEngine*)> text_renderer;
    };
}

#endif // PENGUIN_TEXT_ENGINE_HPP