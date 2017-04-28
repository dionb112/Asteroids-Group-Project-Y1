#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class MainMenu
{
private:
	sf::Text m_screenText;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:
	void init(sf::Font &font);
	void render(sf::RenderWindow &window);
};