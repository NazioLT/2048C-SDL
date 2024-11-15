#ifndef C2048APP_GRAPHICS_H
#define C2048APP_GRAPHICS_H

#include <SDL.h>
#include <stdbool.h>

SDL_Window* gameWindow;
SDL_Surface* screenSurface;

bool initGraphics();
void updateGraphics();
void closeGraphics();

#endif