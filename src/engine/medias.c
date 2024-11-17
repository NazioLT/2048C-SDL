#include "medias.h"

#include <SDL_image.h>
#include <stdio.h>

SDL_Renderer* renderer = NULL;

void freeTexture(Texture* texture)
{
	if (texture == NULL)
		return;

	SDL_DestroyTexture(texture->texture);

	free(texture);
	texture = NULL;
}

bool createTexture(Texture* destination, const char* path)
{
	freeTexture(destination);

	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());

		return false;
	}

	SDL_Texture* newTexture = NULL;
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (newTexture == NULL)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());

		SDL_FreeSurface(loadedSurface);
		return false;
	}

	Texture* finalTexture = malloc(sizeof(Texture));
	finalTexture->texture = newTexture;
	finalTexture->width = loadedSurface->w;
	finalTexture->height = loadedSurface->h;

	testTexture = finalTexture;

	return true;
}

bool loadAllMedias(const SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;

	if (!createTexture(testTexture, "resources/test.png"))
		return false;

	return true;
}

void freeAllMedias()
{
	freeTexture(testTexture);
}