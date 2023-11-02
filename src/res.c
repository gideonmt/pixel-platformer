#include "res.h"

bool initResources(ResourceManager *resources, SDL_Renderer *renderer) {
    printf("Initializing resources...\n");
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load font
    resources->font = TTF_OpenFont("res/font/vermin-vibes.ttf", 64);
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
    printf("Cleaning up resources...\n");
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

SDL_Texture *loadImageTexture(SDL_Renderer *renderer, const char *path) {
    SDL_Surface *surface = IMG_Load(path);
    if (!surface) {
        fprintf(stderr, "IMG_Load error: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

SDL_Texture *getTextTexture(ResourceManager *resources, SDL_Renderer *renderer, const char *text, SDL_Color textColor) {
    SDL_Surface *textSurface = TTF_RenderText_Solid(resources->font, text, textColor);
    if (!textSurface) {
        fprintf(stderr, "TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return textTexture;
}
