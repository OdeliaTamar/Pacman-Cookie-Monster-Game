#pragma once
#include <SFML/Graphics.hpp>
#include"Level.h"
#include"Menu.h"
#include"Reasources.h"
#include "Utilities.h"
class Controller
{
public:
	Controller();
	~Controller()=default;
	void run();
	void startNewGame();
	void printGameOver();
	void printWin();
	void draw();
private:
	Menu m_menu;
	std::unique_ptr<Pacman> m_player;
	sf::Sprite m_gameOverWinSprite;  //for the win and game over pictures
	sf::Sound m_gameOverWinSound;   //for the win and game over
};

