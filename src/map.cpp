#include "berzerk/map.hpp"

#include "berzerk/defs.hpp"

#include <array>

std::array<std::array<Berzerk::Direction, BERZERK_MAP_X>, BERZERK_MAP_Y> Berzerk::map = {};

void Berzerk::initMap() {
	using enum Berzerk::Direction;
	using Row = std::array<Berzerk::Direction, BERZERK_MAP_X>;
	Berzerk::map = {{
		Row{SOUTH, WEST, WEST, EAST, EAST, SOUTH},
		Row{NORTH, NORTH, NORTH, NORTH, NORTH, NORTH},
		Row{SOUTH, NORTH, NORTH, NORTH, NORTH, SOUTH},
		Row{NORTH, WEST, WEST, EAST, EAST, NORTH},
	}};
	int i = 0;
	for (std::size_t y = 1; y < BERZERK_MAP_Y - 1; y++) {
		for (std::size_t x = 1; x < BERZERK_MAP_X - 1; x++) {
			Berzerk::map[y][x] = static_cast<Berzerk::Direction>(i++ % 4);
		}
	}
}
