#include  "EatDemonPacGift.h"
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

EatDemonPacGift::EatDemonPacGift(const enum Pictures& p, sf::Vector2f position) :Gift(p, position)
{
}
//---------------------------------------
void EatDemonPacGift::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this, level);
}
//---------------------------------------
void EatDemonPacGift::collide(Pacman& pacman, Level& level)
{
	pacman.collide(*this, level);
}
