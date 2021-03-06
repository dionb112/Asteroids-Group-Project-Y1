#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"
#include "MyVector3D.h"

class Pirate
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::IntRect m_textureRect;
	double m_rotation;
	double m_turnRate;
	MyVector3D m_velocity;
	MyVector3D m_accelerationVector;
	double m_acceleration;
	bool m_isMoving;
	bool m_isRotating;

public:

	Pirate();
	~Pirate();
	MyVector3D getPos();
	void loadContent();
	void init();
	void setMoving(bool);
	void setRotating(bool newBool);
	sf::Sprite getBody();
	double getRotation();
	void update();
	void render(sf::RenderWindow &window);
	void spawn();
	void move();
	void friction();
	void screenWrap();
	void rotate();
	void reset();

};