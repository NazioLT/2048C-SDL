#ifndef C2048APP_ENGINE_EVENTS_H
#define C2048APP_ENGINE_EVENTS_H

#include "inputs.h"

typedef struct EngineEvents
{
    bool quit;

    bool hasKeyDown;
    bool keyDown[APP_INPUT_COUNT];
} EngineEvents;

const EngineEvents* getEvents();
void updateEvents();

#endif