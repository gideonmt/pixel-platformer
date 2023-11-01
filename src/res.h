#ifndef RES_H
#define RES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>

extern TTF_Font *font;
extern SDL_Texture *backgroundTexture;
extern SDL_Texture *textTexture;

bool initResources(SDL_Renderer *renderer);
void cleanUpResources();

#endif // RES_H
