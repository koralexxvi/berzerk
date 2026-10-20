#include "berzerk/defs.hpp"
#include "berzerk/game.hpp"
#include "berzerk/globals.hpp"
#include "berzerk/map.hpp"
#include "berzerk/render.hpp"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <cstdint>

// clang-format off
#define SDL_MAIN_USE_CALLBACKS (1)
#include <SDL3/SDL_main.h>
// clang-format on

SDL_Renderer* Berzerk::renderer = nullptr;
SDL_Window* Berzerk::window = nullptr;

namespace {

std::uint64_t lastFrame = 0;

}

SDL_AppResult SDL_AppInit(void**, int, char*[]) {
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer(
			"Berzerk",
			RENDER_WIDTH * RENDER_SCALE,
			RENDER_HEIGHT * RENDER_SCALE,
			0,
			&Berzerk::window,
			&Berzerk::renderer
		))
	{
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_SetRenderLogicalPresentation(
		Berzerk::renderer,
		RENDER_WIDTH,
		RENDER_HEIGHT,
		SDL_LOGICAL_PRESENTATION_STRETCH
	);
	if (!SDL_SetRenderVSync(Berzerk::renderer, SDL_RENDERER_VSYNC_ADAPTIVE)) {
		if (!SDL_SetRenderVSync(Berzerk::renderer, 1)) {
			SDL_Log("Couldn't enable vsync: %s", SDL_GetError());
		}
	}
	Berzerk::initMap();
	Berzerk::recenterCamera();
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void*, SDL_Event* event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void*) {
	constexpr std::size_t frameInterval = 1'000'000'000 / BERZERK_FRAMERATE;
	std::uint64_t now = SDL_GetTicksNS();
	if (now - lastFrame >= frameInterval) {
		Berzerk::tick();
		lastFrame = now;
	}

	SDL_SetRenderDrawColor(Berzerk::renderer, 0, 0, 0, 255);
	SDL_RenderClear(Berzerk::renderer);
	Berzerk::drawWalls();
	SDL_RenderPresent(Berzerk::renderer);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void*, SDL_AppResult) {
	SDL_DestroyRenderer(Berzerk::renderer);
	SDL_DestroyWindow(Berzerk::window);
}
