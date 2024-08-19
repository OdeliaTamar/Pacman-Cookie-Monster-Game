#pragma once
#include "Pacman.h"
#include"Board.h"
#include"Demon.h"
#include"SmartDemon.h"
#include"StupidDemon.h"
#include"InformationDisplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
class Controller;
class Level
{
public:
	Level(int levelNum, std::unique_ptr<Pacman>&);
	~Level()=default;
	void addSmartDemon(const enum Pictures& p,sf::Vector2f v);
	void addStupidDemon(const enum Pictures& p,sf::Vector2f v);
	void updatePacmanPosition( sf::Vector2f v);
	bool run();
	void movePlayers();
	void draw();
	void checkColide();
	void setLevelTime(int time);
	void updateCookies(int amount);
	bool checkWin();
	bool checkGameOver();
	void freezeDemons();
	void releaseDemon();
	void updateNumLevel(int levelNum);
	void extraTime();
	void restartGiftClock();
	void returnDemonToFirstPlace();
	float getSpeedClock();
	void deleteDemon();
	void handleClockes();
private:
	int m_timeLevel;
	int m_levelNumber;
	Board m_board;
	std::vector <std::unique_ptr<Demon>> m_demons;
	std::unique_ptr<Pacman>& m_player;
	sf::Clock m_levelClock;
	InformationDisplay m_infoDisplay;
	int m_cookies;
	sf::Clock m_freezeClock;
	sf::Clock m_speedClock; 
	sf::Clock m_giftClock;
	
};
