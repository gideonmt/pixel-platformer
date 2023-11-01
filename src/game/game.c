#include "game.h"
#include <SDL.h>

Game* Game_Create(SDL_Renderer* renderer) {
    Game* game = (Game*)malloc(sizeof(Game));
    if (!game) {
        return NULL;
    }

    game->renderer = renderer;
    game->startButtonTexture = NULL;

    const char* basePath = SDL_GetBasePath();
    if (!basePath) {
        free(game);
        return NULL;
    }

    return game;
}

void Game_Destroy(Game* game) {
    if (game) {
        // Clean up game-related resources here
        free(game);
    }
}

void Game_Update(Game* game) {
    // Update game logic, handle input, physics, collisions, etc.
}

void Game_Render(Game* game) {
    SDL_Renderer* renderer = game->renderer;
    
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
