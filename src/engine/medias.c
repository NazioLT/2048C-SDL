#include "medias.h"

#include <SDL_image.h>
#include <stdio.h>

SDL_Renderer* renderer = NULL;

SDL_Texture* loadSDLTextureFromPath(char* path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		return NULL;
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (newTexture == NULL)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
	}

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

void freeTexture(Texture* texture)
{
	if (texture == NULL)
		return;

	SDL_DestroyTexture(texture->texture);

	free(texture);
	texture = NULL;
}

Texture* createTexture(const char* path)
{
	SDL_Texture* textureImage = loadSDLTextureFromPath(path);
	if (textureImage == NULL)
		return NULL;

	Texture* texture = malloc(sizeof(Texture));
	texture->texture = textureImage;

	return texture;
}

bool loadAllMedias(const SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;

	testTexture = createTexture("resources/test.png");
	if (testTexture == NULL)
		return false;

	return true;
}

void freeAllMedias()
{
	freeTexture(testTexture);
}