#pragma once
#include "Object.h"
class Controller;
class Button
{
public:
	Button(const enum Pictures& p,  sf::Vector2f position);
	virtual ~Button()=default;
	virtual void click(const sf::Vector2f& v,Controller& c) const=0;
	virtual void draw();
	void setPosition(const sf::Vector2f& position);
	sf::FloatRect getGlobalBounds()const { return m_sprite.getGlobalBounds(); }
protected:
	sf::Sprite m_sprite;
};

