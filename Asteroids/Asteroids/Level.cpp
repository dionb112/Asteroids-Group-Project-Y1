#include "Level.h"

void Level::init()
{
	m_player.init();
}

void Level::update()
{
	m_player.update();
}

void Level::movePlayer(bool forward)
{
	m_player.move(forward);
}

void Level::rotatePlayer(double rotate)
{
	m_player.rotate(rotate);
}

void Level::render(sf::RenderWindow & window)
{
	m_player.render(window);
}


