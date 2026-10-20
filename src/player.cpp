#include "berzerk/player.hpp"

#include "berzerk/globals.hpp"
#include "berzerk/point.hpp"

#include <SDL3/SDL_render.h>

Berzerk::Player::Player(const Point& pos) : pos(pos) {}

void Berzerk::Player::tick() {}

void Berzerk::Player::draw() const {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_FRect drawRect = {
		static_cast<float>(pos.x),
		static_cast<float>(pos.y),
		static_cast<float>(size.x),
		static_cast<float>(size.y)
	};
	SDL_RenderFillRect(renderer, &drawRect);
}
