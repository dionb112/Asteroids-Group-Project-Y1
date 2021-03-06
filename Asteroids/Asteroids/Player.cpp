#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\smallplayerstrip064.png"))
	{
		std::cout << "problem loading player texture file";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerRect.width = 64;
	m_playerRect.height = 64;
	m_playerRect.top = 0;
	m_playerRect.left = 0;
	m_playerSprite.setTextureRect(m_playerRect);

	m_deathSplosion.setRadius(0);
	m_deathSplosion.setFillColor(sf::Color::Red);

	m_playerSprite.setOrigin(32, 32);
	m_position = MyVector3D(400, 240, 0);

	m_radius = 32;
	m_velocity = sf::Vector2f(0, 0);
	m_turnRate = 4;
	m_acceleration = 0.15;
	m_rotation = 0;
	
	m_currFrame = 0;
	m_frameDelay = 0;
	m_isMoving = false;

	m_fireRate = 1;
	m_boostLevel = 1;
	m_armourLevel = 1;
	m_capacityLevel = 1;
	m_fuelLevel = 1;

	m_credits = 10000;

	m_dead = false;
}

void Player::update()
{
	if (!m_dead)
	{
		m_position += m_velocity;
		friction();
		animate();
		screenWrap();
	}
	if (m_dead && m_deathSplosionSize < 100)
	{
		m_deathSplosionSize++;
		m_deathSplosion.setRadius(m_deathSplosionSize);
		m_deathSplosion.setOrigin(m_deathSplosionSize, m_deathSplosionSize);
	}
}

void Player::friction()
{
	m_velocity = m_velocity * 0.99;
}

void Player::screenWrap()
{
	if (m_position.X() < 0)
	{
		m_position = MyVector3D(SCR_W, m_position.Y(), 0);
	}
	if (m_position.X() > SCR_W)
	{
		m_position = MyVector3D(0, m_position.Y(), 0);
	}
	if (m_position.Y() < 0)
	{
		m_position = MyVector3D(m_position.Y(), SCR_H, 0);
	}
	if (m_position.Y() > SCR_H)
	{
		m_position = MyVector3D(m_position.Y(), 0, 0);
	}
}

void Player::animate()
{
	if (m_isMoving)
	{
		if (m_frameDelay <= 0)
		{
			m_frameDelay = 4;

			m_currFrame++;
			if (m_currFrame > 5)
			{
				m_currFrame = 1;
			}
		}

		m_frameDelay--;
		
	}
	if (!m_isMoving)
	{
		m_currFrame = 0;
	}

	m_playerRect.left = 64 * m_currFrame;
	m_playerSprite.setTextureRect(m_playerRect);

	m_isMoving = false;
}

void Player::fireUp()
{
	m_fireRate++;
	std::cout << "fireRate: " << m_fireRate << std::endl;
}

void Player::boostUp()
{
	m_boostLevel++;
	std::cout << "Boost: " << m_boostLevel << std::endl;
}

void Player::armourUp()
{
	m_armourLevel++;
	std::cout << "Armour: " << m_armourLevel << std::endl;
}

void Player::capacityUp()
{
	m_capacityLevel++;
	std::cout << "Capacity: " << m_capacityLevel << std::endl;
}

void Player::fuelUp()
{
	m_fuelLevel++;
	std::cout << "Fuel: " << m_fuelLevel << std::endl;
}

int Player::getFireLevel()
{
	return m_fireRate;
}

int Player::getBoostLevel()
{
	return m_boostLevel;
}

int Player::getArmourLevel()
{
	return m_armourLevel;
}

int Player::getCapacityLevel()
{
	return m_capacityLevel;
}

int Player::getFuelLevel()
{
	return m_fuelLevel;
}

int Player::getHold()
{
	return m_currHold;
}

void Player::addHold()
{
	m_currHold++;
}

void Player::addCredits(int amount)
{
	m_credits += amount;
}

int Player::getCredits()
{
	return m_credits;
}

bool Player::isDead()
{
	return m_dead;
}

void Player::killPlayer()
{
	m_dead = true;
	m_deathSplosion.setPosition(m_position);
	m_deathSplosionSize = 0;
}



void Player::render(sf::RenderWindow & window)
{
	if (!m_dead)
	{
		m_playerSprite.setPosition(m_position);
		window.draw(m_playerSprite);
	}
	if (m_dead && m_deathSplosionSize < 100)
	{
		window.draw(m_deathSplosion);
	}
}

MyVector3D Player::getPos()
{
	return m_position;
}

int Player::getRadius()
{
	return m_radius;
}

void Player::reset()
{
	m_position = MyVector3D(SCR_W / 2, SCR_H / 2, 0);
	m_acceleration = m_boostLevel * 0.1;
	m_fuel = 300 + m_fuelLevel * 50;
	m_currHold = 0;
	m_dead = false;
}

void Player::move()
{
	if (m_fuel > 0)
	{
		double x = std::sin(m_rotation * PI / 180.0);
		double y = -std::cos(m_rotation * PI / 180.0);

		m_accelerationVector = MyVector3D(x, y, 0);

		m_velocity += m_accelerationVector * m_acceleration;

		m_fuel--;
		m_isMoving = true;
	}
}

double Player::getRotation()
{
	return m_rotation;
}

void Player::rotate(bool turnLeft)
{
	if (turnLeft)
	{
		m_rotation -= m_turnRate;
		m_playerSprite.setRotation(m_rotation);
	}
	if (!turnLeft)
	{
		m_rotation += m_turnRate;
		m_playerSprite.setRotation(m_rotation);
	}
}