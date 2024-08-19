#pragma once
#include "MovingObject.h"
#include "Subject.h"
#include"Demon.h"
#include "PacmanState.h"
class Wall;
class Cookie;
class Door;
class Key;
class DemonFreezeGift;
class TimeGift;
class LifeGift;
class SmartDemon;
class StupidDemon;
class SuperPacGift;
class Level;
class EatDemonPacGift;
class Pacman :public MovingObject, public Subject
{
public:
	Pacman(const enum Pictures& p, sf::Vector2f position);
	virtual ~Pacman() {};
	virtual void move(float time) override;
	void notifyObserversForLiveAndScore();
	void updateLive(int num);
	void updateScore(int num);
	int getLive()const;
	int getScore()const;
	void setFirstPosition(sf::Vector2f pos);
	sf::Vector2f getFirstPosition()const;
	virtual void collide(Demon& demon, Level&);
	virtual void collide(Object&, Level&);
	virtual void collide(Wall&, Level&) { setPosition(); }
	virtual void collide(Cookie&, Level&);
	virtual void collide(Door& door, Level& level) { m_state->collideDoor(*this, door); }
	virtual void collide(Key&, Level&);
	virtual void collide(DemonFreezeGift& gift, Level&);
	virtual void collide(TimeGift& gift, Level&);
	virtual void collide(LifeGift& gift, Level&);
	virtual void collide(SmartDemon&, Level&) {}
	virtual void collide(StupidDemon&, Level&) {}
	virtual void collide(Pacman&, Level&) {}
	virtual void collide(SuperPacGift& gift, Level&);
	virtual void collide(EatDemonPacGift& gift, Level&);
	virtual void pacmanType(Input input);
	void restartData();
protected:
	int m_live;
	int m_score;
	sf::Vector2f m_firstPosition;
	std::unique_ptr<PacmanState> m_state;
};
