#include "Wall.h"
#include "Cookie.h"
#include "Object.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include "Level.h"


Wall::Wall(const enum Pictures& p, sf::Vector2f position):StaticObject(p,position)
{
}
//-------------------------------------
void Wall::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this, level);
}
