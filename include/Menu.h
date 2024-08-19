#pragma once
#include <vector>
#include <memory>
#include "Button.h"
#include "NewGameButton.h"
#include "ExitButton.h"
#include "HelpButton.h"
#include <SFML/Graphics.hpp>
#include "Reasources.h"

class Controller;
class Menu
{
public:
	Menu(Controller& c);
	~Menu()=default;
	void show();
	void handleClick(const sf::Event& event);
private:
	std::vector <std::unique_ptr<Button>> m_buttons;
	Controller& m_controller;
	sf::Sprite m_sprite;
};

