#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"
class Gems
{
	sf::Texture m_texture;
	sf::Sprite m_bodies[5];

	bool isAlive[5];


public:
	Gems();
	void loadContent(int index);
	void init(int index);
	void update();
	void render(sf::RenderWindow &window);
	void spawn(int index, sf::Vector2f deadAsteroidPos);
	void rotate();
};
