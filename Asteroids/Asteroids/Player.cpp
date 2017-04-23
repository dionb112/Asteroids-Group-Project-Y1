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

	m_playerSprite.setOrigin(32, 32);
	m_playerSprite.setPosition(400, 240);

	m_body.setPosition(sf::Vector2f(400, 280));
	m_body.setRadius(10);
	m_body.setFillColor(sf::Color::Green);
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
	m_shieldLevel = 1;
}

void Player::update()
{
	m_playerSprite.move(m_velocity);
	friction();
	animate();
	screenWrap();
}

void Player::friction()
{
	m_velocity.x *= 0.99;
	m_velocity.y *= 0.99;
}

void Player::screenWrap()
{
	if (m_playerSprite.getPosition().x < 0)
	{
		m_playerSprite.setPosition(SCR_W, m_playerSprite.getPosition().y);
	}
	if (m_playerSprite.getPosition().x > SCR_W)
	{
		m_playerSprite.setPosition(0, m_playerSprite.getPosition().y);
	}
	if (m_playerSprite.getPosition().y < 0)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, SCR_H);
	}
	if (m_playerSprite.getPosition().y > SCR_H)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, 0);
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

void Player::shieldUp()
{
	m_shieldLevel++;
	std::cout << "shield: " << m_shieldLevel << std::endl;
}

void Player::fuelUp()
{
	m_fuelLevel++;
	std::cout << "Fuel: " << m_fuelLevel << std::endl;
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_playerSprite);
}

sf::Sprite Player::getBody()
{
	return m_playerSprite;
}

int Player::getRadius()
{
	return m_radius;
}

void Player::reset()
{
	m_playerSprite.setPosition(SCR_W / 2, SCR_H / 2);
	m_acceleration = m_boostLevel * 0.1;
	m_fuel = 300 + m_fuelLevel * 50;
}

void Player::move()
{
	if (m_fuel > 0)
	{
		double x = std::sin(m_rotation * PI / 180.0);
		double y = -std::cos(m_rotation * PI / 180.0);

		m_accelerationVector = sf::Vector2f(x, y);
		std::cout << "x: " << x << "y: " << y << std::endl;
		std::cout << m_rotation << std::endl;

		m_velocity.y += m_accelerationVector.y * m_acceleration;
		m_velocity.x += m_accelerationVector.x * m_acceleration;

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