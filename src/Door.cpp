#include "Door.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"

Door::Door(const enum Pictures& p, sf::Vector2f position):StaticObject(p,position),m_key(nullptr)
{
}
//---------------------------------------
void Door::collide(Object& obj,  Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//---------------------------------------
void Door::collide(Pacman& pacman, Level& level)
{
	 pacman.collide(*this, level);
}
//---------------------------------------
void Door::setDoorColor(enum Colors color)
{
	if (color == YELLOW)
		m_sprite.setTexture(Reasources::getInstance().getTexture(doorY));
	else if (color == RED)
		m_sprite.setTexture(Reasources::getInstance().getTexture(doorR));
	else if(color == PURPLE)
		m_sprite.setTexture(Reasources::getInstance().getTexture(doorP));
}
//---------------------------------------
void Door::collide(SmartDemon& demon, Level& level)
{ 
	demon.collide(*this, level); 
}
//---------------------------------------
void Door::collide(StupidDemon& demon, Level& level)
{
	demon.collide(*this, level);
}