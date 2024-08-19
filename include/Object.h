#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Reasources.h"
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
class Object
{
public:
	Object(const enum Pictures& p, sf::Vector2f position);
	virtual ~Object()=0{};
	void draw();
	void setPosition(sf::Vector2f pos) { m_sprite.setPosition(pos); }
	sf::Sprite& getSprite() { return m_sprite; }
	sf::FloatRect getGlobalBounds()const { return m_sprite.getGlobalBounds(); }
	bool colideWith( Object* obj);
	virtual void collide(Object&, Level&) = 0;
	virtual void collide(Wall&, Level&) = 0;
	virtual void collide(Cookie&, Level&) = 0;
	virtual void collide(Door&, Level&) = 0;
	virtual void collide(Key&, Level&) = 0;
	virtual void collide(DemonFreezeGift&, Level&) = 0;
	virtual void collide(TimeGift&, Level&) = 0;
	virtual void collide(LifeGift&, Level&) = 0;
	virtual void collide(SmartDemon&, Level&) = 0;
	virtual void collide(StupidDemon&, Level&) = 0;
	virtual void collide(Pacman&, Level&) = 0;

protected:
	sf::Sprite m_sprite;

};

