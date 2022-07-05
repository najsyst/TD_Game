#include "Archer.h"
#include "GameState.h"
Archer::Archer(GameState* gameState) : Tower(gameState)
{
	range = 400;
	attack_speed = 2;
	damage = 20;
	initCoordinates(gameState->buttons["TOWER1"]);
}

Archer::~Archer()
{
}
