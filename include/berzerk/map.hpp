#pragma once

#include "berzerk/defs.hpp"

#include <array>

namespace Berzerk {

extern std::array<std::array<Direction, BERZERK_MAP_X>, BERZERK_MAP_Y> map;

void initMap();

}  // namespace Berzerk
