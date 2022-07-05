#include "GObject.h"

GObject::GObject(Object* object)
{
    this->object = object;
}

GObject::~GObject()
{
}

sf::Sprite GObject::Graphic(std::string file)
{
    texture.loadFromFile(file);
    sprite.setTexture(texture);

    return sprite;
}
