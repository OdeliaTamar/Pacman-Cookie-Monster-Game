#include"TimeGift.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"

TimeGift::TimeGift(const enum Pictures& p, sf::Vector2f position):Gift(p,position)
{
}
//-------------------------------------
void TimeGift::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//-------------------------------------
void TimeGift::collide(Pacman& pacman, Level& level)
{
	//extra time
	pacman.collide(*this,  level);
	
}
