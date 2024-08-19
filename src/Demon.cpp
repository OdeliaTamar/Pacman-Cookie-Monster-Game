#include "Demon.h"
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

Demon::Demon(const enum Pictures& p, sf::Vector2f position):MovingObject(p,position)
{
	m_firstPosition = position;
}
//-----------------------------------------------
void Demon::freezeDemon()
{
	m_speed = NO_SPEED;
}
//-----------------------------------------------
void Demon::releaseDemon()
{
	m_speed = float(SPEED);
}
//---------------------------------------
bool Demon::isDead() const
{
	return (m_dead);
}
//---------------------------------------
void Demon::updateDead()//the demon need to died
{
	m_dead = true;
}

