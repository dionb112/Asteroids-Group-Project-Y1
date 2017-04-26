#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"
#include "MyVector3D.h"

class Asteroids
{
	MyVector3D m_speed;

	sf::Texture m_largeTexture;
	sf::Texture m_medTexture;
	sf::Texture m_smallTexture;
	sf::Texture m_tinyTexture;

	sf::Sprite m_largeSprite;
	sf::Sprite m_medSprite;
	sf::Sprite m_smallSprite;
	sf::Sprite m_tinySprite;

	MyVector3D m_position;
	
	int m_type;

	bool m_isActive;
	int m_radius;

public:
	Asteroids();
	~Asteroids();
	bool getActive();
	void setActive(bool newActive);
	void loadContent();
	void render(sf::RenderWindow & window);
	void update();
	void spawnAsteroids();
	void setupType(int type);
	void movement();
	void screenWrap();
	void init();
	MyVector3D getPos();
	void setPos(MyVector3D newPos);
	int getRadius();
	void setOffScr();
};