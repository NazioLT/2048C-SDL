#include "engineEvents.h"

EngineEvents engineEvents;

void updateEvents()
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