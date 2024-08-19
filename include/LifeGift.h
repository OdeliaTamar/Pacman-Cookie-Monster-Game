#pragma once
#include "Gift.h"
class Wall;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class Cookie;
class SuperPacman;
class SmartDemon;
class StupidDemon;
class RegularPacman;
class Level;
class LifeGift:public Gift
{
public:
	LifeGift(const enum Pictures& p, sf::Vector2f position);
	virtual~LifeGift()=default;
	LifeGift(const LifeGift& other) = default;
	virtual void collide(Object&, Level&) override;
	virtual void collide(Wall&, Level&) override {};
	virtual void collide(Cookie&, Level&) override {};
	virtual void collide(Door&, Level&) override {};
	virtual void collide(Key&, Level&) override {};
	virtual void collide(DemonFreezeGift&, Level&) override {};
	virtual void collide(TimeGift&, Level&) override {};
	virtual void collide(LifeGift&, Level&) override {};
	virtual void collide(SmartDemon&, Level&) override {};
	virtual void collide(StupidDemon&, Level&) override {};
	virtual void collide(Pacman& pacman, Level&) override;


protected:

};

