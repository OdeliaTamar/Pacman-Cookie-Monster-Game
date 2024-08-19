#pragma once
#include"Gift.h"

class Wall;
class Cookie;
class Door;
class Key;
class TimeGift;
class LifeGift;
class Pacman;
class SmartDemon;
class StupidDemon;
class Level;

class DemonFreezeGift:public Gift
{
public:
	DemonFreezeGift(const enum Pictures& p, sf::Vector2f position);
	virtual~DemonFreezeGift()=default;
	DemonFreezeGift(const DemonFreezeGift& other) = default;
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
	


protected:

};

