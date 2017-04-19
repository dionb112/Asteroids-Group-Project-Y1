#include "Level.h"

void Level::init()
{
	player.init();
	setAsteroidType();
	initAsteroids();
}

void Level::update()
{
	player.update();
	playerBullet.update();
	updateAsteroids();
}

void Level::movePlayer()
{
	player.move();
}

void Level::rotatePlayer(bool rotateLeft)
{
	player.rotate(rotateLeft);
}

void Level::playerShoot()
{
	if (!playerBullet.getActive())
	{
		playerBullet.setPosition(player.getBody().getPosition().x, player.getBody().getPosition().y);
		playerBullet.setVelocity(player.getRotation());
	}
}

void Level::fireUp()
{
	player.fireUp();
}

void Level::boostUp()
{
	player.boostUp();
}

void Level::armourUp()
{
	player.armourUp();
}

void Level::capacityUp()
{
	player.capacityUp();
}

void Level::shieldUp()
{
	player.shieldUp();
}

void Level::fuelUp()
{
	player.fuelUp();
}

void Level::levelSetup()
{
	player.reset();
}

void Level::render(sf::RenderWindow & window)
{
	player.render(window);
	playerBullet.render(window);
	drawAsteroids(window);

}

void Level::drawAsteroids(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		largeAsteroids[i].render(window);
		medAsteroids[i].render(window);
		smallAsteroids[i].render(window);
		tinyAsteroids[i].render(window);
	}
}

void Level::setAsteroidType()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		largeAsteroids[i].setupType(1);
		medAsteroids[i].setupType(2);
		smallAsteroids[i].setupType(3);
		tinyAsteroids[i].setupType(4);
	}
}

void Level::initAsteroids()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		largeAsteroids[i].init();
		medAsteroids[i].init();
		smallAsteroids[i].init();
		tinyAsteroids[i].init();
	}
}

void Level::updateAsteroids()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		largeAsteroids[i].update();
		medAsteroids[i].update();
		smallAsteroids[i].update();
		tinyAsteroids[i].update();
	}
}


