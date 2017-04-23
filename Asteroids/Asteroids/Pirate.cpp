#include "Pirate.h"

Pirate::Pirate()
{
}

Pirate::~Pirate()
{
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

	//m_sprite.setPosition(rand() % (SCR_W + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET, rand() % (SCR_H + OFF_SCR_OFFSET * 2) - OFF_SCR_OFFSET);
	m_sprite.setPosition(100,100);

	m_velocity = sf::Vector2f(0, 0);
	m_turnRate = 4;
	m_acceleration = 0.15;
	m_rotation = 0;
}

void Pirate::update()
{
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
}

void Pirate::screenWrap()
{
}
