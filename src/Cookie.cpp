#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Pacman.h"
#include "Level.h"

Cookie::Cookie(const enum Pictures& p, sf::Vector2f position):StaticObject(p,position)
{
}
//-----------------------------------------------------------
void Cookie::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//----------------------------------------------------
void Cookie::collide(Pacman& pacman, Level& level)
{
	pacman.collide(*this,level);
}
