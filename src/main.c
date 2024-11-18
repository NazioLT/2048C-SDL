#include "engine/engine.h"
#include "engine/engineEvents.h"
#include "game/game.h"
#include <stdio.h>

int main(int argc, char* args[])
{
	if (!initEngine())
		goto close;

	if (!initGame())
		goto close;

	while (1)
	{
		EngineEvents* events = getEvents();
		updateEngine();

		if (events->quit)
			break;

		updateGame();
		updateGraphics();
	}

	close:
	closeEngine();
	closeGame();

	return 0;
}