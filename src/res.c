#include "res.h"

bool initResources(ResourceManager *resources, SDL_Renderer *renderer) {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load font
    resources->font = TTF_OpenFont("res/font/vermin-vibes.ttf", 24);
    if (resources->font == NULL) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load background texture
    resources->backgroundTexture = IMG_LoadTexture(renderer, "res/image/sky.png");
    if (!resources->backgroundTexture) {
        fprintf(stderr, "IMG_LoadTexture error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

void cleanUpResources(ResourceManager *resources) {
    if (resources->font) {
        TTF_CloseFont(resources->font);
        resources->font = NULL;
    }

    if (resources->backgroundTexture) {
        SDL_DestroyTexture(resources->backgroundTexture);
        resources->backgroundTexture = NULL;
    }

    if (resources->textTexture) {
        SDL_DestroyTexture(resources->textTexture);
        resources->textTexture = NULL;
    }

    TTF_Quit();
}
