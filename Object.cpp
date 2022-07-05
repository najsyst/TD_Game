#include "Object.h"
#include "GameState.h"


Object::Object(GameState* gameState)
{
	this->gameState = gameState;
}

Object::~Object()
{

}

sf::Vector2f Object::getCoordinates()
{
	return coordinates;
}

void Object::setCoordinates(float x, float y)
{
	coordinates.x = x;
	coordinates.y = y;
}

void Object::initCoordinates()
{
}


