#include "SharpShooter.h"
#include "GameState.h"
SharpShooter::SharpShooter(GameState* gameState) : Tower(gameState)
{
	range = 600;
	attack_speed = 0.5;
	damage = 50;
	initCoordinates(gameState->buttons["TOWER2"]);
}

SharpShooter::~SharpShooter()
{
}

