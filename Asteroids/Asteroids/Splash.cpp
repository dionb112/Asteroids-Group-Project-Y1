#include "Splash.h"
#include "Globals.h"
void Splash::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f, SCR_H - 32));
	m_screenText.setColor(sf::Color::White);
	m_screenText.setString("Press Space Bar to Begin Or Press Escape to Exit");

	if (!m_texture.loadFromFile("ASSETS/IMAGES/splash.png"))
	{
		std::cout << "Error Loading splash";
	}
	m_sprite.setTexture(m_texture);
}

void Splash::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_screenText);
}

