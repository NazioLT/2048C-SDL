#include "drawCalls.h"

#include "engine/components/sprite.h"
#include "engine/medias.h"
#include "camera.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct DrawCall
{
	SDL_Texture* texture;
	SDL_Rect pixelRect;
} DrawCall;

typedef struct DrawCallLayer
{
	int count;
	DrawCall drawCalls[64];
} DrawCallLayer;

#define DRAWCALL_LAYER_COUNT 16
DrawCallLayer* DrawCallLayers = NULL;

bool initDrawCalls()
{
	DrawCallLayers = (DrawCallLayer*)malloc(sizeof(DrawCallLayer) * DRAWCALL_LAYER_COUNT);

	return true;
}

void DrawSprites(const SDL_Renderer* renderer)
{
	//Init drawcalls
	for (size_t i = 0; i < DRAWCALL_LAYER_COUNT; i++)
	{
		DrawCallLayers[i].count = 0;
	}

	//Class drawcalls
	for (size_t i = 0; i < getSpriteCount(); i++)
	{
		Sprite* sprite = getSprite(i);

		SDL_FRect worldSpaceRect = { sprite->x, sprite->y, 1, 1 };

		int layerId = MIN(MAX(sprite->zOrder, 0), DRAWCALL_LAYER_COUNT - 1);
		DrawCallLayer* layer = &DrawCallLayers[layerId];
		DrawCall drawCall =
		{
			.pixelRect = cameraTransformWorldToScreenSpace(&worldSpaceRect),
			.texture = sprite->texture->textureSDL
		};
		layer->drawCalls[layer->count] = drawCall;
		layer->count++;
	}

	//Draw
	for (size_t layerID = 0; layerID < DRAWCALL_LAYER_COUNT; layerID++)
	{
		DrawCallLayer* list = &DrawCallLayers[layerID];
		for (size_t i = 0; i < list->count; i++)
		{
			DrawCall* drawCall = &list->drawCalls[i];
			SDL_RenderCopy(renderer, drawCall->texture, NULL, &drawCall->pixelRect);
		}
	}
}

void closeDrawCalls()
{
	for (size_t i = 0; i < DRAWCALL_LAYER_COUNT; i++)
	{
		DrawCallLayers[i];
	}
	free(DrawCallLayers);
}
