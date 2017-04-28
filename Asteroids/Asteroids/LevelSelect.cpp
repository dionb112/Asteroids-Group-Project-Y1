#include "LevelSelect.h"
#include "Globals.h"
void LevelSelect::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(30, 40));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Level Selection\nPress Space for Main Menu\nUse the number keys to select \na level between 1-5\nThen press the Enter key to enter the selected level\nlevels 6-8 set to come in an expansion next Fall!\n\nPress Escape to Exit");

	if (!m_fullTexture.loadFromFile("ASSETS/IMAGES/planet0.png"))
	{
		std::cout << "Error Loading solor system";
	}
	m_planet = -1;
}

void LevelSelect::render(sf::RenderWindow & window)
{
	m_sprite.setTexture(m_fullTexture);
	window.draw(m_sprite);
	if (m_planet != -1)
	{
		m_sprite.setTexture(m_planetTexture);
		window.draw(m_sprite);
	}
	window.draw(m_screenText);
}

void LevelSelect::setPlanet(int newPlanet)
{
	m_planet = newPlanet;

	switch (m_planet)
	{
	case 0:
		if (!m_planetTexture.loadFromFile("ASSETS/IMAGES/planet1.png"))
		{
			std::cout << "Error Loading mercury";
		}
		break;
	case 1:
		if (!m_planetTexture.loadFromFile("ASSETS/IMAGES/planet2.png"))
		{
			std::cout << "Error Loading venus";
		}
		break;
	case 2:
		if (!m_planetTexture.loadFromFile("ASSETS/IMAGES/planet3.png"))
		{
			std::cout << "Error Loading earth";
		}
		break;
	case 3:
		if (!m_planetTexture.loadFromFile("ASSETS/IMAGES/planet4.png"))
		{
			std::cout << "Error Loading mars";
		}
		break;
	case 4:
		if (!m_planetTexture.loadFromFile("ASSETS/IMAGES/planet5.png"))
		{
			std::cout << "Error Loading jupiter";
		}
		break;
	}
		
}

