#pragma once
#include "Button.h"
class ExitButton:public Button
{
public:
	ExitButton(const enum Pictures& p,  sf::Vector2f position);
	virtual ~ExitButton()=default;
	virtual void click(const sf::Vector2f& v,  Controller& c) const override;

protected:

};
