#pragma once
#include "MovingObject.h"
#include "Demon.h"
#include "Pacman.h"
class Wall;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class Cookie;
class StupidDemon;
class Level;
class SmartDemon: public Demon
{
public:
	SmartDemon( std::unique_ptr<Pacman>& pacman,const enum Pictures& p, sf::Vector2f position);
	virtual ~SmartDemon()=default;
	SmartDemon(const SmartDemon& other) = default;
	virtual void move(float time) override;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall& wall, Level& level) override;
	virtual void collide(Cookie&, Level&) override {}
	virtual void collide(Door& door, Level& level) override{ Demon::collide(door, level); }
	virtual void collide(Key&, Level&) override {}
	virtual void collide(DemonFreezeGift&, Level&) override {}
	virtual void collide(TimeGift&, Level&) override {}
	virtual void collide(LifeGift&, Level&) override {}
	virtual void collide(SmartDemon&, Level&) override {}
	virtual void collide(StupidDemon&, Level&) override {}
	virtual void collide(Pacman&, Level&) override;

protected:
	std::unique_ptr<Pacman>& m_pacman;
};

