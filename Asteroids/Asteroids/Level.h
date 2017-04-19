#pragma once
#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"
class Level
{
private:
	sf::Text m_screenText;
	Player player;
	Bullet playerBullet;
	Asteroids largeAsteroids[MAX_ASTEROIDS];
	Asteroids medAsteroids[MAX_ASTEROIDS];
	Asteroids smallAsteroids[MAX_ASTEROIDS];
	Asteroids tinyAsteroids[MAX_ASTEROIDS];

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
	void setAsteroidType();
	void initAsteroids();
	void updateAsteroids();
};
