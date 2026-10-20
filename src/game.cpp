#include "berzerk/game.hpp"

#include "berzerk/bullet.hpp"
#include "berzerk/player.hpp"

#include <vector>

std::vector<Berzerk::Player> Berzerk::players = {};
std::vector<Berzerk::Bullet> Berzerk::bullets = {};

void Berzerk::initGame() {
	bullets.clear();
	players.clear();
	players.push_back(Player({0, 0}));
}

void Berzerk::tick() {
	for (auto&& v : players) {
		v.tick();
	}
	for (auto&& v : bullets) {
		v.tick();
	}
}
