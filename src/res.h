#ifndef RES_H
#define RES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>

typedef struct {
    TTF_Font *font;
    SDL_Texture *backgroundTexture;
    SDL_Texture *textTexture;
} ResourceManager;

bool initResources(ResourceManager *resources, SDL_Renderer *renderer);
void cleanUpResources(ResourceManager *resources);

#endif // RES_H
