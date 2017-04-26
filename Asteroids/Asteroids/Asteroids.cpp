#include "Asteroids.h"

Asteroids::Asteroids()
{
	//TODO: Dion, maybe the max speed is too high at the moment
	double x = float(rand()) / float(RAND_MAX) * 5 - 2.5f ;
	double y = float(rand()) / float(RAND_MAX) * 5 - 2.5f ;
	m_speed = MyVector3D(x, y, 0);
	spawnAsteroids();
}

Asteroids::~Asteroids()
{
}

bool Asteroids::getActive()
{
	return m_isActive;
}

void Asteroids::setActive(bool newActive)
{
	m_isActive = false;
}



int Asteroids::getRadius()
{
	return m_radius;
}

void Asteroids::setAllOffScr(sf::Vector2f &pos, sf::Sprite &sprite)
{
	pos = { -OFF_SCR_OFFSET * 2, -OFF_SCR_OFFSET * 2 };
	sprite.setPosition(pos);
}

void Asteroids::loadContent()
{
	switch (m_type)
	{
	case 1:
		if (!m_largeTexture.loadFromFile("ASSETS/IMAGES/asteroid3.png"))
		{
			std::cout << "Error loading big asteroid texture" << std::endl;
		}
		m_largeSprite.setTexture(m_largeTexture);
		m_largeSprite.setOrigin(64, 64);
		break;
	case 2:
		if (!m_medTexture.loadFromFile("ASSETS/IMAGES/asteroid2.png"))
		{
			std::cout << "Error loading medium asteroid texture" << std::endl;
		}
		m_medSprite.setTexture(m_medTexture);
		m_medSprite.setOrigin(48, 48);
		break;
	case 3:
		if (!m_smallTexture.loadFromFile("ASSETS/IMAGES/asteroid1.png"))
		{
			std::cout << "Error loading small asteroid texture" << std::endl;
		}
		m_smallSprite.setTexture(m_smallTexture);
		m_smallSprite.setOrigin(32, 32);
		break;
	case 4:
		if (!m_tinyTexture.loadFromFile("ASSETS/IMAGES/asteroid0.png"))
		{
			std::cout << "Error loading tiny asteroid texture" << std::endl;
		}
		m_tinySprite.setTexture(m_tinyTexture);
		m_tinySprite.setOrigin(16, 16);
		break;
	}
}

///TODO: Dion, ensure asteroids do not spawn in the centre of the screen where the player is
void Asteroids::spawnAsteroids()
{
	double x = rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
	double y = rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
	m_position = MyVector3D(x, y, 0);
}

void Asteroids::setupType(int type)
{
	m_type = type;

	switch (m_type)
	{
	case 1:
		m_radius = 64;
		break;
	case 2:
		m_radius = 48;
		break;
	case 3:
		m_radius = 32;
		break;
	case 4:
		m_radius = 16;
		break;
	}

	loadContent();
}


void Asteroids::init()
{
	spawnAsteroids();
}

void Asteroids::render(sf::RenderWindow & window)
{
	//if (m_isActive)
	//{
		switch (m_type)
		{
		case 1:
			m_largeSprite.setPosition(m_position);
			window.draw(m_largeSprite);
			break;
		case 2:
			m_medSprite.setPosition(m_position);
			window.draw(m_medSprite);
			break;
		case 3:
			m_smallSprite.setPosition(m_position);
			window.draw(m_smallSprite);
			break;
		case 4:
			m_tinySprite.setPosition(m_position);
			window.draw(m_tinySprite);
			break;
		}
	//}
}

void Asteroids::update()
{
	movement();
	screenWrap();
}

void Asteroids::movement()
{
	m_position += m_speed;
}
///TODO: Dion, maybe where type is set have a local variable that takes the place
///of the sprite and pos variable for that type, then pass those into all these functions
///to avoid repeated very similar code blocks repeated within the switch.
///The mess / ineficiency is most evident in this next function. But works for now
void Asteroids::screenWrap()
{
	if (m_position.X() < -OFF_SCR_OFFSET * 2)
	{
		m_position = MyVector3D(SCR_W + OFF_SCR_OFFSET * 2, m_position.Y(), 0);
	}
	if (m_position.X() > SCR_W + OFF_SCR_OFFSET)
	{
		m_position = MyVector3D(-OFF_SCR_OFFSET * 2, m_position.Y(), 0);
	}
	if (m_position.Y() < -OFF_SCR_OFFSET * 2)
	{
		m_position = MyVector3D(m_position.X(), SCR_H + OFF_SCR_OFFSET * 2, 0);
	}
	if (m_position.Y() > SCR_H + OFF_SCR_OFFSET)
	{
		m_position = MyVector3D(m_position.X(), -OFF_SCR_OFFSET * 2, 0);
	}
}

MyVector3D Asteroids::getPos()
{
	return m_position;
}
