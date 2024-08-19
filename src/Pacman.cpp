#include "Pacman.h"
#include <cmath>
#include "MovingObject.h"
#include "Object.h"
#include"Cookie.h"
#include "Wall.h"
#include "Door.h"
#include"Key.h"
#include "DemonFreezeGift.h"
#include "TimeGift.h"
#include"LifeGift.h"
#include"SmartDemon.h"
#include "StupidDemon.h"
#include "RegularState.h"
#include "SuperPacGift.h"
#include "Level.h"
#include "EatDemonPacGift.h"
Pacman::Pacman(const enum Pictures& p, sf::Vector2f position) :MovingObject(p, position),
			   	m_live(TOTAL_LIVE), m_score(0), m_state(std::make_unique<RegularState>())
{
	m_speed = float(PAC_SPEED);
	m_firstPosition = m_sprite.getPosition();	
}
//-------------------------------------------
void Pacman::move(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.move(time * m_speed, 0);
		m_sprite.setScale(1,1);
		m_sprite.setRotation(0);
	
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.move(-time * m_speed, 0);
		m_sprite.setScale(-1,1);
		m_sprite.setRotation(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite.move(0, -time * m_speed);
		m_sprite.setScale(1,-1);
		m_sprite.setRotation(-90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_sprite.move(0, time * m_speed);
		m_sprite.setScale(1, -1);
		m_sprite.setRotation(90);	
	}

}
//-------------------------------------------
void Pacman::notifyObserversForLiveAndScore()
{
	for (auto& observer: m_observers)
	{
		observer->updateLive(m_live);
		observer->updateScore(m_score);
	}
}
//-------------------------------------------
void Pacman::updateLive(int num)
{
	m_live+=num;
	notifyObserversForLiveAndScore();
}
//-------------------------------------------
void Pacman::updateScore(int num)
{
	m_score += num;
	notifyObserversForLiveAndScore();
}
//-------------------------------------------
int Pacman::getLive()const
{
	return m_live;
}
//-------------------------------------------
int Pacman::getScore()const
{
	return m_score;
}
//-------------------------------------------
void Pacman::collide(Demon& demon, Level& level)
{
	m_state->collideDemon(*this,demon);
}
//-------------------------------------------
void  Pacman::setFirstPosition(sf::Vector2f pos)
{
	m_firstPosition = pos;
}
//-------------------------------------------
sf::Vector2f Pacman::getFirstPosition()const
{
	return m_firstPosition;
}
//-------------------------------------------
void Pacman::collide(Object& obj ,Level& level)
{
	if (&obj == this)
		return;
	obj.collide(*this,level);
}
//-------------------------------------------
void Pacman::collide(Cookie& cookie, Level& level)
{
	cookie.updateDead();//the cookie is eaten
	Pacman::updateScore(SCORE_FOR_COOKIE);
	level.updateCookies(-1);
}
//-------------------------------------------
void Pacman::collide(Key& key, Level& level)
{
	key.updateDead();//the key is eaten
	key.getDoor()->updateDead();
	Pacman::updateScore(SCORE_FOR_KEY);
}
//-------------------------------------------
void Pacman::collide(DemonFreezeGift& gift, Level& level)
{
	gift.updateDead(); //the gift is eaten     
	Pacman::updateScore(SCORE_FOR_GIFT);
	level.freezeDemons();
	
}
//-------------------------------------------
void Pacman::collide(TimeGift& gift, Level& level)
{
	gift.updateDead(); //the gift is eaten  
	Pacman::updateScore(SCORE_FOR_GIFT);
	level.extraTime();
}
//-------------------------------------------
void Pacman::collide(LifeGift& gift, Level& level)
{
	gift.updateDead();//the gift is eaten  
	Pacman::updateScore(SCORE_FOR_GIFT);

}
//-------------------------------------------
void Pacman::pacmanType(Input input)
{
	std::unique_ptr<PacmanState> state_ = m_state->pacmanType(input);
	if (state_)
	{
		m_state = std::move(state_);
		m_state->setImage(*this);
	}
}
//-------------------------------------------
void Pacman::collide(SuperPacGift& gift, Level& level)
{
	gift.updateDead();
	Pacman::updateScore(SCORE_FOR_GIFT);
	pacmanType(SUPER);
	level.restartGiftClock();
}
//-------------------------------------------
void Pacman::collide(EatDemonPacGift& gift, Level& level)
{
	gift.updateDead();//the gift is eaten  
	Pacman::updateScore(SCORE_FOR_GIFT);
	pacmanType(EAT_DEMON);
	level.restartGiftClock();
}
//-------------------------------------------
void Pacman::restartData()
{
	m_score = INITIAL_SCORE;
	m_live = TOTAL_LIVE;
	pacmanType(REGULAR);
}


