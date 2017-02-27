#pragma once
#include "SFML/Graphics.hpp"
class Splash
{
private:
	sf::Text m_screenText;
public:
	void init(sf::Font &font);
	void render(sf::RenderWindow &window);
};