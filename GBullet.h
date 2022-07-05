#pragma once
#include "GObject.h"
#include "Object.h"

class GBullet : public GObject
{
private:
protected:
public:
	GBullet(Object* object);
	~GBullet();

	void draw(sf::RenderTarget* target);
};

