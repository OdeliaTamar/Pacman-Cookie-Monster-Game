#pragma once
#include "StaticObject.h"

class Wall;
class Cookie;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class Pacman;
class Level;
class Door:public StaticObject
{
public:
	Door(const enum Pictures& p, sf::Vector2f position);
	virtual~Door()=default;
	Door(const Door& other) = default;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall&, Level&) override {}
	virtual void collide(Cookie&, Level&) override {}
	virtual void collide(Door&, Level&) override {}
	virtual void collide(Key&, Level&) override {}
	virtual void collide(DemonFreezeGift&, Level&) override {}
	virtual void collide(TimeGift&, Level&) override {}
	virtual void collide(LifeGift&, Level&) override {}
	virtual void collide(SmartDemon& demon, Level& level) override;
	virtual void collide(StupidDemon& demon, Level& level) override;
	virtual void collide(Pacman& pacman, Level&) override;
	void setKey(Key* k) { m_key = k; }
	Key* getKey()const { return m_key; }
	void setDoorColor(enum Colors color);
protected:
	Key* m_key;
};

