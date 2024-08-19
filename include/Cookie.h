#pragma once
#include "StaticObject.h"
class Wall;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class Pacman;
class Level;
class Cookie:public StaticObject
{
public:
	Cookie(const enum Pictures& p, sf::Vector2f position);
	virtual ~Cookie() = default;
	Cookie(const Cookie & other) = default;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall&, Level&) override {}
	virtual void collide(Cookie&, Level&) override {}
	virtual void collide(Door&, Level&) override {}
	virtual void collide(Key&, Level&) override {}
	virtual void collide(DemonFreezeGift&, Level&) override {}
	virtual void collide(TimeGift&, Level&) override {}
	virtual void collide(LifeGift&, Level&) override {}
	virtual void collide(SmartDemon&, Level&) override {}
	virtual void collide(StupidDemon&, Level&) override {}
	virtual void collide(Pacman&, Level&) override ;

protected:

};