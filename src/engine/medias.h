#ifndef C2048APP_MEDIAS_H
#define C2048APP_MEDIAS_H

#include <stdbool.h>
#include <SDL.h>

typedef struct Texture
{
	SDL_Texture* texture;

	int width;
	int height;
} Texture;

Texture* testTexture;

bool loadAllMedias(const SDL_Renderer* sdlRenderer);
void freeAllMedias();

#endif