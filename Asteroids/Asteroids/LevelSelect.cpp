#include "LevelSelect.h"
#include "Globals.h"
void LevelSelect::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f, SCR_H / 2.5f));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Level Selection\nPress Space for Main Menu\nUse the number keys to select \na level between 1-5\n\nPress Escape to Exit");
}

void LevelSelect::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
}

