#include  "lifeGift.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"


LifeGift::LifeGift(const enum Pictures& p, sf::Vector2f position):Gift(p,position)
{
}
//--------------------------------------------------
void LifeGift::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this, level);
}
//--------------------------------------------------
void LifeGift::collide(Pacman& pacman, Level& level)
{
	pacman.collide(*this, level);
	if(pacman.getLive() <TOTAL_LIVE)
		pacman.updateLive(1);//add live as a gift
}
