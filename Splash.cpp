#include "Splash.h"
#include "Globals.h"
void Splash::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f, SCR_H / 2.5f));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Asteroids Game!\nPress Space Bar to Begin\nPress Escape to Exit");
}

void Splash::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
}

