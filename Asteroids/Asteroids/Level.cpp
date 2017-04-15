#include "Level.h"

void Level::init()
{
	m_player.init();
}

void Level::update()
{
	m_player.update();
}

void Level::movePlayer()
{
	m_player.move();
}

void Level::rotatePlayer(bool rotateLeft)
{
	m_player.rotate(rotateLeft);
}

void Level::fireUp()
{
	m_player.fireUp();
}

void Level::boostUp()
{
	m_player.boostUp();
}

void Level::armourUp()
{
	m_player.armourUp();
}

void Level::capacityUp()
{
	m_player.capacityUp();
}

void Level::shieldUp()
{
	m_player.shieldUp();
}

void Level::fuelUp()
{
	m_player.fuelUp();
}

void Level::levelSetup()
{
	m_player.reset();
}

void Level::render(sf::RenderWindow & window)
{
	m_player.render(window);
	drawAsteroids(window);

}

void Level::drawAsteroids(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroids[i].render(window);
	}
}


