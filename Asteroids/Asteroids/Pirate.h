#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"

class Pirate
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::IntRect m_textureRect;
	double m_rotation;
	double m_turnRate;
	sf::Vector2f m_velocity;
	sf::Vector2f m_accelerationVector;
	double m_acceleration;

public:
	Pirate();
	~Pirate();
	void loadContent();
	void init();
	void update();
	void render(sf::RenderWindow &window);
	void spawn();
	void move();
	void screenWrap();
};