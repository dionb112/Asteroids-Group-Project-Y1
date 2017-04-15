#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void setPosition(double x, double y);
	void setVelocity(double angle);
	sf::CircleShape getBody();
	bool getActive();
	void update();
	void screenWrap();
	void render(sf::RenderWindow &window);

private:
	sf::CircleShape m_body;
	sf::Vector2f m_velocity;
	double m_speed;
	bool m_active;
	int m_timer;
};