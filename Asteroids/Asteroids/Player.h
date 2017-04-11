#pragma once

#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Globals.h"


class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void render(sf::RenderWindow &window);
	sf::Sprite getBody();

	void move();
	double getRotation();
	void rotate(bool turnLeft);
	void friction();

	void screenWrap();

	void fireUp();
	void boostUp();
	void armourUp();
	void capacityUp();
	void shieldUp();
	void fuelUp();

private:

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::IntRect m_playerRect;

	sf::CircleShape m_body;
	double m_rotation;
	double m_turnRate;
	sf::Vector2f m_velocity;
	double m_acceleration;
	sf::Vector2f m_accelerationVector;

	//player upgradable stats
	int m_capacityLevel;
	int m_shieldLevel;
	int m_fuelLevel;
	int m_fireRate;
	int m_boostLevel;
	int m_armourLevel;
};
