#include "Level.h"
#include "Controller.h"

Level::Level(int levelNum, std::unique_ptr<Pacman>& pac):m_levelClock(), m_levelNumber(levelNum), m_board(m_levelNumber), m_player(pac),
        m_infoDisplay(m_levelNumber, m_player,m_timeLevel, m_giftClock),m_cookies(0), m_timeLevel(0)
{	
	m_levelClock.restart();//clock of the level
	m_player->pacmanType(REGULAR);
	m_board.readFromFile(*this);
	m_giftClock.restart();
}
//------------------------------------------------------
void Level::addSmartDemon(const enum Pictures& p,sf::Vector2f v)
{
	m_demons.push_back(std::make_unique<SmartDemon>(m_player,p, v));

}
//------------------------------------------------------
void Level::addStupidDemon(const enum Pictures& p,sf::Vector2f v)
{
	m_demons.push_back(std::make_unique<StupidDemon>(p,v));
}
//------------------------------------------------------
bool Level::run()
{
	Reasources::getInstance().getMusic().setLoop(true);//play music
	Reasources::getInstance().getMusic().play();
	
	while (Reasources::getInstance().getWindow().isOpen())
	{
		for (auto event = sf::Event{}; Reasources::getInstance().getWindow().pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Reasources::getInstance().getWindow().close();
				break;
			}
		}
		
		movePlayers();// pacman and demons move
		checkColide();//check the collision for pacman and demon
		handleClockes();//check clocks for gifts

		if (checkWin())
			return true;
	
		if (checkGameOver())
			return false;

		Reasources::getInstance().getWindow().clear(sf::Color::White);
		draw();
		Reasources::getInstance().getWindow().display();
	}
	return true;
}
//------------------------------------------------------
void Level::movePlayers()
{
	float time = m_speedClock.restart().asSeconds();//speed clock for movement
	m_player->updatePrevPosition(m_player->getSprite().getPosition());//save the last position 
	m_player->move(time);
	for (int i = 0; i < m_demons.size(); i++)//move the demons
	{
		m_demons[i]->updatePrevPosition(m_demons[i]->getSprite().getPosition());//save the last position 
		m_demons[i]->move(time);
	}
}
//------------------------------------------------------
void Level::draw()
{
	m_infoDisplay.display();//draw the information display
	m_board.draw();//draw the objects
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->draw();
	}
	m_player->draw();
}
//------------------------------------------------------
void Level::updatePacmanPosition(sf::Vector2f v)//return pacman to the first position
{
	m_player->getSprite().setPosition(v);
	m_player->setFirstPosition(v);
}
//------------------------------------------------------
void Level::checkColide()
{
	for (int i = 0; i < m_demons.size(); i++)//colide pacmen with demon
	{
		if (m_player->colideWith(m_demons[i].get()))
		{
			m_player->collide(*m_demons[i].get(), *this);
			returnDemonToFirstPlace();
		}
		
	}
	for (int i = 0; i < m_board.getSizeOfStatic(); i++)
	{
		if (m_player->colideWith(m_board.getObject(i)))//colide pacmen with static
		{ 
				m_player->collide(*m_board.getObject(i), *this);
		
		}
		for (int j = 0; j < m_demons.size(); j++)//colide demon with static
		{
		if(m_demons[j]->colideWith(m_board.getObject(i)))
			m_demons[j]->collide(*m_board.getObject(i), *this);
		}
	
	}
	m_board.deleteStaticObject();//delete the dead static objects
	deleteDemon();//delete the demons who need to died

}
//------------------------------------------------------
void Level::setLevelTime(int time)
{
	m_timeLevel = time;
}
//------------------------------------------------------
void Level::updateCookies(int amount)//how many cookies there is in the level
{
	m_cookies+=amount;
}
//------------------------------------------------------
bool Level::checkWin()
{
	if (m_cookies == 0)
		return true;
	return false;
}
//------------------------------------------------------
bool  Level::checkGameOver()
{
	float time = m_levelClock.getElapsedTime().asSeconds();
	if(m_player->getLive() == 0 ||
	  (m_timeLevel!=0&&  time>= m_timeLevel * LEVEL_SECONDS))//time is over
	{ 
		return true;
	}
	return false;
}
//------------------------------------------------------
void Level::freezeDemons()
{
	m_freezeClock.restart();
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->freezeDemon();//freeze all the demons
	}
}
//------------------------------------------------------
void Level::releaseDemon()
{
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->releaseDemon();//release all the demons
	}
}
//------------------------------------------------------
void Level::updateNumLevel(int levelNum)//update the number of level
{
	m_levelNumber = levelNum;
}
//------------------------------------------------------
void Level::extraTime()
{
	m_timeLevel+=1;
}
//------------------------------------------------------
void Level::restartGiftClock()
{
	m_giftClock.restart();
}
//------------------------------------------------------
void Level::returnDemonToFirstPlace()
{
	for (int i = 0; i < m_demons.size(); i++)//return the demons to the first place
	{
		m_demons[i]->setFirstPosition();
	}
}
//------------------------------------------------------
float Level::getSpeedClock()
{
	float time = m_speedClock.restart().asSeconds();
	return time;
}
//------------------------------------------------------
void Level::deleteDemon()
{
	std::erase_if(m_demons, [](const auto& demon) { return demon->isDead(); });
}
//------------------------------------------------------
void Level::handleClockes()
{
	if (m_freezeClock.getElapsedTime().asSeconds() >= float(TIME_FOR_FREEZE_DEMON))
		releaseDemon();
	
	if (m_giftClock.getElapsedTime().asSeconds() >= float(TIME_FOR_GIFT))
		m_player->pacmanType(REGULAR);

}