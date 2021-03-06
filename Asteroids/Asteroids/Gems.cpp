#include "Gems.h"

Gems::Gems()
{
	for (int i = 0; i < 5; i++)
	{
		m_isAlive[i] == false;
	}
	m_radius = 16;
}
void Gems::loadContent(int index)
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/gems.png"))
	{
		std::cout << "Error loading gem texture" << std::endl;
	}
	m_texture.setSmooth(1); //smooth like stones on a beach
	m_bodies[index].setTexture(m_texture);
	m_bodies[index].setOrigin(16,16);

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
	rotate();
}

void Gems::render(sf::RenderWindow &window)
{
	for (int i = 0; i < 5; i++)
	{
		if (m_isAlive[i])
		{
			window.draw(m_bodies[i]);
		}
	}
}
/// <summary>
/// function spawning gem, we do not load assets or anything until this point since it would be unnececery
/// </summary>
/// <param name="index"></param>
/// <param name="deadAsteroidPos"></param>
void Gems::spawn(int index, sf::Vector2f deadAsteroidPos)
{
	loadContent(index);
	init(index);
	m_bodies[index].setPosition(deadAsteroidPos);
	m_isAlive[index] = true;

}

void Gems::rotate()
{
	for (int i = 0; i < 5; i++)
	{
		if (m_isAlive[i])
		{
			m_bodies[i].rotate(1);
		}
	}
}

MyVector3D Gems::getPos(int index)
{
	MyVector3D temp = m_bodies[index].getPosition();
	return temp;
}

int Gems::getRadius()
{
	return m_radius;
}

void Gems::reset()
{
	//
}

void Gems::setPosition(MyVector3D newPos, int index)
{
	m_bodies[index].setPosition(newPos);
}

bool Gems::getAlive(int index)
{
	return m_isAlive[index];
}
