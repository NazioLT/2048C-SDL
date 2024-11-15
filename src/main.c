#include "engine/engine.h"

int main(int argc, char* args[])
{
	if(initEngine() == 0)
		return 0;

	while (1)
	{
		updateGraphics();
	}

	closeEngine();

	return 0;
}