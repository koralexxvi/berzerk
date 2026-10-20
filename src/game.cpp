#include "berzerk/game.hpp"

#include "berzerk/player.hpp"

#include <vector>

std::vector<Berzerk::Player> Berzerk::players = {};

void Berzerk::initGame() {
	players.clear();
	players.push_back(Player({0, 0}));
}

void Berzerk::tick() {
	for (auto&& v : players) {
		v.tick();
	}
}
