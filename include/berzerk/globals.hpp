#pragma once

#include "berzerk/defs.hpp"

#include <SDL3/SDL_render.h>
#include <array>

namespace Berzerk {

// A pointer to the game's renderer.
extern SDL_Renderer* renderer;

// A pointer to the game's window.
extern SDL_Window* window;

extern std::array<std::array<Direction, BERZERK_MAP_Y>, BERZERK_MAP_X> map;

}  // namespace Berzerk
