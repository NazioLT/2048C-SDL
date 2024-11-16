#include "engine.h"

#include "graphics.h"
#include "inputs.h"
#include "medias.h"
#include <stdio.h>

bool initEngine()
{
	if (!initGraphics())
		return false;

	return true;
}

void closeEngine()
{
	closeGraphics();
}

struct GameEvents updateEvents()
{
	struct GameEvents gameEvents = {
		.quit = false
	};

	SDL_Event events;

	while (SDL_PollEvent(&events) != 0)
	{
		if (events.type == SDL_QUIT)
		{
			gameEvents.quit = true;
		}
		if (events.type == SDL_KEYDOWN)
		{
			gameEvents.hasKeyDown = true;
			updateInputsArray(&events, &gameEvents.keyDown);
		}
	}

	return gameEvents;
}