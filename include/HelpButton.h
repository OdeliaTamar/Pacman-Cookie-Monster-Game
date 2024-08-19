#pragma once
#include "Button.h"
class HelpButton :public Button
{
public:
	HelpButton(const enum Pictures& p, sf::Vector2f position);
	virtual ~HelpButton()=default;
	virtual void click(const sf::Vector2f& v, Controller& c) const override;
protected:
	sf::Sprite m_sprite;

};
