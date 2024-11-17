#ifndef C2048APP_SPRITE_H
#define C2048APP_SPRITE_H

typedef struct Texture Texture;

typedef struct Sprite
{
	Texture* texture;

	float x;
	float y;
} Sprite;

int getSpriteCount();
Sprite* getSprite(int index);

Sprite* createSprite(float x, float y);
void freeAllSprites();

#endif