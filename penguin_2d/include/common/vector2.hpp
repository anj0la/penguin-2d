///////////////////////////////////////////////////////////////////////////////////
/// File name: vector2.hpp                                                      ///
///                                                                             ///
/// Defines the Vector2 struct, which represents a 2D vector with x and y       ///
/// coordinates.                                                                ///
///                                                                             ///
/// The Vector2 struct provides arithmetic operations, comparison operators,    ///
/// and scalar operations, allowing for flexible mathematical computations.     ///
///                                                                             ///
/// It supports type conversion between int, float, and double representations. ///
///                                                                             ///
/// Reference: https://github.com/aardhyn/sdl3-template-project/tree/main       ///
///////////////////////////////////////////////////////////////////////////////////

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

/// @brief Represents a 2D vector with x and y components.
///
/// This struct is used to store and manipulate 2D vectors,
/// commonly used for positions, velocities, or directions in 2D space.
/// It supports basic vector operations like addition, subtraction, and scaling.
template<typename T = float>
struct Vector2 {

    static constexpr T ORIGIN = 0.0; /// The origin for all Vector2 objects -> (0, 0)

    T x; /// The x component of the vector.
    T y; /// The y component of the vector.

    /// @brief Constructs a Vector2 with specified x and y components.
    /// @param x_pos: The x component of the vector.
    /// @param y_pos: The y component of the vector.
    Vector2(T x_pos, T y_pos) : x(x_pos), y(y_pos) {}

    /// @brief Constructs a Vector2 at the origin (0, 0).
    Vector2() : x{ ORIGIN }, y{ ORIGIN } {}

    // Returning new Vector2

    inline Vector2<T> operator+(const Vector2<T>& other_vect) const { return Vector2<T>(x + other_vect.x, y + other_vect.y); }
    inline Vector2<T> operator-(const Vector2<T>& other_vect) const { return Vector2<T>(x - other_vect.x, y - other_vect.y); }
    inline Vector2<T> operator*(const Vector2<T>& other_vect) const { return Vector2<T>(x * other_vect.x, y * other_vect.y); }
    inline Vector2<T> operator/(const Vector2<T>& other_vect) const { return Vector2<T>(x / other_vect.x, y / other_vect.y); }

    // Modifying original Vector2

    inline Vector2<T>& operator+=(const Vector2<T>& other_vect) {
        x += other_vect.x;
        y += other_vect.y;
        return *this;
    }
    inline Vector2<T>& operator-=(const Vector2<T>& other_vect) {
        x -= other_vect.x;
        y -= other_vect.y;
        return *this;
    }
    inline Vector2<T>& operator*=(const Vector2<T>& other_vect) {
        x *= other_vect.x;
        y *= other_vect.y;
        return *this;
    }
    inline Vector2<T>& operator/=(const Vector2<T>& other_vect) {
        x /= other_vect.x;
        y /= other_vect.y;
        return *this;
    }

    // Scalar operations (returning new Vector2)

    inline Vector2<T> operator+(const T scalar_val) const {
        return Vector2<T>(x + scalar_val, y + scalar_val);
    }
    inline Vector2<T> operator-(const T scalar_val) const {
        return Vector2<T>(x - scalar_val, y - scalar_val);
    }
    inline Vector2<T> operator*(const T scalar_val) const {
        return Vector2<T>(x * scalar_val, y * scalar_val);
    }
    inline Vector2<T> operator/(const T scalar_val) const {
        return Vector2<T>(x / scalar_val, y / scalar_val);
    }

    // Scalar operations (modifying original Vector2)

    inline Vector2<T>& operator+=(const T scalar_val) {
        x += scalar_val;
        y += scalar_val;
        return *this;
    }
    inline Vector2<T>& operator-=(const T scalar_val) {
        x -= scalar_val;
        y -= scalar_val;
        return *this;
    }
    inline Vector2<T>& operator*=(const T scalar_val) {
        x *= scalar_val;
        y *= scalar_val;
        return *this;
    }
    inline Vector2<T>& operator/=(const T scalar_val) {
        x /= scalar_val;
        y /= scalar_val;
        return *this;
    }

    // Comparision operators

    inline bool operator==(const Vector2<T>& other_vect) const { return x == other_vect.x && y == other_vect.y; }
    inline bool operator!=(const Vector2<T>& other_vect) const { return x != other_vect.x || y != other_vect.y; }
    inline bool operator<(const Vector2<T>& other_vect) const { return x < other_vect.x && y < other_vect.y; }
    inline bool operator>(const Vector2<T>& other_vect) const { return x > other_vect.x && y > other_vect.y; }
    inline bool operator<=(const Vector2<T>& other_vect) const { return x <= other_vect.x && y <= other_vect.y; }
    inline bool operator>=(const Vector2<T>& other_vect) const { return x >= other_vect.x && y >= other_vect.y; }
    inline bool operator!() const { return x == ORIGIN && y == ORIGIN; } // Checks if vector is at the origin (0, 0)

    // Declaring Vector2 types (int, float, double)

    inline operator Vector2<int>() const { return { (int)x, (int)y }; }
    inline operator Vector2<float>() const { return { (float)x, (float)y }; }
    inline operator Vector2<double>() const { return { (double)x, (double)y }; }
};

#endif // VECTOR2_HPP