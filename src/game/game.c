#include "game.h"
#include "engine/components.h"
#include "engine/engine.h"

Sprite* sprite;
Sprite* sprite2;

void updateGame()
{
    float dt = getDeltaTime();
    sprite->x += dt;
}

bool initGame()
{
    sprite = createSprite(0, 0);
    sprite2 = createSprite(0, 0.5);

    return true;
}

void closeGame()
{
}