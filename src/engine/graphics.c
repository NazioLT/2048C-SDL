#include "graphics.h"

#include <stdio.h>

#define APP_NAME "2048 SDL"
#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 480

bool initGraphics()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL INIT FAILED");
		return false;
	}

	gameWindow = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (gameWindow == NULL)
	{
		printf("SDL WINDOW INIT FAILED");
		return false;
	}

	screenSurface = SDL_GetWindowSurface(gameWindow);
	return true;
}

void updateGraphics()
{
	SDL_UpdateWindowSurface(gameWindow);
}

void closeGraphics()
{
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();
}