#include "GBullet.h"

GBullet::GBullet(Object* object) : GObject(object)
{
	sprite = Graphic("Sprite\\bullet1.png");
	float x = sprite.getLocalBounds().width;
	float y = sprite.getLocalBounds().height;

	sprite.setOrigin(x / 2, y / 2);
}

GBullet::~GBullet()
{

}


void GBullet::draw(sf::RenderTarget* target)
{
	sprite.setPosition(object->getCoordinates());
	target->draw(sprite);
}
