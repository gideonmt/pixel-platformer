#include "menu.h"

int quit = 0;

void startAction(void)
{
    
}

void infoAction(void)
{

}

void exitAction(void)
{
    quit = 1;
}

Button startButton = {"Start", 402, 320, 80, 20, SELECTED, startAction};
Button infoButton = {"Info", 402, 360, 80, 20, UNSELECTED, infoAction};
Button exitButton = {"Exit", 402, 400, 80, 20, UNSELECTED, exitAction};

TTF_Font *menuFont = NULL;
SDL_Renderer *menuRenderer = NULL;

void initMenu(SDL_Renderer *renderer, TTF_Font *pfont)
{
    menuRenderer = renderer;
    menuFont = pfont;
}

void handleMenuEvents(SDL_Event *e)
{
    if (e->type == SDL_KEYDOWN)
    {
        if (e->key.keysym.sym == SDLK_UP)
        {
            if (startButton.state == SELECTED)
            {
                startButton.state = UNSELECTED;
                exitButton.state = SELECTED;
            }
            else if (infoButton.state == SELECTED)
            {
                infoButton.state = UNSELECTED;
                startButton.state = SELECTED;
            }
            else if (exitButton.state == SELECTED)
            {
                exitButton.state = UNSELECTED;
                infoButton.state = SELECTED;
            }
        }
        else if (e->key.keysym.sym == SDLK_DOWN)
        {
            if (startButton.state == SELECTED)
            {
                startButton.state = UNSELECTED;
                infoButton.state = SELECTED;
            }
            else if (infoButton.state == SELECTED)
            {
                infoButton.state = UNSELECTED;
                exitButton.state = SELECTED;
            }
            else if (exitButton.state == SELECTED)
            {
                exitButton.state = UNSELECTED;
                startButton.state = SELECTED;
            }
        }
        else if (e->key.keysym.sym == SDLK_RETURN)
        {
            if (startButton.state == SELECTED)
            {
                startButton.action();
            }
            else if (infoButton.state == SELECTED)
            {
                infoButton.action();
            }
            else if (exitButton.state == SELECTED)
            {
                exitButton.action();
            }
        }
    }
}

void drawButton(Button *button)
{
    SDL_Rect textRect = {button->x, button->y, button->width, button->height};
    SDL_Color textColor = {255, 255, 255};
    SDL_Color selectedTextColor = {30, 60, 160};

    SDL_Color renderColor = (button->state == SELECTED) ? selectedTextColor : textColor;

    SDL_Surface *textSurface = TTF_RenderText_Solid(menuFont, button->text, renderColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(menuRenderer, textSurface);
    SDL_RenderCopy(menuRenderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void renderMenu()
{
    drawButton(&startButton);
    drawButton(&infoButton);
    drawButton(&exitButton);
}
