#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Utilities.h"
enum Pictures
{
	newGameButton,helpButton,exitButton,pacman,superPacman,smartDemon,stupidDemon,wall,cookie,gift,giftD,
	giftC,giftS, giftE,key,door,heart,logo,cookieMonster,gameOver,win,doorY,keyY,doorP,keyP,help,doorR,keyR,EatDemon
};
enum Texts
{
	level,score,
	live,time1
};
enum SoundBuffer
{
	eatCookie,
	GameOver,
	Win
};
class Reasources
{
public:
	~Reasources() = default;
	sf::Texture& getTexture(enum Pictures index);
	sf::RenderWindow& getWindow();
	sf::RenderWindow& getHelpWindow();
	void createWindow(); 
	void createHelpWindow(); 
	static Reasources& getInstance();
	sf::Text& getText(enum Texts index);
	sf::Font& getFont();
	sf::SoundBuffer& getSoundBuffer(enum SoundBuffer index);
	sf::Music& getMusic();
private:
	Reasources();
	Reasources(const Reasources&) = default;//copy
	static Reasources m_instance;
	std::vector <sf::Texture> m_texture;
	std::vector <sf::Text> m_text;
	std::vector <sf::SoundBuffer> m_buffer;
	sf::RenderWindow m_window;
	sf::RenderWindow m_helpWindow;
	sf::Font m_font;
	sf::Music m_music;
};
