#include "InformationDisplay.h"
#include "Pacman.h"

InformationDisplay::InformationDisplay(int level, std::unique_ptr<Pacman>& pacman,int& levelTime, sf::Clock& c) :m_level(level),
m_score(pacman->getScore()), m_live(pacman->getLive()),m_levelTime(levelTime), m_levelClock(c)
{																					
	pacman->registerObserver(this);

	m_sprait.setTexture(Reasources::getInstance().getTexture(heart));//for the live

	m_text.resize(NUM_OF_TEXTS);//for the texts-titles
	for (int i = 0 ; i < NUM_OF_TEXTS; i++)
	{
		sf::Vector2f Pos = { Reasources::getInstance().getText(enum Texts(i)).getPosition().x + 90.f,
		Reasources::getInstance().getText(enum Texts(i)).getPosition().y };//position of the text

		m_text[i].setFont((Reasources::getInstance().getFont())); //set the font
		m_text[i].setCharacterSize(24); //size of the text
		m_text[i].setFillColor(sf::Color(0, 51, 153));
		m_text[i].setPosition(Pos);
	}

	m_pacSprait.setTexture(Reasources::getInstance().getTexture(cookieMonster));
	m_pacSprait.setPosition(COOKIE_MONSTER_X_POSITION, COOKIE_MONSTER_Y_POSITION);
}
//---------------------------------------
void InformationDisplay::display()
{
	for (int i = 0; i < NUM_OF_TEXTS; i++)//print the texts of the titles
	{
		if (i == time1 && m_levelTime == NO_TIME_LIMIT)
			break;
		Reasources::getInstance().getWindow().draw(Reasources::getInstance().getText(enum Texts(i)));
	}
		

	//print the heart for the live
	for (int i = 0, x = Reasources::getInstance().getText(live).getPosition().x + 80.f; i < m_live; i++, x += 40.f)
	{
		m_sprait.setPosition(float(x), HEART_Y_POSITION);
		Reasources::getInstance().getWindow().draw(m_sprait);
	}
	//load the texts
	m_text[level].setString(std::to_string(m_level));
	m_text[score].setString(std::to_string(m_score));

	if (m_levelTime != NO_TIME_LIMIT)//the level has time
	{
		float timeRemaining = m_levelTime * LEVEL_SECONDS - m_levelClock.getElapsedTime().asSeconds();
		if ((int)timeRemaining % LEVEL_SECONDS < TWO_DIGIT_NUMBER)
			m_text[time1].setString(std::to_string(((int)timeRemaining / LEVEL_SECONDS)) + ":0" + 
				             std::to_string(((int)timeRemaining % LEVEL_SECONDS)));//for the time
		else
			m_text[time1].setString(std::to_string(((int)timeRemaining / LEVEL_SECONDS)) + ":" +
				             std::to_string(((int)timeRemaining % LEVEL_SECONDS)));//for the time
	}

	for (int i = 0; i < NUM_OF_TEXTS; i++)//print the texts 
		Reasources::getInstance().getWindow().draw(m_text[i]);
	Reasources::getInstance().getWindow().draw(m_pacSprait);//the picture of cookie monster
}

//------------------------------------------------------
void InformationDisplay::updateLive(int lives)
{
	m_live = lives;
}
//------------------------------------------------------
void InformationDisplay::updateScore(int score)
{
	m_score = score;
}
