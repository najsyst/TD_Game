#include "Bullet.h"
#include "GameState.h"
#include "Enemy.h"

Bullet::Bullet(GameState* gameState, Object* object, Object* object2) : Object(gameState)
{
	this->tower = object;
	this->enemy = object2;
	initCoordinates();
}

Bullet::~Bullet()
{
}

bool Bullet::DidItHit()
{
	if ((enemy->getCoordinates().x - 20 < getCoordinates().x) && (getCoordinates().x < enemy->getCoordinates().x + 20)
		&& (enemy->getCoordinates().y - 20 < getCoordinates().y) && (getCoordinates().y < enemy->getCoordinates().y + 20))
	{
		return true;
	}
	return false;
}

void Bullet::initCoordinates()
{

	setCoordinates(tower->getCoordinates().x, tower->getCoordinates().y);
}


void Bullet::move()
{
	sf::Vector2f temp = enemy->getCoordinates();
	if (temp.x > getCoordinates().x)
	{
		setCoordinates(getCoordinates().x + 5, getCoordinates().y);
	}
	if (temp.x < getCoordinates().x)
	{
		setCoordinates(getCoordinates().x - 5, getCoordinates().y);
	}
	if (temp.y > getCoordinates().y)
	{
		setCoordinates(getCoordinates().x, getCoordinates().y + 5);
	}
	if (temp.y < getCoordinates().y)
	{
		setCoordinates(getCoordinates().x, getCoordinates().y - 5);
	}
}

void Bullet::update()
{
	move();
}
