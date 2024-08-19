#include "Menu.h"
#include "Controller.h"

Menu::Menu(Controller& c):m_controller(c)
{
	//the buttons
	float x = WINDOW_SIZE / 3.f, y = BUTTON_Y_POSITION;
	m_buttons.push_back(std::make_unique<NewGameButton>(newGameButton, sf::Vector2f(x, y)));
	m_buttons.push_back(std::make_unique<HelpButton>(helpButton, sf::Vector2f(x, y*2)));
	m_buttons.push_back(std::make_unique<ExitButton>(exitButton, sf::Vector2f(x, y*3)));

	m_sprite.setTexture(Reasources::getInstance().getTexture(logo));//for the logo
	m_sprite.setPosition(x-50.f, 0);//for the logo
}
//--------------------------------------------------
void Menu::show()
{
	Reasources::getInstance().createWindow();
	while (Reasources::getInstance().getWindow().isOpen())
	{
		for (auto event = sf::Event{}; Reasources::getInstance().getWindow().pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Reasources::getInstance().getWindow().close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				handleClick(event);
			}
			break;
			}
		}
		Reasources::getInstance().getWindow().clear(sf::Color::White);

		//draw the buttons
		for (int i = 0; i < m_buttons.size(); i++)
		{
			m_buttons[i]->draw();
		}
		Reasources::getInstance().getWindow().draw(m_sprite);//draw the logo
		Reasources::getInstance().getWindow().display();
	}
}
//--------------------------------------------------
void Menu::handleClick(const sf::Event& event)
{
	auto location = Reasources::getInstance().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });//the location of the press
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i]->getGlobalBounds().contains(location))
		{
			m_buttons[i]->click(location ,m_controller);
		}

	}
}
