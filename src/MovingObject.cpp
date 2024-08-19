#include "MovingObject.h"
#include "Object.h"
#include"Cookie.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Level.h"


MovingObject::MovingObject(const enum Pictures& p,  sf::Vector2f position):Object(p,position)
{
}
//-------------------------------------------
void MovingObject::updatePrevPosition(sf::Vector2f position)
{	
	m_prevPosition = position;
}
//-------------------------------------------
void MovingObject::setPosition()
{
	m_sprite.setPosition(m_prevPosition);//the last position
}
//-------------------------------------------
void MovingObject::setFirstPosition()
{
	m_sprite.setPosition(m_firstPosition);//the first position
}
