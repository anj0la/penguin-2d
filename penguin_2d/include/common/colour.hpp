///////////////////////////////////////////////////////////////////////////////////
/// File name: colour.hpp                                                       ///
///                                                                             ///
/// Defines the Colour struct and a collection of pre-defined Colours.          ///
///                                                                             ///
/// This file introduces the Colour struct, which represents an RGBA color,     ///
/// and a Colours namespace containing commonly used colors such as red, blue,  ///
/// green, white, black, and more.                                              ///
///                                                                             ///
/// Reference: https://github.com/aardhyn/sdl3-template-project/tree/main       ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef COLOUR_HPP
#define COLOUR_HPP

/// @brief Represents an RGBA color value.
///
/// This struct stores red, green, blue, and alpha (opacity) components 
/// as unsigned integers. It provides a constructor for defining colors and 
/// includes constants for fully opaque and fully transparent values.
struct Colour {
    static constexpr unsigned int OPAQUE = 255; /// Fully opaque alpha value.
    static constexpr unsigned int TRANSPARENT = 0; /// Fully transparent alpha value.

    unsigned int red = 0;   /// Red component (0-255).
    unsigned int green = 0; /// Green component (0-255).
    unsigned int blue = 0;  /// Blue component (0-255).
    unsigned int alpha = OPAQUE; /// Alpha (opacity) component (0-255).

    /// @brief Constructs a `Colour` with the specified RGBA values.
    /// @param r: Red component (0-255).
    /// @param g: Green component (0-255).
    /// @param b: Blue component (0-255).
    /// @param a: Alpha (opacity) component (0-255).
    constexpr Colour(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
        : red(r), green(g), blue(b), alpha(a) {
    }
};

/// @brief Provides a collection of predefined color constants.
///
/// This namespace defines commonly used colors as Colour objects. 
/// These colors can be used for rendering purposes in the framework.
namespace Colours {
    // Basic shades
    constexpr Colour WHITE{ 255, 255, 255, 255 };
    constexpr Colour GREY{ 128, 128, 128, 255 };
    constexpr Colour BLACK{ 0, 0, 0, 255 };
    constexpr Colour TRANSPARENT{ 0, 0, 0, 0 };

    // Primary colours
    constexpr Colour RED{ 255, 0, 0, 255 };
    constexpr Colour GREEN{ 0, 255, 0, 255 };
    constexpr Colour BLUE{ 0, 0, 255, 255 };
    constexpr Colour YELLOW{ 255, 255, 0, 255 };
    constexpr Colour CYAN{ 0, 255, 255, 255 };
    constexpr Colour MAGENTA{ 255, 0, 255, 255 };

    // Additional colors
    constexpr Colour MAROON{ 128, 0, 0, 255 };
    constexpr Colour PURPLE{ 128, 0, 128, 255 };
    constexpr Colour TEAL{ 0, 128, 128, 255 };
    constexpr Colour NAVY{ 0, 0, 128, 255 };
}

#endif // COLOUR_HPP
