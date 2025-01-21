#ifndef VECTOR2_HPP
#define VECTOR2_HPP

// Used as a reference for constructing the Vector2 object used in the app: https://github.com/aardhyn/sdl3-template-project/tree/main

template<typename T = float>

struct Vector2 {

    static constexpr T ORIGIN = 0.0; // The origin for all Vector2 objects -> (0, 0)

    float x, y;

    Vector2(T p_x, T p_y) : x(p_x), y(p_y) {}
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