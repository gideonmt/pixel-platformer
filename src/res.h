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
SDL_Texture *loadImageTexture(SDL_Renderer *renderer, const char *path);
SDL_Texture *getTextTexture(ResourceManager *resources, SDL_Renderer *renderer, const char *text, SDL_Color textColor);

#endif // RES_H
