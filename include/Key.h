#pragma once
#include "StaticObject.h"
class Wall;
class Door;
class Cookie;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class Pacman;
class Level;
class Key:public StaticObject
{
public:
	Key(const enum Pictures& p, sf::Vector2f position);
	virtual~Key()=default;
	Key(const Key& other) = default;
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
	virtual void collide(Pacman& pacman, Level&) override;
	void setDoor(Door* d) { m_door = d; }
	Door* getDoor()const { return m_door; }
	void setKeyColor(enum Colors color);

protected:
	Door* m_door;
};

