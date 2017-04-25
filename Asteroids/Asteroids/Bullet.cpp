#include "Bullet.h"

Bullet::Bullet()
{
	m_speed = 10;
	m_timer = 0;
	m_active = false;

	m_body.setFillColor(sf::Color::White);
	m_body.setRadius(2);
	m_radius = 2;
}

Bullet::~Bullet()
{
}

void Bullet::setPosition(MyVector3D pos)
{
	m_position = pos;
}

void Bullet::setVelocity(double angle)
{
	double x = std::sin(angle * PI / 180.0);
	double y = -std::cos(angle * PI / 180.0);

	m_velocity = MyVector3D(x, y, 0);

	m_velocity += m_velocity * m_speed;

	m_timer = 60;
	m_active = true;
}

MyVector3D Bullet::getPos()
{
	return m_position;
}

int Bullet::getRadius()
{
	return m_radius;
}

bool Bullet::getActive()
{
	return m_active;
}

void Bullet::update()
{
	if (m_active)
	{
		m_position += m_velocity;
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

void Bullet::render(sf::RenderWindow & window)
{
	if (m_active)
	{
		m_body.setPosition(m_position);
		window.draw(m_body);
	}
}
