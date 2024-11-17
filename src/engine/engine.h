#ifndef C2048APP_ENGINE_H
#define C2048APP_ENGINE_H

#include "inputs.h"
#include "components/sprite.h"

typedef struct EngineEvents 
{
    bool quit;

    bool hasKeyDown;
    bool keyDown[APP_INPUT_COUNT];
} EngineEvents;

bool initEngine();
void closeEngine();

const EngineEvents* updateEvents();
const EngineEvents* getEvents();

#endif