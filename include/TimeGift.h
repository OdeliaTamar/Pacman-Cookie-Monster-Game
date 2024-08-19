#pragma once
#include"Gift.h"
class Wall;
class Door;
class Key;
class DemonFreezeGift;
class Cookie;
class LifeGift;
class Pacman;
class SmartDemon;
class StupidDemon;
class Level;
class TimeGift:public Gift
{
public:
	TimeGift(const enum Pictures& p, sf::Vector2f position);
	virtual~TimeGift()=default;
	TimeGift(const TimeGift& other) = default;
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
	virtual void collide(Pacman&, Level&) override;

protected:

};

