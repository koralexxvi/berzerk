#pragma once

#include "berzerk/point.hpp"

#define BULLET_LENGTH (7)

namespace Berzerk {

// Represents a fired bullet.
class Bullet {
  public:
	// The position of the bullet.
	Point pos;

	// The direction the bullet is travelling in.
	Point dir;

  private:
	// The speed of the bullet.
	std::uint8_t speed;

  public:
	// Constructs a new bullet.
	Bullet(const Point& pos, const Point& dir, std::uint8_t speed);

	// Steps this bullet forward in the simulation.
	void tick();

	// Draws this bullet to the screen.
	void draw() const;
};

}  // namespace Berzerk
