#include "berzerk/enemy.hpp"

#include "berzerk/globals.hpp"
#include "berzerk/point.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

Berzerk::Enemy::Enemy(const Point& pos)
	: hitbox({pos.x, pos.y, BERZERK_ENEMY_W, BERZERK_ENEMY_H}) {}

void Berzerk::Enemy::tick() {}

void Berzerk::Enemy::draw() const {
	SDL_FRect drawRect = {
		static_cast<float>(hitbox.x),
		static_cast<float>(hitbox.y),
		static_cast<float>(hitbox.w),
		static_cast<float>(hitbox.h)
	};
	SDL_RenderFillRect(Berzerk::renderer, &drawRect);
}
