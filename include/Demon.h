#pragma once
#include "MovingObject.h"

class Wall;
class Cookie;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class Pacman;
class Level;
class Demon :public MovingObject
{
public:
	Demon(const enum Pictures& p, sf::Vector2f position);
	virtual~Demon()=default;
	virtual void collide(Object&, Level&) = 0;
	virtual void collide(Wall&, Level&) = 0; 
	virtual void collide(Cookie&, Level&) = 0;
	virtual void collide(Door&, Level&) = 0 { setPosition(); m_direction *= -1.f; }
	virtual void collide(Key&, Level&) = 0;
	virtual void collide(DemonFreezeGift&, Level&) = 0;
	virtual void collide(TimeGift&, Level&) = 0;
	virtual void collide(LifeGift&, Level&) = 0;
	virtual void collide(SmartDemon&, Level&) = 0;
	virtual void collide(StupidDemon&, Level&) = 0;
	virtual void collide(Pacman&, Level&) = 0;
	void freezeDemon();
	void releaseDemon();
	virtual bool  isDead() const;
	virtual void updateDead();
protected:
	sf::Vector2f m_direction = { 0,1 };
	bool m_dead=false;
};
