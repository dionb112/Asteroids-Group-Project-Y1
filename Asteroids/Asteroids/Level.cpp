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

void Level::render(sf::RenderWindow & window)
{
	m_player.render(window);
}


