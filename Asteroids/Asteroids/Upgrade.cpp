#include "Upgrade.h"
#include "Globals.h"
void Upgrade::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f, SCR_H / 6.0f));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Upgrade Screen\nPress Space for Main Menu\nPress 1 to upgrade your fire rate\nPress 2 to upgrade your engines\nPress 3 to upgrade your armour\nPress 4 to upgrade your hull capacity\nPress 5 to upgrade your shields\nPress 6 to upgrade your fuel capacity\nPress Escape to Exit");
}

void Upgrade::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
}