#include "sprite.h"

#include "engine/medias.h"
#include "engine/graphics/graphics.h"
#include <stdio.h>

const int MAX_SPRITE_COUNT = 16;
int spriteCount = 0;
Sprite* sprites[16];

int getSpriteCount()
{
	return spriteCount;
}

Sprite* getSprite(int index)
{
	return sprites[index];
}

Sprite* createSprite(float x, float y)
{
	if (spriteCount >= MAX_SPRITE_COUNT)
	{
		printf("Cannot add new drawCall!");
		return NULL;
	}

	Sprite* sprite = malloc(sizeof(Sprite));
	sprite->texture = testTexture;
	sprite->x = x;
	sprite->y = y;
	sprite->zOrder = 0;

	sprites[spriteCount] = sprite;
	spriteCount++;

	return sprite;
}

void freeSprite(Sprite* sprite)
{
	if (sprite == NULL)
		return;

	free(sprite);
	sprite = NULL;
}

void freeAllSprites()
{
	for (size_t i = 0; i < spriteCount; i++)
	{
		freeSprite(sprites[i]);
	}
}