#include "berzerk/bullet.hpp"

#include "berzerk/globals.hpp"

#include <SDL3/SDL_render.h>

Berzerk::Bullet::Bullet(
	const Point& pos,
	const Point& dir,
	SDL_Color colour,
	std::uint8_t length,
	std::uint8_t speed
)
	: pos(pos),
	  dir(dir),
	  colour(colour),
	  length(length),
	  speed(speed) {}

void Berzerk::Bullet::tick() {
	pos += dir * speed;
}

void Berzerk::Bullet::draw() const {
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderLine(
		renderer,
		static_cast<float>(pos.x),
		static_cast<float>(pos.y),
		static_cast<float>(pos.x + dir.x * length),
		static_cast<float>(pos.y + dir.y * length)
	);
}
