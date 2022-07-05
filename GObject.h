#pragma once

#include "Object.h"

class GObject
{
private:
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	
	Object *object;

public:
	GObject(Object* object);

	~GObject();

	sf::Sprite Graphic(std::string file);
	virtual void draw(sf::RenderTarget* target) = 0;

};

