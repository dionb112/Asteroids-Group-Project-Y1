#include "Gems.h"

Gems::Gems()
{
	for (int i = 0; i < 5; i++)
	{
		isAlive[i] == false;
	}
	m_radius = 16;
}
void Gems::loadContent(int index)
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/gems.png"))
	{
		std::cout << "Error loading gem texture" << std::endl;
	}
	m_bodies[index].setTexture(m_texture);
}

void Gems::init(int index )
{
	if (index == 0)
	{
		sf::IntRect textureArea(0, 0, 32, 32);
		m_bodies[index].setTextureRect(textureArea);
	}
	else if (index == 1)
	{
		sf::IntRect textureArea(32, 0, 32, 32);
		m_bodies[index].setTextureRect(textureArea);
	}
	else if (index == 2)
	{
		sf::IntRect textureArea(64, 0, 32, 32);
		m_bodies[index].setTextureRect(textureArea);
	}
	else if (index == 3)
	{
		sf::IntRect textureArea(96, 0, 32, 32);
		m_bodies[index].setTextureRect(textureArea);
	}
	else if (index == 4)
	{
		sf::IntRect textureArea(128, 0, 32, 32);
		m_bodies[index].setTextureRect(textureArea);
	}
}

void Gems::update()
{
	for (int i = 0; i < 5; i++)
	{
		if (isAlive[i])
		{
			rotate();
		}
	}
}

void Gems::render(sf::RenderWindow &window)
{
	for (int i = 0; i < 5; i++)
	{
		if (isAlive[i])
		{
			window.draw(m_bodies[i]);
		}
	}
}

void Gems::spawn(int index, sf::Vector2f deadAsteroidPos)
{
	loadContent(index);
	init(index);
	m_bodies[index].setPosition(deadAsteroidPos);
	isAlive[index] = true;

}

void Gems::rotate()
{
}

int Gems::getRadius()
{
	return m_radius;
}
