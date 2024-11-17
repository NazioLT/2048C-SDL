#include "engine.h"

#include "graphics/graphics.h"
#include "inputs.h"
#include "medias.h"
#include "graphics/camera.h"
#include "components/sprite.h"

#include <stdio.h>
#include <stdbool.h>

EngineEvents engineEvents;

bool initEngine()
{
	if (!initGraphics())
		return false;

	if (!initCamera(2, 0, 0))
		return false;

	return true;
}

void closeEngine()
{
	freeAllSprites();

	closeGraphics();
}

const EngineEvents* updateEvents()
{
	SDL_Event events;

	while (SDL_PollEvent(&events) != 0)
	{
		if (events.type == SDL_QUIT)
		{
			engineEvents.quit = true;
		}
		if (events.type == SDL_KEYDOWN)
		{
			engineEvents.hasKeyDown = true;
			updateInputsArray(&events, engineEvents.keyDown);
		}
	}

	return &engineEvents;
}

const EngineEvents* getEvents()
{
	return &engineEvents;
}