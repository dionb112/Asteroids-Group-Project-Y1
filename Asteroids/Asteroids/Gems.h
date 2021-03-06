#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"
#include "MyVector3D.h"

class Gems
{
	sf::Texture m_texture;
	sf::Sprite m_bodies[5];

	bool m_isAlive[5];
	int m_radius;

public:
	Gems();
	void loadContent(int index);
	void init(int index);
	void update();
	void render(sf::RenderWindow &window);
	void spawn(int index, sf::Vector2f deadAsteroidPos);
	void rotate();
	MyVector3D getPos(int index);
	int getRadius();
	void reset();
	void setPosition(MyVector3D newPos, int index);
	bool getAlive(int index);
};
