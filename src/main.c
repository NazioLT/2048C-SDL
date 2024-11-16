#include "engine/engine.h"
#include <stdio.h>

int main(int argc, char* args[])
{
	if (!initEngine())
		return 0;

	while (1)
	{
		struct GameEvents gameEvents = updateEvents();

		if (gameEvents.quit)
			break;

		if (gameEvents.hasKeyDown)
		{
			printf("%d\n", gameEvents.keyDown[APP_INPUT_UP]);
		}

		updateGraphics();
	}

	closeEngine();

	return 0;
}