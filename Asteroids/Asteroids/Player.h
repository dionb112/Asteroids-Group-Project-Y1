#pragma once

#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"

const int PI = 3.14159265;

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void render(sf::RenderWindow &window);
	sf::Sprite getBody();

	void move();
	double getRotation();
	void rotate(bool turnLeft);
	void friction();

	void screenWrap();

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::IntRect m_playerRect;

	sf::CircleShape m_body;
	double m_rotation;
	double m_turnRate;
	sf::Vector2f m_velocity;
	double m_acceleration;
	sf::Vector2f m_accelerationVector;
};
