#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>
#include "res.h"

void render(SDL_Renderer *renderer, ResourceManager *resources, SDL_Color textColor);

#endif // RENDER_H
