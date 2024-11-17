#include "engine/engine.h"
#include <stdio.h>

int main(int argc, char* args[])
{
	if (!initEngine())
		goto close;

	Sprite* sprite = createSprite(0, 0);
	Sprite* sprite2 = createSprite(2.5, 2);

	while (1)
	{
		struct GameEvents gameEvents = updateEvents();

		if (gameEvents.quit)
			break;

		//Game logic

		updateGraphics();
	}

	close:
	closeEngine();

	return 0;
}