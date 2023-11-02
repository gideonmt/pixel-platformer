#include "res.h"

bool initResources(ResourceManager *resources, SDL_Renderer *renderer) {
    printf("Initializing resources...\n");
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Load font
    resources->hfont = TTF_OpenFont("res/font/vermin-vibes.ttf", 64);
    if (resources->hfont == NULL) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    resources->pfont = TTF_OpenFont("res/font/pfont.ttf", 36);
    if (resources->pfont == NULL) {
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
    if (resources->hfont) {
        TTF_CloseFont(resources->hfont);
        resources->hfont = NULL;
    }
    
    if (resources->pfont) {
        TTF_CloseFont(resources->pfont);
        resources->pfont = NULL;
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
    // hfont
    SDL_Surface *hTextSurface = TTF_RenderText_Solid(resources->hfont, text, textColor);
    if (!hTextSurface) {
        fprintf(stderr, "TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture *hTextTexture = SDL_CreateTextureFromSurface(renderer, hTextSurface);
    SDL_FreeSurface(hTextSurface);

    // pfont
    SDL_Surface *pTextSurface = TTF_RenderText_Solid(resources->pfont, text, textColor);
    if (!pTextSurface) {
        fprintf(stderr, "TTF_RenderText_Solid error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture *pTextTexture = SDL_CreateTextureFromSurface(renderer, pTextSurface);
    SDL_FreeSurface(pTextSurface);

    return hTextTexture; return pTextTexture;
}