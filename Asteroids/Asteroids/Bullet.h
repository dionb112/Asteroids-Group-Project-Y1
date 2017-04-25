#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "MyVector3D.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void setPosition(MyVector3D pos);
	void setVelocity(double angle);
	MyVector3D getPos();
	int getRadius();
	bool getActive();
	void update();
	void screenWrap();
	void render(sf::RenderWindow &window);

private:
	sf::CircleShape m_body;
	MyVector3D m_position;
	int m_radius;
	MyVector3D m_velocity;
	double m_speed;
	bool m_active;
	int m_timer;
};