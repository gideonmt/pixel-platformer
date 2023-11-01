#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "/opt/homebrew/Cellar/sdl2_image/2.6.3_2/include/SDL2/SDL_image.h"

typedef struct {
    SDL_Renderer* renderer;
    SDL_Texture* startButtonTexture;
} Game;

Game* Game_Create(SDL_Renderer* renderer);
void Game_Destroy(Game* game);
void Game_Update(Game* game);
void Game_Render(Game* game);

#endif
