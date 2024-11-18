#ifndef C2048APP_ENGINE_H
#define C2048APP_ENGINE_H

#include <stdbool.h>

float getDeltaTime();

bool initEngine();
void updateEngine();
void closeEngine();

#endif