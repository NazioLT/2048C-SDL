#include "inputs.h"

void updateInputsArray(const SDL_Event* events, bool* keyArray)
{
	switch (events->key.keysym.sym)
	{
	case SDLK_UP:
		keyArray[APP_INPUT_UP] = true;
		break;

	case SDLK_DOWN:
		keyArray[APP_INPUT_DOWN] = true;
		break;

	case SDLK_RIGHT:
		keyArray[APP_INPUT_RIGHT] = true;
		break;

	case SDLK_LEFT:
		keyArray[APP_INPUT_LEFT] = true;
		break;
	}
}