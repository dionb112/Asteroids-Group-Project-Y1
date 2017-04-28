#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class LevelSelect
{
private:
	sf::Text m_screenText;
	sf::Sprite m_sprite;
	sf::Texture m_fullTexture;
	sf::Texture m_planetTexture;
	int m_planet;
public:
	void init(sf::Font &font);
	void render(sf::RenderWindow &window);
	void setPlanet(int newPlayet);
};