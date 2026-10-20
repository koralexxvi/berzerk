#pragma once

#include "berzerk/point.hpp"

#define BERZERK_PLAYER_W (8)
#define BERZERK_PLAYER_H (16)

namespace Berzerk {

// Represents a player in the game.
class Player {
  public:
	// The position of the player.
	Point pos;

	// The size of the player.
	Point size = {BERZERK_PLAYER_W, BERZERK_PLAYER_H};

	// The inputs of the player, in order up, down, left, right and fire.
	std::uint8_t input = 0;

  private:
	// How long until the player can move again.
	std::uint8_t moveTimer = 0;

  public:
	// Constructs a new player.
	Player(const Point& pos);

	// Steps this player forward in the simulation.
	void tick();

	// Draws this player.
	void draw() const;
};

}  // namespace Berzerk
