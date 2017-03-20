#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
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
	m_body.move(m_velocity);
	friction();
	screenWrap();
	std::cout << m_rotation << std::endl;
}

void Player::friction()
{
	m_velocity.x *= 0.99;
	m_velocity.y *= 0.99;
}

void Player::screenWrap()
{
	if (m_body.getPosition().x < 0)
	{
		m_body.setPosition(800, m_body.getPosition().y);
	}
	if (m_body.getPosition().x > 800)
	{
		m_body.setPosition(0, m_body.getPosition().y);
	}
	if (m_body.getPosition().y < 0)
	{
		m_body.setPosition(m_body.getPosition().x, 480);
	}
	if (m_body.getPosition().y > 480)
	{
		m_body.setPosition(m_body.getPosition().x, 0);
	}
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

sf::CircleShape Player::getBody()
{
	return m_body;
}

void Player::move()
{
	
	const float cos = std::cos(m_rotation * PI / 180);
	const float sin = std::sin(m_rotation * PI / 180);
	const double x = (0 * cos) - (-1 * sin);
	const double y = (0 * sin) + (-1 * cos);
	m_accelerationVector = sf::Vector2f(x, y);
	std::cout << "x: " << x << "y: " << y << std::endl;

	//m_velocity.y += m_acceleration;
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
	}
	if (!turnLeft)
	{
		m_rotation += m_turnRate;
	}
}