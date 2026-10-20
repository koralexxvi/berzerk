#pragma once

#include "berzerk/math.hpp"
#include "berzerk/point.hpp"

#define BERZERK_ENEMY_W (8)
#define BERZERK_ENEMY_H (12)

namespace Berzerk {

class Enemy {
  public:
	// The hitbox of the enemy.
	Rect hitbox;

  private:
	// The direction the enemy is facing in.
	Point dir;

  public:
	// Constructs a new enemy.
	Enemy(const Point& pos);

	// Steps the enemy forward in time.
	void tick();

	// Draws the enemy to the screen.
	void draw() const;
};

}  // namespace Berzerk
