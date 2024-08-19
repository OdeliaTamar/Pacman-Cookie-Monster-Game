#include "Button.h"
#include"Controller.h"

Button::Button(const enum Pictures& p, sf::Vector2f position)
{
	m_sprite.setTexture(Reasources::getInstance().getTexture(p));
	m_sprite.setPosition(position);
}
//----------------------------------------------------
void Button::draw()
{
	Reasources::getInstance().getWindow().draw(m_sprite);
}
//----------------------------------------------------
void Button::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

