#ifndef C2048APP_GRAPHICS_H
#define C2048APP_GRAPHICS_H

#include <stdbool.h>

#define APP_NAME "2048 SDL"
#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 480

bool initGraphics();
void updateGraphics();
void closeGraphics();

#endif