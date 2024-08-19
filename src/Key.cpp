#include "Key.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "Pacman.h"
#include "Level.h"

Key::Key(const enum Pictures& p, sf::Vector2f position):StaticObject(p,position),m_door(nullptr)
{
}
//------------------------------------------------------
void Key::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//------------------------------------------------------
void Key::collide(Pacman& pacman, Level& level)
{
	 pacman.collide(*this, level);
}
//------------------------------------------------------
void Key::setKeyColor(enum Colors color)
{
	if (color == YELLOW)
		m_sprite.setTexture(Reasources::getInstance().getTexture(keyY));
	else if (color == RED)
		m_sprite.setTexture(Reasources::getInstance().getTexture(keyR));
	else if (color == PURPLE)
		m_sprite.setTexture(Reasources::getInstance().getTexture(keyP));
}