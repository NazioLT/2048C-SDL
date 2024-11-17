#include "engine/engine.h"
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
		EngineEvents* events = updateEvents();

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