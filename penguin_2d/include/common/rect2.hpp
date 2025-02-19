///////////////////////////////////////////////////////////////////////////////////
/// File name: rect2.hpp                                                        ///
///                                                                             ///
/// Defines the Rect2 struct, which represents a rectangle in 2D space.			///
///																				///
/// The Rect2 struct includes position and size attributes, represented as		///
/// Vector2 objects.															///
/// 																			///
/// It provides various operations, including intersection detection via		///
/// has_intersection().															///
///																				///
/// Reference: https://github.com/aardhyn/sdl3-template-project/tree/main       ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef RECT2_HPP
#define RECT2_HPP

// Penguin2D related include files
#include "vector2.hpp"

// SDL related include files
#include <SDL_rect.h>

// C++ library files
#include <type_traits>

/// @brief Represents a 2D rectangle with a position and size, defined by Vector2 objects.
///
/// This struct is used to represent a rectangle in 2D space. It stores
/// the rectangle's position (top-left corner) and its size (width and height),
/// both as Vector2 objects. This can be used for handling bounding boxes,
/// collision detection, and layout positioning.
template<typename T = float>
struct Rect2 final {

	Vector2<T> position; /// The position of the top-left corner of the rectangle.
	Vector2<T> size; /// The size (width and height) of the rectangle.

	/// @brief Constructs a Rect2 with specified position and size.
	/// @param position The position of the top-left corner.
	/// @param size The size of the rectangle.
	Rect2(Vector2<T> position, Vector2<T> size) : position{ position }, size{ size } {}

	/// @brief Constructs a Rect2 with a size and position set to the origin (0, 0).
	/// @param size The size of the rectangle.
	Rect2(Vector2<T> size) : position{ Vector2<T>(0, 0) }, size{ size } {}

	/// @brief Constructs a Rect2 with specified x, y position and x, y size.
	/// @param x_pos: The x position of the top-left corner.
	/// @param y_pos: The y position of the top-left corner.
	/// @param x_size: The width (x size) of the rectangle.
	/// @param y_size: The height (y size) of the rectangle.
	Rect2(T x_pos, T y_pos, T x_size, T y_size) : position{ Vector2<T>(x_pos, y_pos) }, size{ Vector2<T>(x_size, y_size) } {}

	/// @brief Constructs a `Rect2` with specified width and height, position set to the origin.
	/// @param x_size: The width (x size) of the rectangle.
	/// @param y_size: The height (y size) of the rectangle.
	Rect2(T x_size, T y_size) : position{ Vector2<T>(0, 0) }, size{ Vector2<T>(x_size, y_size) } {}

	// Equality operators

	inline bool operator==(const Rect2<T>& other_rect) const { return position == other_rect.position && size == other_rect.size; }
	inline bool operator!=(const Rect2<T>& other_rect) const { return *this != other_rect; }

	// Addition & subtraction operators (returns new Rect)

	inline Rect2<T> operator+(const Vector2<T>& other_vect) const { return Rect2<T>{ position + other_vect, size }; }
	inline Rect2<T> operator-(const Vector2<T>& other_vect) const { return Rect2<T>{ position - other_vect, size }; }

	// Addition & subtraction operators (modifies original Rect)

	inline Rect2<T>& operator+=(const Vector2<T>& other_vect) {
		position += other_vect;
		return *this;
	}
	inline Rect2<T>& operator-=(const Vector2<T>& other_vect) {
		position -= other_vect;
		return *this;
	}

	// SDL representations of Rect2

	inline operator SDL_Rect() const {
		return SDL_Rect{ (int)position.x, (int)position.y, (int)size.x, (int)size.y };
	}
	inline operator SDL_FRect() const {
		return SDL_FRect{ (float)position.x, (float)position.y, (float)size.x, (float)size.y };
	}

	/// @brief Checks if two rectangles intersect.
	/// @param other_rect: The other rectangle to check for an intersection.
	inline bool has_intersection(const Rect2<T>& other_rect) const {
		if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
			SDL_FRect sdl_this_rect = { static_cast<float>(this->position.x), static_cast<float>(this->position.y), static_cast<float>(this->size.x), static_cast<float>(this->size.y) };
			SDL_FRect sdl_other_rect = { static_cast<float>(other_rect.position.x), static_cast<float>(other_rect.position.y), static_cast<float>(other_rect.size.x), static_cast<float>(other_rect.size.y) };

			return SDL_HasRectIntersectionFloat(&sdl_this_rect, &sdl_other_rect);
		}
		else {
			SDL_Rect sdl_this_rect = { static_cast<int>(this->position.x), static_cast<int>(this->position.y), static_cast<int>(this->size.x), static_cast<int>(this->size.y) };
			SDL_Rect sdl_other_rect = { static_cast<int>(other_rect.position.x), static_cast<int>(other_rect.position.y), static_cast<int>(other_rect.size.x), static_cast<int>(other_rect.size.y) };

			// Use SDL_HasIntersection for integer rects
			return SDL_HasRectIntersection(&sdl_this_rect, &sdl_other_rect);
		}
	}

	/// @brief Checks if a point exists in the rectangle.
	/// @return True if the point is within the rectangle, false otherwise.
	inline bool contains_point(Vector2<T> point) const { return point < position + size && point > position; }
};

#endif // RECT2_HPP
