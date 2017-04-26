#pragma once

#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "MyVector3D.h"


class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void render(sf::RenderWindow &window);
	MyVector3D getPos();
	int getRadius();

	void reset();

	void move();
	double getRotation();
	void rotate(bool turnLeft);
	void friction();
	void screenWrap();

	void animate();

	void fireUp();
	void boostUp();
	void armourUp();
	void capacityUp();
	void shieldUp();
	void fuelUp();

	void collectGem();
private:

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::IntRect m_playerRect;

	double m_rotation;
	double m_turnRate;
	MyVector3D m_position;
	MyVector3D m_velocity;
	MyVector3D m_accelerationVector;

	int m_currFrame;
	int m_frameDelay;
	bool m_isMoving;

	int m_radius;

	//Current stats for level
	double m_acceleration;
	int m_shields;
	int m_fuel;


	//player upgradable stats
	int m_capacityLevel;
	int m_shieldLevel;
	int m_fuelLevel;
	int m_fireRate;
	int m_boostLevel;
	int m_armourLevel;

	int m_credits;
};
