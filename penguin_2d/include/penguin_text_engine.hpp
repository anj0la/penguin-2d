#ifndef PENGUIN_TEXT_ENGINE_HPP
#define PENGUIN_TEXT_ENGINE_HPP

#include <memory>
#include <string>
#include <SDL3_ttf/include/SDL3_ttf/SDL_textengine.h>
#include <SDL3_ttf/include/SDL3_ttf/SDL_ttf.h>
#include "exception.hpp"

namespace Penguin2D {

    struct FontStyle {
        bool bold = false;
        bool italic = false;
        bool underline = false;
        bool strike_through = false;
    };

    class PenguinTextEngine {
    public:
        PenguinTextEngine(const std::string$ p_font_path, int p_font_size, FontStyle p_font_style);
        ~PenguinTextEngine() = default;

        void set_style(FontStyle p_font_style);
        TTF_Font get_font() const;

    private:
        FontStyle font_style;
  
    };
}

#endif // PENGUIN_TEXT_ENGINE_HPP