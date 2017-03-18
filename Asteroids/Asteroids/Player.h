#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

const int PI = 3.14159265359;

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void render(sf::RenderWindow &window);
	sf::CircleShape getBody();

	void move();
	double getRotation();
	void rotate(double rotate);
	void friction();

	void screenWrap();

	sf::CircleShape m_body;
	double m_rotation;
	sf::Vector2f m_velocity;
	double m_acceleration;
	sf::Vector2f m_accelerationVector;
};
