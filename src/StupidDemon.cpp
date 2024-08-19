#include "StupidDemon.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "Pacman.h"
#include"SmartDemon.h"
#include "Level.h"


StupidDemon::StupidDemon(const enum Pictures& p, sf::Vector2f position):Demon(p,position)
{
	
}
//-------------------------------------
void StupidDemon::move(float time)
{
	m_countStep--;
	if (m_countStep <= 0)
	{
		m_countStep = rand() % 4 + 1300;

		int option = rand() % 4; // (int(time) + 1);
		//int option = rand() % 4; /*rand() % (int(time)+1);*/
		switch (option)
		{
		case 0://right
			m_direction = { 1, 0 };
			break;
		case 1://left
			m_direction = { -1, 0 };
			break;
		case 2://up
			m_direction = { 0, -1 };
			break;
		case 3: //down
			m_direction = { 0, 1 };
			break;
		}
	}
	m_sprite.move(m_direction * m_speed * time);
}
//-------------------------------------
void StupidDemon::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//-------------------------------------
void StupidDemon::collide(Pacman& pac, Level& level)
{
	setPosition();
}
