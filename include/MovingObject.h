#pragma once
#include "Object.h"

class Wall;
class Cookie;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class Level;

class MovingObject:public Object
{
public:
	MovingObject(const enum Pictures& p, sf::Vector2f position);
	virtual~MovingObject()=default;
	virtual void move(float time) = 0;
	float getSpeed()const { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }
	virtual void collide(Object&, Level&) = 0;
	virtual void collide(Wall&, Level&) = 0;
	virtual void collide(Cookie&, Level&) = 0;
	virtual void collide(Door&, Level&) = 0;
	virtual void collide(Key&, Level&) = 0;
	virtual void collide(DemonFreezeGift&, Level&) = 0;
	virtual void collide(TimeGift&, Level&) = 0;
	virtual void collide(LifeGift&, Level&) = 0;
	virtual void collide(SmartDemon&, Level&) = 0;
	virtual void collide(StupidDemon&, Level&) = 0;
	virtual void collide(Pacman&, Level&) = 0;
	
	void updatePrevPosition(sf::Vector2f position);
	void setPosition();
	void setFirstPosition();
protected:
	float m_speed = float(SPEED);
	sf::Vector2f m_prevPosition;
	sf::Vector2f m_firstPosition;
};
