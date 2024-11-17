#ifndef C2048APP_ENGINE_H
#define C2048APP_ENGINE_H

#include "inputs.h"
#include "sprite.h"

struct GameEvents 
{
    bool quit;

    bool hasKeyDown;
    bool keyDown[APP_INPUT_COUNT];
};

bool initEngine();
void closeEngine();

struct GameEvents updateEvents();

#endif