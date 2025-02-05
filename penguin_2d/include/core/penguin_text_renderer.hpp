/// File name: penguin_text_renderer.hpp
/// 
/// Author: Anjola Aina
/// 
/// PenguinTextRenderer initializes the text renderer required for rendering text onto the screen.
/// 
/// This class should only be used when creating a PenguinText, by passing the text renderer as a parameter (don't reference, pass by reference).
///

#ifndef PENGUIN_TEXT_ENGINE_HPP
#define PENGUIN_TEXT_ENGINE_HPP

// Penguin2D related include files
#include "penguin_renderer.hpp"
#include "exception.hpp"

// SDL related include files
#include <SDL3_ttf/SDL_textengine.h>

// C++ library files
#include <memory>
#include <string>

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