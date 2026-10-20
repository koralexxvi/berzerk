#include "berzerk/player.hpp"

#include "berzerk/globals.hpp"
#include "berzerk/point.hpp"

#include <SDL3/SDL_render.h>

Berzerk::Player::Player(const Point& pos) : pos(pos) {}

void Berzerk::Player::tick() {
	if (moveTimer > 0) {
		moveTimer--;
		return;
	}
	std::uint8_t y = input & 0b00011;
	std::uint8_t x = (input >> 2) & 0b00011;
	if (y == 0b01) {
		pos.y--;
	} else if (y == 0b10) {
		pos.y++;
	}
	if (x == 0b01) {
		pos.x--;
	} else if (x == 0b10) {
		pos.x++;
	}
	moveTimer = 1;
}

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
