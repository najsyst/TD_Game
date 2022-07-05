#include "Tower.h"+
#include "button.h"
#include "Enemy.h"
#include "GameState.h"

void Tower::initCoordinates(Button* button) 
{
	setCoordinates(button->getPosition().x, button->getPosition().y);
}

Tower::Tower(GameState* gameState) : Object (gameState)
{
}

Tower::~Tower()
{
}

float Tower::getDamage()
{
	return damage;
}

float Tower::getRange()
{
	return range;
}

float Tower::getAttack_speed()
{
	return attack_speed;
}


void Tower::update()
{
	for (int i = 0; i < gameState->Objects.size(); i++)
	{
		if (Enemy* enemy = dynamic_cast<Enemy*>(gameState->Objects[i]))
		{
			if (inRange(enemy, range) == true)
			{
				shoot(enemy);
			}
		}
	}
}

void Tower::shoot(Object* object)
{
	sf::Time delta_time = sf::milliseconds(1000 / attack_speed);
	if (Enemy* enemy = dynamic_cast<Enemy*>(object))
	{
		elapsed_time += clock.restart();
		while (elapsed_time >= delta_time)
		{
			elapsed_time -= delta_time;
			enemy->setHealth(damage);
			gameState->createBullet(this, object);
			if (Bullet* bullet = dynamic_cast<Bullet*>(gameState->Objects.back()))
			{
				bullet->tower = this;
			}
		}
	}
}

bool Tower::inRange(Enemy* enemy, float range)
{
	sf::Vector2f temp = enemy->getCoordinates() - this->getCoordinates();

	if (std::sqrt(std::pow(temp.x, 2) + std::pow(temp.y, 2)) < range/2)
	{
		return true;
	}
	return false;
}
