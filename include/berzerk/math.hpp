#pragma once

#include "berzerk/point.hpp"

#include <algorithm>
#include <cstdint>

namespace Berzerk {

// Represents a rectangle.
struct Rect {
	// The X position of the rectangle, centered on the left.
	std::int32_t x;

	// The Y position of the rectangle, centered on the top.
	std::int32_t y;

	// The width of the rectangle.
	std::int32_t w;

	// The height of the rectangle.
	std::int32_t h;
};

// Returns true if value is both greater or equal to min and less than or equal to max.
template<typename T> constexpr bool valueInRange(T value, T min, T max) noexcept {
	return value >= min && value <= max;
}

// Returns true if the given rect and point intersect.
constexpr bool rectIntersectsPoint(const Rect& rect, const Point& point) noexcept {
	return valueInRange(point.x, rect.x, rect.x + rect.w)
		&& valueInRange(point.y, rect.y, rect.y + rect.h);
}

// Returns true if the two rects intersect.
constexpr bool rectIntersectsRect(const Rect& a, const Rect& b) noexcept {
	return (valueInRange(a.x, b.x, b.x + b.w) || valueInRange(b.x, a.x, a.x + a.w))
		&& (valueInRange(a.y, b.y, b.y + b.h) || valueInRange(b.y, a.y, a.y + a.h));
}

// Returns the bounding box of a line.
constexpr Rect getLineBoundingBox(Point a, Point b) {
	std::int32_t minX = std::min(a.x, b.x);
	std::int32_t minY = std::min(a.y, b.y);
	std::int32_t maxX = std::max(a.x, b.x);
	std::int32_t maxY = std::max(a.y, b.y);
	return {minX, minY, maxX - minX, maxY - minY};
}

}  // namespace Berzerk
