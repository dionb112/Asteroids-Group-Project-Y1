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
		std::cout << "problem loading WAV file";
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
	m_velocity = sf::Vector2f(0, 0);
	m_turnRate = 0.1;
	m_acceleration = 0.01;
	m_rotation = 0;
}

void Player::update()
{
	m_playerSprite.move(m_velocity);
	friction();
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
		m_playerSprite.setPosition(800, m_playerSprite.getPosition().y);
	}
	if (m_playerSprite.getPosition().x > 800)
	{
		m_playerSprite.setPosition(0, m_playerSprite.getPosition().y);
	}
	if (m_playerSprite.getPosition().y < 0)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, 480);
	}
	if (m_playerSprite.getPosition().y > 480)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, 0);
	}
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_playerSprite);
}

sf::Sprite Player::getBody()
{
	return m_playerSprite;
}

void Player::move()
{
	//Note:
	//Sin and cos are not giving the appropriate values.
	//The vakues are close to what they should be but
	//after rotating the ship around 3 or 4 times you 
	//start to see a major difference in what it should be
	//I'm still not sure why this is happening.
	//eg: for a rotation of 1080 (3 spins) the results are
	//x: -0.750987 and y : -0.660317
	//whereas it should be
	//x: 0 and y: 1

	//it's k I just dumb! All is well with the world now
	double x = std::sin(m_rotation * PI / 180.0);
	double y = -std::cos(m_rotation * PI / 180.0);

	m_accelerationVector = sf::Vector2f(x, y);
	std::cout << "x: " << x << "y: " << y << std::endl;
	std::cout << m_rotation << std::endl;

	m_velocity.y += m_accelerationVector.y * m_acceleration;
	m_velocity.x += m_accelerationVector.x * m_acceleration;

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