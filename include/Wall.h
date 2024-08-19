#pragma once
#include "StaticObject.h"
#include "SmartDemon.h"
#include "StupidDemon.h"
#include "Pacman.h"

class Wall;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class Pacman;
class Cookie;
class Level;
class Wall :public StaticObject
{
public:
	Wall(const enum Pictures& p, sf::Vector2f position);
	virtual~Wall ()=default;
	Wall(const Wall& other) = default;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall&, Level&) override {}
	virtual void collide(Cookie&, Level&) override {}
	virtual void collide(Door&, Level&) override {}
	virtual void collide(Key&, Level&) override {}
	virtual void collide(DemonFreezeGift&, Level&) override {}
	virtual void collide(TimeGift&, Level&) override {}
	virtual void collide(LifeGift&, Level&) override {}
	virtual void collide(SmartDemon& smartDemon, Level&level) override { smartDemon.collide(*this, level); }
	virtual void collide(StupidDemon& stupidDemon, Level& level) override { stupidDemon.collide(*this, level); }
	virtual void collide(Pacman& pacman, Level& level) override { pacman.collide(*this, level); }

protected:

};

