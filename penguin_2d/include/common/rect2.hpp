#ifndef RECT2_HPP
#define RECT2_HPP

#include "vector2.hpp"
#include <SDL3/SDL_rect.h>

#include <type_traits>

// Used as a reference for constructing the Rect2 object used in the app: https://github.com/aardhyn/sdl3-template-project/tree/main

template<typename T = float>

struct Rect2 final {

	Vector2<T> position;
	Vector2<T> size;

	Rect2(Vector2<T> position, Vector2<T> size) : position{ position }, size{ size } {}
	Rect2(Vector2<T> size) : position{ Vector2<T>(0, 0) }, size{ size } {}

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

	// Checking if a point exists in the Rect2
	inline bool contains_point(Vector2<T> point) const { return point < position + size && point > position; }

	// SDL representations of Rect2
	inline operator SDL_Rect() const {
		return SDL_Rect{ (int)position.x, (int)position.y, (int)size.x, (int)size.y };
	}

	inline operator SDL_FRect() const {
		return SDL_FRect{ (float)position.x, (float)position.y, (float)size.x, (float)size.y };
	}

	// Checking if two rectangles intersect
	inline bool has_intersection(const Rect2<T>& other_rect) const {
		if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {

			auto sdl_this_rect = (SDL_FRect)this;
			auto sdl_other_rect = (SDL_FRect)other_rect;

			return SDL_HasRectIntersectionFloat(&sdl_this_rect, &sdl_other_rect);
		}
		else {

			auto sdl_this_rect = (SDL_Rect)this;
			auto sdl_other_rect = (SDL_Rect)other_rect;

			// Use SDL_HasIntersection for integer rects
			return SDL_HasRectIntersection(&sdl_this_rect, &sdl_other_rect);
		}
	}


};

#endif // RECT2_HPP
