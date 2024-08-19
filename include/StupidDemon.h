#pragma once
#include "Demon.h"
class Wall;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class Pacman;
class SmartDemon;
class Cookie;
class Level;

class StupidDemon:public Demon
{
public:
	StupidDemon(const enum Pictures& p, sf::Vector2f position);
	virtual ~StupidDemon()=default;
	StupidDemon(const StupidDemon& other) = default;
	virtual void move(float time) override;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall& wall, Level& level) override { setPosition(); m_direction *= -1.f; }
	virtual void collide(Cookie&, Level&) override {}
	virtual void collide(Door& door, Level & level) override { Demon::collide(door, level); }
	virtual void collide(Key&, Level&) override {}
	virtual void collide(DemonFreezeGift&, Level&) override {}
	virtual void collide(TimeGift&, Level&) override {}
	virtual void collide(LifeGift&, Level&) override {}
	virtual void collide(SmartDemon&, Level&) override {}
	virtual void collide(StupidDemon&, Level&) override {}
	virtual void collide(Pacman& pac, Level&) override;
protected:
	int m_countStep=0;
	float m_preTime = 0;
};

