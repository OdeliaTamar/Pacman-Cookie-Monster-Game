#include "SmartDemon.h"
#include "Cookie.h"
#include "Object.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include "StupidDemon.h"
#include "Pacman.h"
#include "Level.h"

SmartDemon::SmartDemon(std::unique_ptr<Pacman>& pacman, const enum Pictures& p, sf::Vector2f position) :Demon(p, position),m_pacman(pacman)
{
	m_speed = float(DEMON_SPEED);
}
//-------------------------------------
void SmartDemon::move(float time)
{

	if (m_pacman->getSprite().getPosition().x - m_sprite.getPosition().x > EPSILON)//demon need to go right
		m_direction = { 1,0 };

	 if (m_sprite.getPosition().x - m_pacman->getSprite().getPosition().x > EPSILON)//demon need to left
		m_direction = { -1,0 };

	 if (m_sprite.getPosition().y - m_pacman->getSprite().getPosition().y > EPSILON)//demon need to go up
		 m_direction = { 0,-1 };

	 if (m_pacman->getSprite().getPosition().y - m_sprite.getPosition().y > EPSILON)//demon need to go down
		 m_direction = { 0,1 };

	 m_sprite.move(m_direction * time * m_speed);
}
//-------------------------------------
void SmartDemon::collide(Object& obj, Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this, level);
}
//-------------------------------------
void SmartDemon::collide(Pacman&, Level& level)
{
	setPosition();
}
//-------------------------------------
void SmartDemon::collide(Wall& wall, Level& level)
{
	 m_direction *= -1.f;
	sf::Vector2f wallPosition = wall.getSprite().getPosition();
		if (wallPosition.y <= m_sprite.getPosition().y)//if the wall is above the demon
		{
			m_sprite.move(sf::Vector2f(5, 0));
			m_sprite.move(sf::Vector2f(0, 8) );
		}
		else if (wallPosition.y >= m_sprite.getPosition().y)//if the wall is under the demon
		{
			m_sprite.move(sf::Vector2f(-5, 0));
			m_sprite.move(sf::Vector2f(0,-8));
		}
		else if (wallPosition.x <= m_sprite.getPosition().x)//if the wall is left to the demon
		{
			m_sprite.move(sf::Vector2f(0.f, -20.f));
			m_sprite.move(sf::Vector2f(1.f, 0.f));
		}
		else if (wallPosition.x >= m_sprite.getPosition().x)//if the wall is right to the demon
		{
			m_sprite.move(sf::Vector2f(0.f, -20.f));
			m_sprite.move(sf::Vector2f(-1.f, 0.f));
		}
}
