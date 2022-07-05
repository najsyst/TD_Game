#pragma once

#include "GObject.h"


class GTower : public GObject
{
private:
protected:
	sf::CircleShape GRange;
public:
	GTower(Object* object);
	~GTower();

	void draw(sf::RenderTarget* target);
};

