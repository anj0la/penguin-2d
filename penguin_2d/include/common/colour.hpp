#ifndef COLOUR_HPP
#define COLOUR_HPP

// Used as a reference for constructing the Colour object used in the app: https://github.com/aardhyn/sdl3-template-project/tree/main

///
/// Represents an RGBA colour.
///
struct Colour {
    static constexpr unsigned int OPAQUE = 255;
    static constexpr unsigned int TRANSPARENT = 0;

    // RGBA value
    unsigned int red = 0, green = 0, blue = 0, alpha = OPAQUE;

    // Constructors -> add more options to convert HEX to RGBA values
    constexpr Colour(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
        : red(r), green(g), blue(b), alpha(a) {
    }
};

namespace Colours {

    // Shades
    constexpr Colour WHITE{ 255, 255, 255, 255 };
    constexpr Colour GREY{ 128, 128, 128, 255 };
    constexpr Colour BLACK{ 0, 0, 0, 255 };
    constexpr Colour TRANSPARENT{ 0, 0, 0, 0 };

    // Primary Colours - will separate into colours (e.g., Reds, Blues, Purples)
    constexpr Colour RED{ 255, 0, 0, 255 };
    constexpr Colour GREEN{ 0, 255, 0, 255 };
    constexpr Colour BLUE{ 0, 0, 255, 255 };
    constexpr Colour YELLOW{ 255, 255, 0, 255 };
    constexpr Colour CYAN{ 0, 255, 255, 255 };
    constexpr Colour MAGENTA{ 255, 0, 255, 255 };

    // Other Colours
    constexpr Colour MAROON{ 128, 0, 0, 255 };
    constexpr Colour PURPLE{ 128, 0, 128, 255 };
    constexpr Colour TEAL{ 0, 128, 128, 255 };
    constexpr Colour NAVY{ 0, 0, 128, 255 };
}

#endif // COLOUR_HPP
