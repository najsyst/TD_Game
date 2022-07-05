#include "GTower.h"
#include "Tower.h"

GTower::GTower(Object* object) : GObject(object)
{
	if(Tower* tower = dynamic_cast<Tower*>(object))
	{ 
		GRange.setRadius(tower->getRange() / 2);
		GRange.setOrigin(tower->getRange() / 2, tower->getRange() / 2);
	}
}

GTower::~GTower()
{
}


void GTower::draw(sf::RenderTarget* target)
{
	sprite.setPosition(object->getCoordinates());
	sprite.setOrigin(32, 32);
	GRange.setFillColor(sf::Color(255, 0, 0, 50));
	GRange.setPosition(object->getCoordinates());
	target->draw(GRange);
	target->draw(sprite);
}

