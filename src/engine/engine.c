#include "engine.h"

#include "graphics/graphics.h"
#include "graphics/camera.h"
#include "engineEvents.h"

#include <stdbool.h>

int OldFrameTick = 0;
float DeltaTime = 0;

float getDeltaTime()
{
	return DeltaTime;
}

bool initEngine()
{
	if (!initGraphics())
		return false;

	if (!initCamera(2, 0, 0))
		return false;

	return true;
}

void updateEngine()
{
	updateEvents();

	int currentTick = SDL_GetTicks();
	int deltaTick = currentTick - OldFrameTick;

	OldFrameTick = currentTick;
	DeltaTime = deltaTick / 1000.0f;
}

void closeEngine()
{
	freeAllSprites();

	closeGraphics();
}