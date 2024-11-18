#ifndef C2048APP_DRAWCALLS_H
#define C2048APP_DRAWCALLS_H

#include <stdbool.h>
#include <SDL.h>

bool initDrawCalls();
void DrawSprites(const SDL_Renderer* renderer);
void closeDrawCalls();

#endif