///////////////////////////////////////////////////////////////////////////////////
/// File name: penguin_text_renderer.hpp                                        ///
///                                                                             ///
/// Defines the PenguinTextRenderer class, which initializes the text renderer  ///
/// required for rendering text onto the screen.                                ///
///                                                                             ///
/// This class should only be used when creating a PenguinText, by passing the  ///
/// text renderer as a parameter (don't reference, pass by reference).          ///
///////////////////////////////////////////////////////////////////////////////////

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

    /// @brief A class responsible for handling text rendering operations.
    ///
    /// This class provides functionality for rendering text to the screen using a text engine (e.g., SDL_ttf).
    /// It manages the underlying text renderer and allows you to interact with it for creating and displaying text.
    class PenguinTextRenderer {
    public:
        /// @brief Constructs a PenguinTextRenderer with the given renderer.
        /// @param renderer: The PenguinRenderer that this text renderer will be associated with.
        PenguinTextRenderer(PenguinRenderer& renderer);

        /// @brief Retrieves the underlying text renderer engine.
        /// @return A pointer to the TTF_TextEngine used for rendering text.
        TTF_TextEngine* get_text_renderer();
    private:
        std::unique_ptr<TTF_TextEngine, void(*)(TTF_TextEngine*)> text_renderer; 
    };
}

#endif // PENGUIN_TEXT_ENGINE_HPP