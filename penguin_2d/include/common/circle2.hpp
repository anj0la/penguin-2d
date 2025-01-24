#ifndef CIRCLE2_HPP
#define CIRCLE2_HPP

#include "vector2.hpp"
#include <numbers>

template<typename T = float>

struct Circle2 final {

	Vector2<T> position;
	T radius;

	Circle2(Vector2<T> pos, T rad) : position(pos), radius(rad) {}

}

#endif // CIRCLE2_HPP
