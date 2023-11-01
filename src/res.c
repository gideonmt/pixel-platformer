#include "res.h"

TTF_Font *font = NULL;
SDL_Texture *backgroundTexture = NULL;
SDL_Texture *textTexture = NULL;

bool initResources(SDL_Renderer *renderer) {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load font
    font = TTF_OpenFont("res/font/vermin-vibes.ttf", 64);
    if (font == NULL) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load background texture
    backgroundTexture = IMG_LoadTexture(renderer, "res/image/sky.png");
    if (!backgroundTexture) {
        fprintf(stderr, "IMG_LoadTexture error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

void cleanUpResources() {
    if (font) {
        TTF_CloseFont(font);
        font = NULL;
    }

    if (backgroundTexture) {
        SDL_DestroyTexture(backgroundTexture);
        backgroundTexture = NULL;
    }

    if (textTexture) {
        SDL_DestroyTexture(textTexture);
        textTexture = NULL;
    }

    TTF_Quit();
}
