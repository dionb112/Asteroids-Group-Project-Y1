#pragma once
#include "Pirate.h"
#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "Gems.h"
#include "SFML/Graphics.hpp"
class Level
{
private:
	sf::Text m_screenText;
	Player player;
	Bullet playerBullet;
	Bullet enemyBullet;
	Asteroids largeAsteroids[MAX_ASTEROIDS];
	Asteroids medAsteroids[MAX_ASTEROIDS + 4];
	Asteroids smallAsteroids[MAX_ASTEROIDS + 14];
	Asteroids tinyAsteroids[MAX_ASTEROIDS + 34];
	Gems gems;
	Pirate pirate;
	int m_noOfLarge;
	int m_noOfMed;
	int m_noOfSmall;
	int m_noOfTiny;
	int m_counter;

public:
	void init();
	void update();

	void movePlayer();
	void rotatePlayer(bool rotateLeft);
	void actionManager();
	void enemyShoot();
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

	void setNoOfAsteroids();
	void setAsteroidType();
	void initAsteroids();
	void updateAsteroids();
	void deleteLarge();
	void deleteMed();
	void deleteSmall();
	void deleteTiny();
	void addMed();
	void addSmall();
	void addTiny();
	void spawnGem();

	void collisions();
	void playerCollisions();
	void bulletCollsions();
	void pirateCollsions();
	bool isColliding(int x1, int y1, int rad1, int x2, int y2, int rad2);
};
