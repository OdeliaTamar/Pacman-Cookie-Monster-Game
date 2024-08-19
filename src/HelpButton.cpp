#include "HelpButton.h"
HelpButton::HelpButton(const enum Pictures& p, sf::Vector2f position) :Button(p, position)
{
	m_sprite.setTexture(Reasources::getInstance().getTexture(help));
}
//---------------------------------------
void HelpButton::click(const sf::Vector2f& v, Controller& c) const
{

	Reasources::getInstance().createHelpWindow();
	while (Reasources::getInstance().getHelpWindow().isOpen())
	{
		for (auto event = sf::Event{}; Reasources::getInstance().getHelpWindow().pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Reasources::getInstance().getHelpWindow().close();
				break;
			}
		}

		Reasources::getInstance().getHelpWindow().clear(sf::Color::White);
		Reasources::getInstance().getHelpWindow().draw(m_sprite); //draw the instructions
		Reasources::getInstance().getHelpWindow().display();
	}
}