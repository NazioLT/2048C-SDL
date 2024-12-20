#include "camera.h"

#include "graphics.h"

float Scale = 1;
float X = 0;
float Y = 0;

float CameraCenterX = WINDOW_WIDTH / 2;
float CameraCenterY = WINDOW_HEIGHT / 2;
float PixelPerUnit = WINDOW_HEIGHT;

bool initCamera(float scale, float x, float y)
{
	Scale = scale;
	moveCamera(x, y);

	PixelPerUnit = WINDOW_HEIGHT / Scale;

	return true;
}

void moveCamera(float x, float y)
{
	X = x;
	Y = y;
}

SDL_Rect cameraTransformWorldToScreenSpace(const SDL_FRect* worldSpaceRect)
{
	SDL_Rect screenSpaceRect =
	{
		.w = worldSpaceRect->w * PixelPerUnit,
		.h = worldSpaceRect->h * PixelPerUnit
	};

	screenSpaceRect.x = PixelPerUnit * -X + PixelPerUnit * worldSpaceRect->x + CameraCenterX - screenSpaceRect.w / 2;
	screenSpaceRect.y = PixelPerUnit * -Y + PixelPerUnit * worldSpaceRect->y + CameraCenterY - screenSpaceRect.h / 2;

	return screenSpaceRect;
}