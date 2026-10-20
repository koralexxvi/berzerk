#include "berzerk/player.hpp"

#include "berzerk/bullet.hpp"
#include "berzerk/game.hpp"
#include "berzerk/globals.hpp"
#include "berzerk/point.hpp"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <stdexcept>

Berzerk::Player::Player(const Point& pos) : pos(pos) {}

void Berzerk::Player::tick() {
	if (moveTimer > 0) {
		moveTimer--;
		return;
	}
	std::uint8_t y = input & 0b00011;
	std::uint8_t x = (input >> 2) & 0b00011;
	Point dir;
	if (y == 0b01) {
		dir.y = -1;
	} else if (y == 0b10) {
		dir.y = 1;
	}
	if (x == 0b01) {
		dir.x = -1;
	} else if (x == 0b10) {
		dir.x = 1;
	}

	if ((input & 0b10000) && input != 0b10000) {
		Point shootOffset;
		std::uint8_t shootInput = input;
		// up+down?
		if (shootInput & 0b00011) {
			shootInput ^= 0b00011;
		}
		// left+right?
		if (shootInput & 0b01100) {
			shootInput ^= 0b01100;
		}
		// no inputs left?
		if (shootInput == 0b10000) {
			return;
		}
		switch (shootInput) {
			// north
			case 0b10001: shootOffset = {6, 0}; break;
			// north east
			case 0b11001: shootOffset = {6, 2}; break;
			// east
			case 0b11000: shootOffset = {8, 4}; break;
			// south east
			case 0b11010: shootOffset = {6, 6}; break;
			// south
			case 0b10010: shootOffset = {6, 8}; break;
			// south west
			case 0b10110: shootOffset = {2, 4}; break;
			// west
			case 0b10100: shootOffset = {0, 4}; break;
			// north west
			case 0b10101: shootOffset = {2, 4}; break;
			default: throw std::invalid_argument("invalid input (unreachable\?\?)");
		}
		moveTimer = 10;
		bullets.push_back(Bullet(
			pos + shootOffset,
			dir,
			{255, 64, 64, 255},
			BERZERK_BULLET_LENGTH_PLAYER,
			BERZERK_BULLET_SPEED_FAST
		));
		return;
	}

	pos += dir;
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
