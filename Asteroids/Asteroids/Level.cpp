#include "Level.h"

void Level::init()
{
	player.init();
	initAsteroids();
	pirate.init();
	m_counter = 0;
	m_prevBehaviour = 0;
}

void Level::update()
{
	player.update();
	playerBullet.update();
	enemyBullet.update();
	updateAsteroids();
	gems.update();
	pirate.update();
	actionManager();

	collisions();
}

void Level::render(sf::RenderWindow & window)
{
	player.render(window);
	playerBullet.render(window);
	enemyBullet.render(window);
	drawAsteroids(window);
	gems.render(window);
	pirate.render(window);
}

void Level::movePlayer()
{
	player.move();
}

void Level::rotatePlayer(bool rotateLeft)
{
	player.rotate(rotateLeft);
}

void Level::actionManager()
{
	m_counter++;
	if (m_counter == 120)
	{
		pirate.setMoving(false);
		pirate.setRotating(false);

		int currBehaviour = rand() % 3 + 1;
		
		if (currBehaviour == 1)
		{
			pirate.setMoving(true);
		}
		else if (currBehaviour == 2)
		{
			pirate.setRotating(true);
		}
		else if (currBehaviour == 3)
		{
			enemyShoot();
		}
		m_counter = 0;
	}
}

void Level::enemyShoot()
{
	/*if (!enemyBullet.getActive())
	{
		enemyBullet.setPosition(pirate.getBody().getPosition().x, pirate.getBody().getPosition().y);
		enemyBullet.setVelocity(pirate.getRotation());
	}*/
}

void Level::playerShoot()
{
	if (!playerBullet.getActive())
	{
		playerBullet.setPosition(player.getPos());
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


void Level::setNoOfAsteroids()
{
	m_noOfLarge = MAX_ASTEROIDS;
	m_noOfMed = MAX_ASTEROIDS;
	m_noOfSmall = MAX_ASTEROIDS;
	m_noOfTiny = MAX_ASTEROIDS;
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
	setNoOfAsteroids();
	setAsteroidType();
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
	for (int i = 0; i < m_noOfLarge; i++)
	{
		largeAsteroids[i].update();
	}
	for (int i = 0; i < m_noOfMed; i++)
	{
		medAsteroids[i].update();
	}
	for (int i = 0; i < m_noOfSmall; i++)
	{
		smallAsteroids[i].update();
	}
	for (int i = 0; i < m_noOfTiny; i++)
	{
		tinyAsteroids[i].update();
	}
}

void Level::drawAsteroids(sf::RenderWindow & window)
{
	for (int i = 0; i < m_noOfLarge; i++)
	{
		largeAsteroids[i].render(window);
	}
	for (int i = 0; i < m_noOfMed; i++)
	{
		medAsteroids[i].render(window);
	}
	for (int i = 0; i < m_noOfSmall; i++)
	{
		smallAsteroids[i].render(window);
	}
	for (int i = 0; i < m_noOfTiny; i++)
	{
		tinyAsteroids[i].render(window);
	}
}

/// <summary>
/// These functions are all seperated to allow for more effecient calling. Rather than calling one big arraysManager function and passing around a bunch of variables every time any collision of any type happens
/// There is no function for add large since there is no bigger asteroid to destroy giving two large
/// </summary>
void Level::deleteLarge()
{
	if (m_noOfLarge > 0)
	{
		m_noOfLarge--;
		std::cout << "1 large removed" << std::endl;
	}
}

void Level::deleteMed()
{
	if (m_noOfMed > 0)
	{
		m_noOfMed--;
		std::cout << "1 med removed" << std::endl;
	}
}

void Level::deleteSmall()
{
	if (m_noOfSmall > 0)
	{
		m_noOfSmall--;
		std::cout << "1 small removed" << std::endl;
	}
}

void Level::deleteTiny()
{
	if (m_noOfTiny > 0)
	{
		spawnGem();
		m_noOfTiny--;
		std::cout << "1 tiny removed" << std::endl;

	}
}

/// <summary>
/// spawning gems for first level, called upon tiny deletion
/// on Earth level, orange, red and purple have 10% spawn chance
/// green has 30% and blue has 0%
/// </summary>
void Level::spawnGem()
{
	int index = -1;
	int random = rand() % 10 + 1;
	if (random <= 6)
	{
		int gemType = rand() % 6 + 1; //combined chance of any spawn is 60% so check if any have spawned, then we check individually which has spawned
		if (gemType == 1)
		{
			index = 0;
		}
		else if (gemType == 2)
		{
			index = 1;
		}
		else if (gemType == 3)
		{
			index = 2;
		}
		else if (gemType > 3)
		{
			index = 3;
		}
		gems.spawn(index, tinyAsteroids[m_noOfTiny].getPos());//spawn that gem
	}

}

void Level::collisions()
{
	playerCollisions();

	if (playerBullet.getActive())
	{
		bulletCollsions();
	}

	pirateCollsions();
}

void Level::playerCollisions()
{
	for (int i = 0; i < 2; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), largeAsteroids[i].getPos(), largeAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), medAsteroids[i].getPos(), medAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), smallAsteroids[i].getPos(), smallAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 36; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), tinyAsteroids[i].getPos(), tinyAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}

	/*for (int i = 0; i < 5; i++)
	{
		if (isColliding(playerX, playerY, player.getRadius(), gemX, gemY, gems.getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}*/
}

void Level::bulletCollsions()
{
	for (int i = 0; i < 2; i++)
	{
		if (isColliding(playerBullet.getPos(), player.getRadius(), largeAsteroids[i].getPos(), largeAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (isColliding(playerBullet.getPos(), player.getRadius(), medAsteroids[i].getPos(), medAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (isColliding(playerBullet.getPos(), player.getRadius(), smallAsteroids[i].getPos(), smallAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
	for (int i = 0; i < 36; i++)
	{
		if (isColliding(playerBullet.getPos(), player.getRadius(), tinyAsteroids[i].getPos(), tinyAsteroids[i].getRadius()))
		{
			std::cout << "hit" << std::endl;
		}
	}
}

void Level::pirateCollsions()
{

}

bool Level::isColliding(MyVector3D pos1, int rad1, MyVector3D pos2, int rad2)
{
	MyVector3D pos3 = pos1 - pos2;
	int distance = pos3.length();

	if (distance < rad1 + rad2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Level::addMed()
{
	if (m_noOfMed < MAX_ASTEROIDS + 4)
	{
		medAsteroids[m_noOfMed].setupType(2);
		medAsteroids[m_noOfMed].loadContent();
		medAsteroids[m_noOfMed].spawnAsteroids();
		m_noOfMed = m_noOfMed + 2;
		std::cout << "2 med added" << std::endl;
	}
}

void Level::addSmall()
{
	if (m_noOfSmall < MAX_ASTEROIDS + 14)
	{
		smallAsteroids[m_noOfSmall].setupType(3);
		smallAsteroids[m_noOfSmall].loadContent();
		smallAsteroids[m_noOfSmall].spawnAsteroids();
		m_noOfSmall = m_noOfSmall + 2;
		std::cout << "2 small added" << std::endl;
	}
}

void Level::addTiny()
{
	if (m_noOfTiny < MAX_ASTEROIDS + 34)
	{
		tinyAsteroids[m_noOfTiny].setupType(4);
		tinyAsteroids[m_noOfTiny].loadContent();
		tinyAsteroids[m_noOfTiny].spawnAsteroids();
		m_noOfTiny = m_noOfTiny+2;
		std::cout << "2 tiny added" << std::endl;
	}
}
