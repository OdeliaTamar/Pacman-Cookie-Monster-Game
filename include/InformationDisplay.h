#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Reasources.h"
#include "Observer.h"
class Pacman;
class InformationDisplay:public Observer
{
public:
	InformationDisplay(int level, std::unique_ptr<Pacman>& pacman,int& levelTime, sf::Clock& c);
	~InformationDisplay()=default;
	void display();
	virtual  void updateLive(int lives) override;
	virtual  void updateScore(int score) override;
private:
	std::vector <sf::Text> m_text;
	sf::Sprite m_sprait;  //for the live (hearts)
	sf::Sprite m_pacSprait; //for the pacman-cookieMonster picture
	int m_live;
	int m_score;
	int m_level;
	int& m_levelTime;
	sf::Clock& m_levelClock;
};

