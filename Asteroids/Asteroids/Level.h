#pragma once
#include "Pirate.h"
#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "Gems.h"
#include "MyVector3D.h"
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
	LevelData levelData[5];

	int m_counter;
	int m_prevBehaviour;
public:
	void init();
	void update();

	void movePlayer();
	void rotatePlayer(bool rotateLeft);
	void actionManager();
	void enemyShoot();	//Update when pirate use MyVectors
	void playerShoot();

	void fireUp();
	void boostUp();
	void armourUp();
	void capacityUp();
	void fuelUp();

	void addCredits(int amount);
	int getCredits();
	int getFireLevel();
	int getBoostLevel();
	int getArmourLevel();
	int getCapacityLevel();
	int getFuelLevel();

	void levelSetup(int currLevel);
	void asteroidsSetup(int currLevel);

	void render(sf::RenderWindow &window);
	void drawAsteroids(sf::RenderWindow &window);

	void setAsteroidType();
	void updateAsteroids();
	void addMed(int deadLarge);
	void addSmall(int deadMed);
	void addTiny(int deadSmall);
	void spawnGem(int deadTiny);

	void collisions();
	void playerCollisions();
	void bulletCollsions(); //Update when gems use MyVectors
	void pirateCollsions();
	bool isColliding(MyVector3D pos1, int rad1, MyVector3D pos2, int rad2);
};
