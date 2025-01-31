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
	Rect2(T x_pos, T y_pos, T x_size, T y_size) : position{ Vector2<T>(x_pos, y_pos) }, size{ Vector2<T>(x_size, y_size) } {}
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

};

#endif // RECT2_HPP
