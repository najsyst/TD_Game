#pragma once
#include "GObject.h"

class GEnemy : public GObject
{
private:
protected:
public:
	GEnemy(Object* object);
	~GEnemy();
	
	sf::RectangleShape healthBar;
	void draw(sf::RenderTarget* target);

};

