#include "render.h"

// Cached textures
static SDL_Texture *cachedBackgroundTexture = NULL;
static SDL_Texture *cachedTextTexture = NULL;

void render(SDL_Renderer *renderer, ResourceManager *resources, SDL_Color textColor)
{
    // Clear the renderer
    SDL_RenderClear(renderer);

    // Render the background texture (if not cached)
    if (!cachedBackgroundTexture)
    {
        cachedBackgroundTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load("res/image/sky.png"));
    }
    SDL_RenderCopy(renderer, cachedBackgroundTexture, NULL, NULL);

    if (!cachedTextTexture)
    {
        cachedTextTexture = getTextTexture(resources, renderer, "Pixel Platformer", textColor);
    }

    int textWidth, textHeight;
    SDL_QueryTexture(cachedTextTexture, NULL, NULL, &textWidth, &textHeight);

    int centerX = (864 - textWidth) / 2;
    int centerY = (555 - textHeight) / 2;

    SDL_Rect textRect;
    textRect.x = centerX;
    textRect.y = centerY;
    textRect.w = textWidth;
    textRect.h = textHeight;

    SDL_RenderCopy(renderer, cachedTextTexture, NULL, &textRect);

    SDL_RenderPresent(renderer);
}
