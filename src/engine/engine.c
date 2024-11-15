#include "engine.h"

#include "graphics.h"

bool initEngine()
{
	return initGraphics();
}

void closeEngine()
{
	closeGraphics();
}