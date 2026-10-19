#pragma once

#define BERZERK_MAP_X (6)
#define BERZERK_MAP_Y (4)
#define BERZERK_WALL_LENGTH_X (48)
#define BERZERK_WALL_LENGTH_Y (64)
#define BERZERK_WALL_THICKNESS (2)

namespace Berzerk {

// Defines a cardinal direction.
enum class Direction : unsigned char {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

}  // namespace Berzerk
