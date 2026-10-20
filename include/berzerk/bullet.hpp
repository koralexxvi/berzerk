#pragma once

#include "berzerk/point.hpp"

#include <SDL3/SDL_pixels.h>

#define BERZERK_BULLET_LENGTH_PLAYER (7)
#define BERZERK_BULLET_LENGTH_ENEMY (4)
#define BERZERK_BULLET_SPEED_FAST (2)
#define BERZERK_BULLET_SPEED_SLOW (1)

namespace Berzerk {

// Represents a fired bullet.
class Bullet {
  public:
	// The position of the bullet.
	Point pos;

	// The direction the bullet is travelling in.
	Point dir;

  private:
	// The colour of the bullet.
	SDL_Color colour;

	// The length of the bullet.
	std::uint8_t length;

	// The speed of the bullet.
	std::uint8_t speed;

	// Whether or not the bullet is marked as dead (inactive).
	bool dead = false;

  public:
	// Constructs a new bullet.
	Bullet(
		const Point& pos,
		const Point& dir,
		SDL_Color colour,
		std::uint8_t length,
		std::uint8_t speed
	);

	// Steps this bullet forward in the simulation.
	void tick();

	// Draws this bullet to the screen.
	void draw() const;

	// Returns whether or not the bullet is marked as dead.
	constexpr bool isDead() const {
		return dead;
	}
};

}  // namespace Berzerk
