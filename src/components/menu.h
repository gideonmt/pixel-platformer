#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "../res.h"

// Button state constants
enum ButtonState {
    UNSELECTED,
    SELECTED,
};

// Data structure to represent a button
typedef struct {
    const char *text;
    int x, y;
    int width, height;
    enum ButtonState state;
    void (*action)(void);
} Button;

void initMenu(SDL_Renderer *renderer, TTF_Font *pfont);
void handleMenuEvents(SDL_Event *e);
void renderMenu();

void startAction(void);
void infoAction(void);
void exitAction(void);

int quit;

#endif // MENU_H
