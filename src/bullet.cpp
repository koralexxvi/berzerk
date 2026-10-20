#include "berzerk/bullet.hpp"

#include "berzerk/globals.hpp"

#include <SDL3/SDL_render.h>

Berzerk::Bullet::Bullet(const Point& pos, const Point& dir, std::uint8_t speed)
	: pos(pos),
	  dir(dir),
	  speed(speed) {}

void Berzerk::Bullet::tick() {
	pos += dir * speed;
}

void Berzerk::Bullet::draw() const {
	SDL_RenderLine(
		renderer,
		static_cast<float>(pos.x),
		static_cast<float>(pos.y),
		static_cast<float>(pos.x + dir.x * speed),
		static_cast<float>(pos.y + dir.y * speed)
	);
}
