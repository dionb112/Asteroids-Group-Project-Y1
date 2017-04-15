#pragma once
#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"
class Level
{
private:
	sf::Text m_screenText;
	Player m_player;
	Bullet m_playerBullet;
	Asteroids asteroids[MAX_ASTEROIDS];

public:
	void init();
	void update();

	void movePlayer();
	void rotatePlayer(bool rotateLeft);
	void playerShoot();

	void fireUp();
	void boostUp();
	void armourUp();
	void capacityUp();
	void shieldUp();
	void fuelUp();

	void levelSetup();

	void render(sf::RenderWindow &window);
	void drawAsteroids(sf::RenderWindow &window);
};
