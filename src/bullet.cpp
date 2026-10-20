#include "berzerk/bullet.hpp"

#include "berzerk/defs.hpp"
#include "berzerk/globals.hpp"
#include "berzerk/point.hpp"
#include "berzerk/render.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <vector>

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
	if (pos.x < 0 || pos.x >= (BERZERK_MAP_X - 1) * BERZERK_WALL_LENGTH_X) {
		dead = true;
	}
	if (pos.y < 0 || pos.y >= (BERZERK_MAP_Y - 1) * BERZERK_WALL_LENGTH_Y) {
		dead = true;
	}
}

void Berzerk::Bullet::draw() const {
	Point drawPos = pos + getCameraPos();
	std::vector<SDL_FPoint> points;
	points.reserve(length);
	for (std::uint8_t i = 0; i < length; i++) {
		Point p = drawPos + dir * i;
		points.push_back({static_cast<float>(p.x), static_cast<float>(p.y)});
	}
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderPoints(renderer, points.data(), length);
}
