#include "Enemy.h"
#include "GameState.h"





Enemy::Enemy(GameState* gameState) : Object(gameState)
{
	speed = 10;
	health = 100;
	initCoordinates();
	temp = getCoordinates();
}

Enemy::~Enemy()
{

}

float Enemy::getHealth()
{
	return health;
}

float Enemy::getSpeed()
{
	return speed;
}

bool Enemy::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	return true;
}

void Enemy::setHealth(float damage)
{
	health -= damage;
}

void Enemy::move()
{
	 
	if (temp == getCoordinates())
	{
		int x_row = (getCoordinates().x - 25) / 50;
		int y_col = (getCoordinates().y - 25) / 50;

		for (int i = 0; i < 1; i++)
		{
			if (gameState->map->pom[x_row + 1][y_col] == 2 && x_pom != x_row + 1)
			{
				temp = sf::Vector2f((x_row + 1) * 50 + 25, y_col * 50 + 25);
				break;
			}
			if (x_row > 1 && gameState->map->pom[x_row - 1][y_col] == 2 && x_pom != x_row - 1)
			{
				temp = sf::Vector2f((x_row - 1) * 50 + 25, y_col * 50 + 25);
				break;
			}
			if (gameState->map->pom[x_row][y_col + 1] == 2 && y_pom != y_col + 1)
			{
				temp = sf::Vector2f((x_row) * 50 + 25, (y_col + 1) * 50 + 25);
				break;
			}
			if (y_col > 1 && gameState->map->pom[x_row][y_col - 1] == 2 && y_pom != y_col - 1)
			{
				temp = sf::Vector2f((x_row) * 50 + 25, (y_col - 1) * 50 + 25);
				break;
			}
		}
		
		x_pom = x_row;
		y_pom = y_col;
	}
	else
	{
		for (int i = 0; i < 1; i++)
		{
			if (temp.x > getCoordinates().x)
			{
				setCoordinates(getCoordinates().x + 0.1 * speed, getCoordinates().y);
				break;
			}
			if (temp.x < getCoordinates().x)
			{
				setCoordinates(getCoordinates().x - 0.1 * speed, getCoordinates().y);
				break;
			}
			if (temp.y > getCoordinates().y)
			{
				setCoordinates(getCoordinates().x, getCoordinates().y + 0.1 * speed);
				break;
			}
			if (temp.y < getCoordinates().y)
			{
				setCoordinates(getCoordinates().x, getCoordinates().y - 0.1 * speed);
				break;
			}
		}
	}
}

void Enemy::initCoordinates()
{
		for (int y = 0; y < gameState->map->maxSize_y; y++)
		{
			if (gameState->map->pom[0][y] == 2)
			{
				setCoordinates(0 + 25, y * 50 + 25);
			}
		}
}

void Enemy::update()
{
	move();
}
