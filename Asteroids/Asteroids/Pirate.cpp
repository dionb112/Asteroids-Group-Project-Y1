#include "Pirate.h"

Pirate::Pirate()
{
}

Pirate::~Pirate()
{
}

MyVector3D Pirate::getPos()
{
	return MyVector3D();
}

void Pirate::loadContent()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\enemyship64.png"))
	{
		std::cout << "problem loading pirate texture";
	}
	m_sprite.setTexture(m_texture);
}

void Pirate::init()
{
	loadContent();
	m_textureRect.width = 64;
	m_textureRect.height = 64;
	m_sprite.setTextureRect(m_textureRect);

	m_sprite.setOrigin(32, 32);

	m_sprite.setPosition(rand() % (SCR_W + OFF_SCR_OFFSET) - OFF_SCR_OFFSET, rand() % (SCR_H + OFF_SCR_OFFSET) - OFF_SCR_OFFSET);

	m_velocity = sf::Vector2f(0, 0);
	m_turnRate = 4;
	m_acceleration = 0.15;
	m_rotation = 0;
	m_isMoving = false;
	m_isRotating = false;
}

void Pirate::setMoving(bool newBool)
{
	m_isMoving = newBool;
}
void Pirate::setRotating(bool newBool)
{
	m_isRotating = newBool;
}

sf::Sprite Pirate::getBody()
{
	return m_sprite;
}

double Pirate::getRotation()
{
	return m_rotation;
}

void Pirate::update()
{
	if (m_isMoving)
	{
		move();
	}
	if (m_isRotating)
	{
		rotate();
	}
	screenWrap();
	friction();
}

void Pirate::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Pirate::spawn()
{

}

void Pirate::move()
{
	double x = std::sin(m_rotation * PI / 180.0);
	double y = -std::cos(m_rotation * PI / 180.0);

	m_accelerationVector = sf::Vector2f(x, y);
	m_velocity += m_accelerationVector * m_acceleration;


}

void Pirate::friction()
{
	m_velocity = m_velocity * 0.99;
	m_sprite.move(m_velocity);
}


void Pirate::screenWrap()
{
	if (m_sprite.getPosition().x < 0)
	{
		m_sprite.setPosition(SCR_W, m_sprite.getPosition().y);
	}
	if (m_sprite.getPosition().x > SCR_W)
	{
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	}
	if (m_sprite.getPosition().y < 0)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, SCR_H);
	}
	if (m_sprite.getPosition().y > SCR_H)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 0);
	}

}

void Pirate::rotate()
{
	int direction = rand() % 2 + 1;
	if (direction == 1)
	{
		m_rotation -= m_turnRate;
		m_sprite.setRotation(m_rotation);
	}
	else if (direction == 2)
	{
		m_rotation += m_turnRate;
		m_sprite.setRotation(m_rotation);
	}
}

void Pirate::reset()
{
	m_sprite.setPosition(rand() % (SCR_W + OFF_SCR_OFFSET) - OFF_SCR_OFFSET, rand() % (SCR_H + OFF_SCR_OFFSET) - OFF_SCR_OFFSET);
	m_acceleration = 0.15;
}
