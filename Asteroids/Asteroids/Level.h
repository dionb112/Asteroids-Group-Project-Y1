#pragma once
#include "Player.h"
#include "Asteroid.h"
#include "SFML/Graphics.hpp"
class Level
{
private:
	sf::Text m_screenText;
	Player m_player;
public:
	void init();
	void update();
	void movePlayer();
	void rotatePlayer(bool rotateLeft);
	void render(sf::RenderWindow &window);
};
