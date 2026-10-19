#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>

// clang-format off
#define SDL_MAIN_USE_CALLBACKS (1)
#include <SDL3/SDL_main.h>
// clang-format on

#include <berzerk/globals.hpp>

#define RENDER_WIDTH (400)
#define RENDER_HEIGHT (300)
#define RENDER_SCALE (2)

SDL_Renderer* Berzerk::renderer = nullptr;
SDL_Window* Berzerk::window = nullptr;

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
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void*, SDL_Event* event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void*) {
	SDL_SetRenderDrawColor(Berzerk::renderer, 0, 0, 0, 255);
	SDL_RenderClear(Berzerk::renderer);
	SDL_RenderPresent(Berzerk::renderer);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void*, SDL_AppResult) {
	SDL_DestroyRenderer(Berzerk::renderer);
	SDL_DestroyWindow(Berzerk::window);
}
