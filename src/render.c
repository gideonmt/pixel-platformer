#include "render.h"

void render(SDL_Renderer *renderer, ResourceManager *resources) {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, resources->backgroundTexture, NULL, NULL);

    SDL_Color textColor = { 255, 255, 255, 255 };

    SDL_Surface *textSurface = TTF_RenderText_Solid(resources->font, "Pixel Platformer", textColor);
    if (!textSurface) {
        fprintf(stderr, "TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return;
    }

    resources->textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!resources->textTexture) {
        fprintf(stderr, "SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return;
    }

    int centerX = (800 - textSurface->w) / 2;
    int centerY = (600 - textSurface->h) / 2;

    SDL_Rect textRect;
    textRect.x = centerX;
    textRect.y = centerY;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    SDL_RenderCopy(renderer, resources->textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);

    SDL_RenderPresent(renderer);
}
