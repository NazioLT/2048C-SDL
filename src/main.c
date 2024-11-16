#include "engine/engine.h"
#include <stdio.h>

int main(int argc, char* args[])
{
	if (!initEngine())
		goto close;

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

	close:
	closeEngine();

	return 0;
}