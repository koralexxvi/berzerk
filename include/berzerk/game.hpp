#pragma once

#include "berzerk/player.hpp"

#include <vector>

namespace Berzerk {

// The players that are currently in the game.
extern std::vector<Player> players;

// Initialises the game.
void initGame();

// Steps the game forward in time by a frame.
void tick();

}  // namespace Berzerk
