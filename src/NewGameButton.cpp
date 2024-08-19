#include "NewGameButton.h"
#include"Controller.h"
NewGameButton::NewGameButton(const enum Pictures& p, sf::Vector2f position) :Button(p,position)
{
}
//-------------------------------------------
void NewGameButton::click(const sf::Vector2f& v, Controller& c) const
{
	c.startNewGame();
}