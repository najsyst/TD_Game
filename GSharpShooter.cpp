#include "GSharpShooter.h"

GSharpShooter::GSharpShooter(Object* object) : GTower(object)
{
	sprite = Graphic("Sprite\\tower2.png");
}

GSharpShooter::~GSharpShooter()
{
}
