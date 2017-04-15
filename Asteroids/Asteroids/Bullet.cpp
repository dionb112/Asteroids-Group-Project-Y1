#include "Bullet.h"

Bullet::Bullet()
{
	m_speed = 10;
	m_timer = 0;
	m_active = false;

	m_body.setFillColor(sf::Color::White);
	m_body.setRadius(2);
}

Bullet::~Bullet()
{
}

void Bullet::setPosition(double x, double y)
{
	m_body.setPosition(x, y);
}

void Bullet::setVelocity(double angle)
{
	double x = std::sin(angle * PI / 180.0);
	double y = -std::cos(angle * PI / 180.0);

	m_velocity = sf::Vector2f(x, y);

	m_velocity.y += m_velocity.y * m_speed;
	m_velocity.x += m_velocity.x * m_speed;

	m_timer = 60;
	m_active = true;
}

sf::CircleShape Bullet::getBody()
{
	return m_body;
}

bool Bullet::getActive()
{
	return m_active;
}

void Bullet::update()
{
	if (m_active)
	{
		m_body.move(m_velocity);
		screenWrap();

		m_timer--;
		if (m_timer <= 0)
		{
			m_active = false;
		}
	}
}

void Bullet::screenWrap()
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

void Bullet::render(sf::RenderWindow & window)
{
	if (m_active)
	{
		window.draw(m_body);
	}
}
