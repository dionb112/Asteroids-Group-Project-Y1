#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

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
public:
	Asteroids();
	~Asteroids();
	void loadContent();
	void init();
	void render(sf::RenderWindow & window);
	void update();
	void setupSprites();
};