#include <SDL.h>
#include "InputManager.h"
#include "backends/imgui_impl_sdl.h"

// If false means we want to close the game
bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...

		ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
