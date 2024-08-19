#include "ExitButton.h"

ExitButton::ExitButton(const enum Pictures& p,  sf::Vector2f position) :Button(p, position)
{
}
//---------------------------------------
void ExitButton::click(const sf::Vector2f& v, Controller& c) const
{
	Reasources::getInstance().getWindow().close();
}