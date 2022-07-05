#include "GEnemy.h"
#include "Enemy.h"



GEnemy::GEnemy(Object* object) : GObject(object)
{
	healthBar.setSize(sf::Vector2f(25, 4));
	healthBar.setFillColor(sf::Color(255, 0, 0));
	healthBar.setOrigin(sf::Vector2f(12, 2));
	sprite = Graphic("Sprite\\enemy.png");
	float x = sprite.getLocalBounds().width;
	float y = sprite.getLocalBounds().height;

	sprite.setOrigin(x / 2, y / 2);
}

GEnemy::~GEnemy()
{
}


void GEnemy::draw(sf::RenderTarget* target)
{
	sprite.setPosition(object->getCoordinates());
	healthBar.setPosition(object->getCoordinates().x, object->getCoordinates().y - 15);
	target->draw(healthBar);
;	target->draw(sprite);
	if (Enemy* enemy = dynamic_cast<Enemy*>(object))
	{
		healthBar.setSize(sf::Vector2f(((enemy->getHealth() / 100) * 25), 4));
	}
}
