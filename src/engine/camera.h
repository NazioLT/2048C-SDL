#ifndef C2048APP_CAMERA_H
#define C2048APP_CAMERA_H

#include <SDL.h>
#include "medias.h"

bool initCamera(float scale, float x, float y);
SDL_Rect cameraTransformWorldToScreenSpace(const Texture* texture, SDL_Rect worldSpaceRect);

#endif