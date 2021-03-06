#include "MainMenu.h"
#include "Globals.h"
void MainMenu::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f, SCR_H / 2.5f));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Main Menu:\nPress 1 for LevelSelect\nPress 2 for Upgrades\nPress 3 for Help\nPress Escape to Exit");
	
	if (!m_texture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "Error Loading menu";
	}
	m_sprite.setTexture(m_texture);
}

void MainMenu::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_screenText);
}

