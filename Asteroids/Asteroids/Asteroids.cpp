#include "Asteroids.h"

Asteroids::Asteroids()
{
	//TODO: Dion, maybe the max speed is too high at the moment
	m_speed.x = float(rand()) / float(RAND_MAX) * 5 - 2.5f ;
	m_speed.y = float(rand()) / float(RAND_MAX) * 5 - 2.5f ;
	setAllOffScr(m_largePos, m_largeSprite);
	setAllOffScr(m_medPos, m_medSprite);
	setAllOffScr(m_smallPos, m_smallSprite);
	setAllOffScr(m_tinyPos, m_tinySprite);
}

Asteroids::~Asteroids()
{
}

sf::Vector2f Asteroids::getPos()
{
	sf::Vector2f pos;
	switch (m_type)
	{
	case 1:
		pos = m_largePos;
		break;
	case 2:
		pos = m_medPos;
		break;
	case 3:
		pos = m_smallPos;
		break;
	case 4:
		pos = m_tinyPos;
		break;
	}
	return pos;
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
		break;
	case 2:
		if (!m_medTexture.loadFromFile("ASSETS/IMAGES/asteroid2.png"))
		{
			std::cout << "Error loading medium asteroid texture" << std::endl;
		}
		m_medSprite.setTexture(m_medTexture);
		break;
	case 3:
		if (!m_smallTexture.loadFromFile("ASSETS/IMAGES/asteroid1.png"))
		{
			std::cout << "Error loading small asteroid texture" << std::endl;
		}
		m_smallSprite.setTexture(m_smallTexture);
		break;
	case 4:
		if (!m_tinyTexture.loadFromFile("ASSETS/IMAGES/asteroid0.png"))
		{
			std::cout << "Error loading tiny asteroid texture" << std::endl;
		}
		m_tinySprite.setTexture(m_tinyTexture);
		break;
	}
}

///TODO: Dion, ensure asteroids do not spawn in the centre of the screen where the player is
void Asteroids::spawnAsteroids()
{
	switch (m_type)
	{
	case 1:
		m_largePos.x = rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_largePos.y = rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_largeSprite.setPosition(m_largePos);
		break;
	case 2:
		m_medPos.x = rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_medPos.y = rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_medSprite.setPosition(m_medPos);
		break;
	case 3:
		m_smallPos.x = rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_smallPos.y = rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_smallSprite.setPosition(m_smallPos);
		break;
	case 4:
		m_tinyPos.x = rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_tinyPos.y = rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET;
		m_tinySprite.setPosition(m_tinyPos);
		break;
	}
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
}


void Asteroids::init()
{
	loadContent(); 
	spawnAsteroids();
}

void Asteroids::render(sf::RenderWindow & window)
{
	switch (m_type)
	{
	case 1:
		window.draw(m_largeSprite);
		break;
	case 2:
		window.draw(m_medSprite);
		break;
	case 3:
		window.draw(m_smallSprite);
		break;
	case 4:
		window.draw(m_tinySprite);
		break;
	}
}

void Asteroids::update()
{
	movement();
	screenWrap();
}

void Asteroids::movement()
{
	switch (m_type)
	{
	case 1:
		m_largePos += m_speed;
		m_largeSprite.setPosition(m_largePos);
		break;
	case 2:
		m_medPos += m_speed;
		m_medSprite.setPosition(m_medPos);
		break;
	case 3:
		m_smallPos += m_speed;
		m_smallSprite.setPosition(m_smallPos);
		break;
	case 4:
		m_tinyPos += m_speed;
		m_tinySprite.setPosition(m_tinyPos);
		break;
	}
	
}
///TODO: Dion, maybe where type is set have a local variable that takes the place
///of the sprite and pos variable for that type, then pass those into all these functions
///to avoid repeated very similar code blocks repeated within the switch.
///The mess / ineficiency is most evident in this next function. But works for now
void Asteroids::screenWrap()
{
	switch (m_type)
	{
	case 1:
		if (m_largePos.x < -OFF_SCR_OFFSET)
		{
			m_largePos.x=SCR_W + OFF_SCR_OFFSET;
			m_largeSprite.setPosition(m_largePos);
		}
		if (m_largePos.x > SCR_W + OFF_SCR_OFFSET)
		{
			m_largePos.x = -OFF_SCR_OFFSET;
			m_largeSprite.setPosition(m_largePos);
		}
		if (m_largePos.y < -OFF_SCR_OFFSET)
		{
			m_largePos.y = SCR_H + OFF_SCR_OFFSET;
			m_largeSprite.setPosition(m_largePos);
		}
		if (m_largePos.y > SCR_H + OFF_SCR_OFFSET)
		{
			m_largePos.y = -OFF_SCR_OFFSET;
			m_largeSprite.setPosition(m_largePos);
		}
		break;
	case 2:
		if (m_medPos.x < -OFF_SCR_OFFSET)
		{
			m_medPos.x = SCR_W + OFF_SCR_OFFSET;
			m_medSprite.setPosition(m_medPos);
		}
		if (m_medPos.x > SCR_W + OFF_SCR_OFFSET)
		{
			m_largePos.x = -OFF_SCR_OFFSET;
			m_medSprite.setPosition(m_medPos);
		}
		if (m_medPos.y < -OFF_SCR_OFFSET)
		{
			m_medPos.y = SCR_H + OFF_SCR_OFFSET;
			m_medSprite.setPosition(m_medPos);
		}
		if (m_medPos.y > SCR_H + OFF_SCR_OFFSET)
		{
			m_medPos.y = -OFF_SCR_OFFSET;
			m_medSprite.setPosition(m_medPos);
		}
		break;
	case 3:
		if (m_smallPos.x < -OFF_SCR_OFFSET)
		{
			m_smallPos.x = SCR_W + OFF_SCR_OFFSET;
			m_smallSprite.setPosition(m_smallPos);
		}
		if (m_smallPos.x > SCR_W + OFF_SCR_OFFSET)
		{
			m_smallPos.x = -OFF_SCR_OFFSET;
			m_smallSprite.setPosition(m_smallPos);
		}
		if (m_smallPos.y < -OFF_SCR_OFFSET)
		{
			m_smallPos.y = SCR_H + OFF_SCR_OFFSET;
			m_smallSprite.setPosition(m_smallPos);
		}
		if (m_smallPos.y > SCR_H + OFF_SCR_OFFSET)
		{
			m_smallPos.y = -OFF_SCR_OFFSET;
			m_smallSprite.setPosition(m_smallPos);
		}
		break;
	case 4:
		if (m_tinyPos.x < -OFF_SCR_OFFSET)
		{
			m_tinyPos.x = SCR_W + OFF_SCR_OFFSET;
			m_tinySprite.setPosition(m_tinyPos);
		}
		if (m_tinyPos.x > SCR_W + OFF_SCR_OFFSET)
		{
			m_tinyPos.x = -OFF_SCR_OFFSET;
			m_tinySprite.setPosition(m_tinyPos);
		}
		if (m_tinyPos.y < -OFF_SCR_OFFSET)
		{
			m_tinyPos.y = SCR_H + OFF_SCR_OFFSET;
			m_tinySprite.setPosition(m_tinyPos);
		}
		if (m_tinyPos.y > SCR_H + OFF_SCR_OFFSET)
		{
			m_tinyPos.y = -OFF_SCR_OFFSET;
			m_tinySprite.setPosition(m_tinyPos);
		}
		break;
	}
}
