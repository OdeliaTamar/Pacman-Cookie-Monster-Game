#include  "SuperPacGift.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include "LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"

SuperPacGift::SuperPacGift(const enum Pictures& p, sf::Vector2f position) :Gift(p, position)
{
}
//-------------------------------------
void SuperPacGift::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,  level);
}
//-------------------------------------
void SuperPacGift::collide(Pacman& pacman, Level& level)
{
	pacman.collide(*this, level);
}
