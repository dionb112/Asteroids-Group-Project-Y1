#include "License.h"
#include "Globals.h"
void License::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 3, SCR_H / 2.5f));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("A game like no other! \nBrought to you by Dion and Emmet");
}

void License::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
}

