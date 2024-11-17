#include "graphics.h"

#include "medias.h"
#include "camera.h"
#include <stdio.h>

SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

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
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gameRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (!loadAllMedias(gameRenderer))
	{
		printf("Medias couldn't initialize!");
		return false;
	}

	return true;
}

void updateGraphics()
{
	SDL_RenderClear(gameRenderer);

	SDL_Rect worldSpaceRect = { 0, 0, 1, 1 };
	SDL_Rect screenSpaceRect = cameraTransformWorldToScreenSpace(&testTexture, worldSpaceRect);

	SDL_RenderCopy(gameRenderer, testTexture->texture, NULL, &screenSpaceRect);

	SDL_RenderPresent(gameRenderer);
}

void closeGraphics()
{
	//FREE IMG
	freeAllMedias();

	//FREE WINDOW
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameRenderer = NULL;
	gameWindow = NULL;
	
	IMG_Quit();
	SDL_Quit();
}