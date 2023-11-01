#include "render.h"
#include "res.h"

void render(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_Color textColor = {255, 255, 255, 255};

    // Create a text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Pixel Platformer", textColor);
    if (!textSurface) {
        fprintf(stderr, "TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return;
    }

    SDL_Rect textRect;
    textRect.x = 10;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    // Create a texture from the text surface
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        fprintf(stderr, "SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return;
    }

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);

    SDL_RenderPresent(renderer);
}
