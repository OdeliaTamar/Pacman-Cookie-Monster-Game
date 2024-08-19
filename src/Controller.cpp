#include "Controller.h"

Controller::Controller() :m_player(std::make_unique<Pacman>(pacman, sf::Vector2f(0, 0))), m_menu(*this)
{
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(gameOver));
}
//-----------------------------------------------
void Controller::run()
{
	m_menu.show();
}
//-----------------------------------------------
void Controller::startNewGame()
{	
	m_player->restartData();
	int levelNum= 1;
	//start the levels
	for (; levelNum <= NUM_OF_LEVELS; levelNum++)
	{
		Level level(levelNum, m_player);//new level
		if (!level.run())//can continue to the next level
		{
			printGameOver();
			return;
		}
		
	} 
	if(levelNum== NUM_OF_LEVELS+1)
		printWin();//show "you win"
}
//-----------------------------------------------
void Controller::printGameOver()
{
	Reasources::getInstance().getMusic().stop();
	m_gameOverWinSound.setBuffer(Reasources::getInstance().getSoundBuffer(GameOver));
	m_gameOverWinSound.play();
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(gameOver));
	m_gameOverWinSprite.setPosition(sf::Vector2f(GAME_OVER_POSITION, GAME_OVER_POSITION));
	draw();
}
//-----------------------------------------------
void Controller::printWin()
{
	Reasources::getInstance().getMusic().stop();
	m_gameOverWinSound.setBuffer(Reasources::getInstance().getSoundBuffer(Win));
	m_gameOverWinSound.play();
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(win));
	m_gameOverWinSprite.setPosition(sf::Vector2f(WIN_POSITION, WIN_POSITION));
	draw();
}
//-----------------------------------------------
void Controller::draw()
{
	Reasources::getInstance().getWindow().clear(sf::Color::White);
	Reasources::getInstance().getWindow().draw(m_gameOverWinSprite);
	Reasources::getInstance().getWindow().display();
	sf::Time delayTime = sf::seconds(DELAY_TIME);
	sf::sleep(sf::Time(delayTime));
}

