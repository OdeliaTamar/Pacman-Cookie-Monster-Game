#pragma once
#include <vector>
#include <memory>
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include"Utilities.h"
#include <queue>
using namespace std;
using std::ifstream;
class Level;

class Board
{
public:
	Board(int i);
	~Board()=default;
	Board(const Board& other) = default;
	void readFromFile(Level& level);
	void draw();
	int getSizeOfStatic() const;
	StaticObject* getObject(int index) const;
	void deleteStaticObject();
	void connectDoorsAndKeys();

private:
	std::vector <std::unique_ptr<StaticObject>> m_statObjects;
	ifstream m_file;
	int m_row;
	int m_col;
	int m_levelTime;
	
};

