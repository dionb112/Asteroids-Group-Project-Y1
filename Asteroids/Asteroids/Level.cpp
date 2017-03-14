#include "Level.h"

void Level::init()
{
	m_player.init();
}

void Level::render(sf::RenderWindow & window)
{
	m_player.render(window);
}


