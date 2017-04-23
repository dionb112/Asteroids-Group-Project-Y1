#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"
class Asteroids
{
	sf::Vector2f m_speed;

	sf::Texture m_largeTexture;
	sf::Texture m_medTexture;
	sf::Texture m_smallTexture;
	sf::Texture m_tinyTexture;

	sf::Sprite m_largeSprite;
	sf::Sprite m_medSprite;
	sf::Sprite m_smallSprite;
	sf::Sprite m_tinySprite;

	sf::Vector2f m_largePos;
	sf::Vector2f m_medPos;
	sf::Vector2f m_smallPos;
	sf::Vector2f m_tinyPos;
	
	int m_type;

	int m_radius;

public:
	Asteroids();
	~Asteroids();
	void loadContent();
	void init();
	void render(sf::RenderWindow & window);
	void update();
	void spawnAsteroids();
	void setupType(int type);
	void movement();
	void screenWrap();
	sf::Vector2f getPos();
	int getRadius();
	void setAllOffScr(sf::Vector2f &pos, sf::Sprite &sprit);
};