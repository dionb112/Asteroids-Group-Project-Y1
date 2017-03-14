#pragma once
#include "SFML/Graphics.hpp"
class Player
{
public:
	Player();
	~Player();

	void init();
	void render(sf::RenderWindow &window);
	sf::CircleShape getBody();
	double getRotation();
	void rotate(int rotate);


	sf::CircleShape m_body;
	double m_rotation;

	sf::Vector2f m_velocity;
	double m_speed;
	double m_acceleration;
	double m_decelaration;
};
