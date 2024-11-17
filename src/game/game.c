#include "game.h"
#include "engine/engine.h"

Sprite* sprite = NULL;
Sprite* sprite2 = NULL;

void updateGame()
{
}

bool initGame()
{
    sprite = createSprite(0, 0);
    sprite2 = createSprite(2.5, 2);

    return true;
}

void closeGame()
{

}