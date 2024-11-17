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
	X = x;
	Y = y;

	PixelPerUnit = WINDOW_HEIGHT / Scale;
}

SDL_Rect cameraTransformWorldToScreenSpace(const Texture* texture, SDL_Rect worldSpaceRect)
{
	float pixelPerUnit = WINDOW_HEIGHT / Scale;

	SDL_Rect screenSpaceRect = 
	{
		.w = worldSpaceRect.h * pixelPerUnit,
		.h = worldSpaceRect.h * pixelPerUnit
	};

	screenSpaceRect.x = pixelPerUnit * -X + pixelPerUnit * worldSpaceRect.x + CameraCenterX - screenSpaceRect.w / 2;
	screenSpaceRect.y = pixelPerUnit * -Y + pixelPerUnit * worldSpaceRect.y + CameraCenterY - screenSpaceRect.h / 2;

	return screenSpaceRect;
}