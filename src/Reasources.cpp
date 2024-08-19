#include "Reasources.h"


Reasources& Reasources::getInstance()
{
	static Reasources m_instance;
	return m_instance;
}
//-------------------------------------
Reasources::Reasources()
{
	//load the textures
	m_texture.resize(NUM_OF_PICTURES);
	m_texture[newGameButton].loadFromFile("NewGameButton.png");
	m_texture[helpButton].loadFromFile("HelpButton.png");
	m_texture[exitButton].loadFromFile("ExitButton.png");
	m_texture[pacman].loadFromFile("Pacman.png");
	m_texture[superPacman].loadFromFile("Super.png");
	m_texture[smartDemon].loadFromFile("Demon.png");
	m_texture[stupidDemon].loadFromFile("StupidDemon.png");
	m_texture[wall].loadFromFile("Wall.png");
	m_texture[cookie].loadFromFile("Cookie.png");
	m_texture[gift].loadFromFile("Gift.png");
	m_texture[giftD].loadFromFile("GiftD.png");
	m_texture[giftC].loadFromFile("GiftC.png");
	m_texture[giftS].loadFromFile("GiftS.png");
	m_texture[giftE].loadFromFile("GiftE.png");
	m_texture[key].loadFromFile("Key.png");
	m_texture[door].loadFromFile("Door.png");
	m_texture[heart].loadFromFile("Heart.png");
	m_texture[logo].loadFromFile("Logo.png");
	m_texture[cookieMonster].loadFromFile("cookieMonster.png");
	m_texture[gameOver].loadFromFile("GameOver.png");
	m_texture[win].loadFromFile("Win.png");
	m_texture[doorY].loadFromFile("DoorY.png");
	m_texture[keyY].loadFromFile("KeyY.png");
	m_texture[doorP].loadFromFile("DoorP.png");
	m_texture[keyP].loadFromFile("KeyP.png");
	m_texture[help].loadFromFile("Help.png");
	m_texture[keyR].loadFromFile("KeyR.png");
	m_texture[doorR].loadFromFile("DoorR.png");
	m_texture[EatDemon].loadFromFile("EatDemon.png");

	//load the texts
	m_text.resize(NUM_OF_TEXTS);
	m_text[level].setString("Level:");
	m_text[score].setString("Score:");
	m_text[live].setString("Live:");
	m_text[time1].setString("Time:");
	
	//load the sound Buffers
	m_buffer.resize(NUM_OF_SOUNDS);
	m_buffer[eatCookie].loadFromFile("EatCookie.wav");
	m_buffer[GameOver].loadFromFile("gameOver.wav");
	m_buffer[Win].loadFromFile("Win.wav");

	//load the background music
	m_music.openFromFile("background.wav");

	for (int i = 0, x = 0; i < NUM_OF_TEXTS; i++, x += 200)//load the texts
	{
		m_font.loadFromFile("C:/Windows/Fonts/SNAP____.ttf");
		m_text[i].setFont(m_font);
		m_text[i].setCharacterSize(24); // in pixels
		m_text[i].setFillColor(sf::Color(0, 153, 255));// set the color
		m_text[i].setPosition(x, 0);// the position of the text
	}
}
//-------------------------------------
sf::RenderWindow& Reasources::getWindow()
{
	return m_window;
}
//-------------------------------------
sf::RenderWindow& Reasources::getHelpWindow()
{
	return m_helpWindow;
}
//-------------------------------------
void Reasources::createWindow()
{
	 m_window.create(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Pacman"); 
}
//-------------------------------------
void Reasources::createHelpWindow()
{
	m_helpWindow.create(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Hellp");
}
//-------------------------------------
sf::Texture& Reasources::getTexture(enum Pictures index)
{
	return m_texture[index];
}
//-------------------------------------
sf::Text& Reasources::getText(enum Texts index)
{
	return m_text[index];
}
//-------------------------------------
sf::Font& Reasources::getFont()
{
	return m_font;
}
//-------------------------------------
sf::SoundBuffer& Reasources::getSoundBuffer(enum SoundBuffer index)
{
	return m_buffer[index];
}
//-------------------------------------
sf::Music& Reasources::getMusic()
{
	return m_music;
}
