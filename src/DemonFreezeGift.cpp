#include "DemonFreezeGift.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"

DemonFreezeGift::DemonFreezeGift(const enum Pictures& p, sf::Vector2f position):Gift(p,position)
{
}
//---------------------------------------
void DemonFreezeGift::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//---------------------------------------
void DemonFreezeGift::collide(Pacman& pacman, Level& level)
{
	pacman.collide(*this,level);
}
