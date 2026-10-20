#pragma once

#include <cstddef>

namespace Berzerk {

// A point composed of two integral components.
struct Point {
	// The X component of this point.
	std::size_t x;

	// The Y component of this point.
	std::size_t y;

	// Constructs a vector with an X and Y value of 0.
	constexpr Point() noexcept : x(0), y(0) {}

	// Constructs a vector with the provided components.
	constexpr Point(std::size_t x, std::size_t y) noexcept : x(x), y(y) {}

	// Returns this point.
	constexpr Point operator+() const noexcept {
		return *this;
	}

	// Returns the unary negation of this point.
	constexpr Point operator-() const noexcept {
		return {-x, -y};
	}

	// Returns the bitwise negation of this point.
	constexpr Point operator~() const noexcept {
		return {~x, ~y};
	}

	// Adds the components of the two points together.
	constexpr Point operator+(const Point& other) const noexcept {
		return {x + other.x, y + other.y};
	}

	// Subtracts the components of this point from the other.
	constexpr Point operator-(const Point& other) const noexcept {
		return {x - other.x, y - other.y};
	}

	// Multiplies the components of this point by a scalar.
	constexpr Point operator*(std::size_t scale) const noexcept {
		return {x * scale, y * scale};
	}

	// Multiplies the components of the two points together.
	constexpr Point operator*(const Point& other) const noexcept {
		return {x * other.x, y * other.y};
	}

	// Divides the components of this point by a scalar.
	constexpr Point operator/(std::size_t scale) const noexcept {
		return {x / scale, y / scale};
	}

	// Divides the components of this point by the other.
	constexpr Point operator/(const Point& other) const noexcept {
		return {x / other.x, y / other.y};
	}

	// Returns the bitwise and of the two points together.
	constexpr Point operator&(const Point& other) const noexcept {
		return {x & other.x, y & other.y};
	}

	// Returns the bitwise or of the two points together.
	constexpr Point operator|(const Point& other) const noexcept {
		return {x | other.x, y | other.y};
	}

	// Returns this point shifted left by scale bits.
	constexpr Point operator<<(std::size_t scale) const noexcept {
		return {x << scale, y << scale};
	}

	// Returns this point's components shifted left by eachother.
	constexpr Point operator<<(const Point& other) const noexcept {
		return {x << other.x, y << other.y};
	}

	// Returns this point shifted right by scale bits.
	constexpr Point operator>>(std::size_t scale) const noexcept {
		return {x >> scale, y >> scale};
	}

	// Returns this point's components shifted right by eachother.
	constexpr Point operator>>(const Point& other) const noexcept {
		return {x >> other.x, y >> other.y};
	}

	// Adds the components of the two points together.
	constexpr Point operator+=(const Point& other) noexcept {
		x += other.x;
		y += other.y;
		return *this;
	}

	// Subtracts the components of this point from the other.
	constexpr Point operator-=(const Point& other) noexcept {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// Multiplies the components of this point by a scalar.
	constexpr Point operator*=(std::size_t scale) noexcept {
		x *= scale;
		y *= scale;
		return *this;
	}

	// Multiplies the components of the two points together.
	constexpr Point operator*=(const Point& other) noexcept {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	// Divides the components of this point by a scalar.
	constexpr Point operator/=(std::size_t scale) noexcept {
		x /= scale;
		y /= scale;
		return *this;
	}

	// Divides the components of this point by the other.
	constexpr Point operator/=(const Point& other) noexcept {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	// Performs a bitwise and on the two points.
	constexpr Point operator&=(const Point& other) noexcept {
		x &= other.x;
		y &= other.y;
		return *this;
	}

	// Performs a bitwise and on the two points.
	constexpr Point operator|=(const Point& other) noexcept {
		x |= other.x;
		y |= other.y;
		return *this;
	}

	// Performs a left shift on the components of this point with a scalar.
	constexpr Point operator<<=(std::size_t scale) noexcept {
		x <<= scale;
		y <<= scale;
		return *this;
	}

	// Performs a left shift on the components of the two points.
	constexpr Point operator<<=(const Point& other) noexcept {
		x <<= other.x;
		y <<= other.y;
		return *this;
	}

	// Performs a right shift on the components of this point with a scalar.
	constexpr Point operator>>=(std::size_t scale) noexcept {
		x >>= scale;
		y >>= scale;
		return *this;
	}

	// Performs a left shift on the components of the two points.
	constexpr Point operator>>=(const Point& other) noexcept {
		x >>= other.x;
		y >>= other.y;
		return *this;
	}

	// Compares the two points, returning true if both components are equal.
	constexpr bool operator==(const Point& other) const noexcept {
		return x == other.x && y == other.y;
	}

	// Compares the two points, returning false if both components are equal.
	constexpr bool operator!=(const Point& other) const noexcept {
		return !(*this == other);
	}
};

}  // namespace Berzerk
