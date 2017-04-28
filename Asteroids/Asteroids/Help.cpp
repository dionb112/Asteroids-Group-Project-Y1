#include "Help.h"
#include "Globals.h"
void Help::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 4, SCR_H / 4));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Press Space for Main Menu\n\nUse the W Key to Accelerate!\nUse the A and D keys to Rotate!\nSpace Bar to Shoot!\nSurvive and collect gems to upgrade your ship!\n\nPress Escape to Exit");
}

void Help::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
}

