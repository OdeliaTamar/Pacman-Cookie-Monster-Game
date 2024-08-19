#include "StaticObject.h"
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

StaticObject::StaticObject(const enum Pictures& p, sf::Vector2f position):Object(p,position)
{
}
//-------------------------------------
bool StaticObject::isDead()const
{
  return (m_dead);
}
//-------------------------------------
void StaticObject::updateDead()
{
	m_dead = true;
}
