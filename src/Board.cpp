#include "Board.h"
#include "Utilities.h"
#include "Level.h"
#include "Key.h"
#include "Cookie.h"
#include "SmartDemon.h"
#include "StupidDemon.h"
#include "Wall.h"
#include "Door.h"
#include "Gift.h"
#include "TimeGift.h"
#include "DemonFreezeGift.h"
#include "LifeGift.h"
#include "SuperPacGift.h"
#include"EatDemonPacGift.h"

Board::Board(int levelNum):m_row(0), m_col(0), m_levelTime(0)
{
	m_file.open("level" + std::to_string(levelNum) + ".txt");
	if (!m_file.is_open())
		exit(1);
}
//-------------------------------------------
//read the data from the file and put them in vector
void Board::readFromFile(Level& level)
{
	char item;
	m_file >> m_row >> m_col >> m_levelTime;
	m_file.get();
	level.setLevelTime(m_levelTime);
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_file.get(item);
			switch (item)
			{
			case SPACE:
				break;
			case PACMAN:
				level.updatePacmanPosition( sf::Vector2f(float(PIC_SIZE * j + 50), float(PIC_SIZE * i + 200)));
				break;
			case SMARTDEMON:
				level.addSmartDemon(smartDemon, sf::Vector2f(float(PIC_SIZE * j + 50), float(PIC_SIZE * i + 200)));
				break;
			case STUPITDEMON:
				level.addStupidDemon(stupidDemon, sf::Vector2f(float(PIC_SIZE * j + 50), float(PIC_SIZE * i + 200)));
				break;
			case GIFT://random gift
			{
				int option = rand() % 5 + 1;
				while (m_levelTime == NO_TIME_LIMIT && option==1)//no time gift for level without time limit
					option = rand() % 5 + 1;
				switch (option)
				{
				case 1:
					m_statObjects.push_back(std::make_unique<TimeGift>(giftC, sf::Vector2f(float(PIC_SIZE * j + X_POSITION),float( PIC_SIZE * i + Y_POSITION))));
					break;
				case 2:
					m_statObjects.push_back(std::make_unique<DemonFreezeGift>(giftD, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
					break;
				case 3:
					m_statObjects.push_back(std::make_unique<LifeGift>(gift, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
					break;
				case 4:
					m_statObjects.push_back(std::make_unique<SuperPacGift>(giftS, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
					break;
				case 5:
					m_statObjects.push_back(std::make_unique<EatDemonPacGift>(giftE, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
					break;
				}
			}	
				break;
			case KEY:
				m_statObjects.push_back(std::make_unique<Key>(key, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
				break;
			case DOOR:
				m_statObjects.push_back(std::make_unique<Door>(door, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
				break;
			case COOKIE:
				m_statObjects.push_back(std::make_unique<Cookie>(cookie, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
				level.updateCookies(1);
				break;
			case WALL:
				m_statObjects.push_back(std::make_unique<Wall>(wall, sf::Vector2f(float(PIC_SIZE * j + X_POSITION), float(PIC_SIZE * i + Y_POSITION))));
				break;
			default:
				break;
			}
		}
		m_file.get();
	}
	connectDoorsAndKeys();//connect each key to door 
}
//-------------------------------------------
void Board::draw()
{
	for (auto& a : m_statObjects)
		a->draw();
}
//-------------------------------------------
int Board::getSizeOfStatic()const
{
	return int(m_statObjects.size());
}
//-------------------------------------------
StaticObject* Board::getObject(int index) const
{
	return(m_statObjects[index].get());
}
//-------------------------------------------//delet the static object by condition
void Board::deleteStaticObject()
{
	std::erase_if(m_statObjects, [](const auto& item) { return item->isDead(); });
}
//-------------------------------------------
void Board::connectDoorsAndKeys()
{
	Colors myColor = YELLOW;
	for (int i = 0; i < m_statObjects.size(); i++)
	{
		if (((Colors)((int)myColor + 1)) == NUM_OF_COLORS)//change the color
			myColor = YELLOW;
		Door* door = dynamic_cast<Door*>(m_statObjects[i].get());
		if (door)
		{
			for (int j = int(m_statObjects.size())- 1; j >= 0; j--)
			{	
				Key* key = dynamic_cast<Key*>(m_statObjects[j].get());
				if (key)
				{

					if (key->getDoor() == nullptr)
					{
						//connect the key and door
						door->setKey(key);
						key->setDoor(door);
						//change the colors
						door->setDoorColor(myColor);
						key->setKeyColor(myColor);
						myColor = (Colors)((int)myColor + 1);
						break;
					}

				}
			}
		}
	}
}
