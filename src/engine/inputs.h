#ifndef C2048APP_INPUTS_H
#define C2048APP_INPUTS_H

#include <SDL.h>
#include <stdbool.h>

enum GameInputsKeys
{
    APP_INPUT_UP,
    APP_INPUT_DOWN,
    APP_INPUT_RIGHT,
    APP_INPUT_LEFT,
    APP_INPUT_COUNT
};

void updateInputsArray(const SDL_Event* events, bool* keyArray);

#endif