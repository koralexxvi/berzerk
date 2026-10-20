#include "berzerk/render.hpp"

#include "berzerk/defs.hpp"
#include "berzerk/game.hpp"
#include "berzerk/globals.hpp"
#include "berzerk/map.hpp"
#include "berzerk/point.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <array>

namespace {

Berzerk::Point cameraPos;

SDL_FRect getWallRectAt(std::size_t x, std::size_t y) {
	Berzerk::Direction direction = Berzerk::map[y][x];
	float rx = (static_cast<float>(x) * BERZERK_WALL_LENGTH_X);
	float ry = (static_cast<float>(y) * BERZERK_WALL_LENGTH_Y);
	float rw, rh;
	if (direction == Berzerk::Direction::NORTH || direction == Berzerk::Direction::SOUTH) {
		rw = BERZERK_WALL_THICKNESS;
		rh = BERZERK_WALL_LENGTH_Y;
	} else {
		rw = BERZERK_WALL_LENGTH_X;
		rh = BERZERK_WALL_THICKNESS;
	}
	if (direction == Berzerk::Direction::NORTH) {
		ry -= rh - BERZERK_WALL_THICKNESS;
	} else if (direction == Berzerk::Direction::WEST) {
		rx -= rw - BERZERK_WALL_THICKNESS;
	}
	return {rx + cameraPos.x, ry + cameraPos.y, rw, rh};
}

}  // namespace

Berzerk::Point Berzerk::getCameraPos() {
	return cameraPos;
}

void Berzerk::setCameraPos(const Point& pos) {
	cameraPos = pos;
}

void Berzerk::recenterCamera() {
	// clang-format off
	constexpr std::int32_t offsetX = (RENDER_WIDTH - (BERZERK_MAP_X * BERZERK_WALL_LENGTH_X)
		+ (BERZERK_WALL_LENGTH_X - BERZERK_WALL_THICKNESS))
		/ 2;
	constexpr std::int32_t offsetY = 0;
	// clang-format on
	cameraPos = {offsetX, offsetY};
}

void Berzerk::drawWalls() {
	std::size_t index = 0;
	std::array<SDL_FRect, BERZERK_MAP_X * BERZERK_MAP_Y> rects;
	for (std::size_t y = 0; y < BERZERK_MAP_Y; y++) {
		for (std::size_t x = 0; x < BERZERK_MAP_X; x++) {
			rects[index++] = getWallRectAt(x, y);
		}
	}
	SDL_SetRenderDrawColor(Berzerk::renderer, 0, 0, 255, 255);
	SDL_RenderFillRects(renderer, rects.data(), rects.size());
}

void Berzerk::drawObjects() {
	for (const auto& v : players) {
		v.draw();
	}
}
