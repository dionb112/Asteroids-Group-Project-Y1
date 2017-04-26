#include "Level.h"

void Level::init()
{
	player.init();
	setAsteroidType();
	pirate.init();
	m_counter = 0;
	m_prevBehaviour = 0;

	//for testing stuff easier
	levelData[0].largeAst	= 2;
	levelData[0].medAst		= 2;
	levelData[0].smallAst	= 2;
	levelData[0].tinyAst	= 2;

	levelData[1].largeAst	= 0;
	levelData[1].medAst		= 2;
	levelData[1].smallAst	= 1;
	levelData[1].tinyAst	= 1;

	levelData[2].largeAst	= 1;
	levelData[2].medAst		= 1;
	levelData[2].smallAst	= 2;
	levelData[2].tinyAst	= 0;

	levelData[3].largeAst	= 1;
	levelData[3].medAst		= 2;
	levelData[3].smallAst	= 2;
	levelData[3].tinyAst	= 1;

	levelData[4].largeAst	= 2;
	levelData[4].medAst		= 2;
	levelData[4].smallAst	= 2;
	levelData[4].tinyAst	= 2;
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
	//if (!enemyBullet.getActive())
	//{
	//	enemyBullet.setPosition(pirate.getPos());
	//	enemyBullet.setVelocity(pirate.getRotation());
	//}
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

void Level::levelSetup(int currLevel)
{
	player.reset();
	pirate.reset();
	gems.reset(); // this one does nothing atm
	asteroidsSetup(currLevel);
	playerBullet.setActive(false);
	enemyBullet.setActive(false);
}

void Level::asteroidsSetup(int currLevel)
{
	//These first 4 for loops reset all of the asteroid arrays to false so that we can set up the level with the last 4 for loops
	for (int i = 0; i < 2; i++)
	{
		largeAsteroids[i].setActive(false);
	}
	for (int i = 0; i < 6; i++)
	{
		medAsteroids[i].setActive(false);
	}
	for (int i = 0; i < 16; i++)
	{
		smallAsteroids[i].setActive(false);
	}
	for (int i = 0; i < 36; i++)
	{
		tinyAsteroids[i].setActive(false);
	}

	//These 4 for loops set up the level with the amount of asteroids it needs
	for (int i = 0; i < levelData[currLevel].largeAst; i++)
	{
		largeAsteroids[i].setActive(true);
	}
	for (int i = 0; i < levelData[currLevel].medAst; i++)
	{
		medAsteroids[i].setActive(true);
	}
	for (int i = 0; i < levelData[currLevel].smallAst; i++)
	{
		smallAsteroids[i].setActive(true);
	}
	for (int i = 0; i < levelData[currLevel].tinyAst; i++)
	{
		tinyAsteroids[i].setActive(true);
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
	setAsteroidType();
}

void Level::updateAsteroids()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		if (largeAsteroids[i].getActive())
		{
			largeAsteroids[i].update();
		}
	}
	for (int i = 0; i < MAX_ASTEROIDS + 4; i++)
	{
		if (medAsteroids[i].getActive())
		{
			medAsteroids[i].update();
		}
	}
	for (int i = 0; i < MAX_ASTEROIDS + 14; i++)
	{
		if (smallAsteroids[i].getActive())
		{
			smallAsteroids[i].update();
		}
	}
	for (int i = 0; i < MAX_ASTEROIDS + 34; i++)
	{
		if (tinyAsteroids[i].getActive())
		{
			tinyAsteroids[i].update();
		}
	}
}

void Level::drawAsteroids(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		largeAsteroids[i].render(window);
	}
	for (int i = 0; i < MAX_ASTEROIDS + 4; i++)
	{
		medAsteroids[i].render(window);
	}
	for (int i = 0; i < MAX_ASTEROIDS + 14; i++)
	{
		smallAsteroids[i].render(window);
	}
	for (int i = 0; i < MAX_ASTEROIDS +34; i++)
	{
		tinyAsteroids[i].render(window);
	}
}


/// <summary>
/// spawning gems for first level, called upon tiny deletion
/// on Earth level, orange, red and purple have 10% spawn chance
/// green has 30% and blue has 0%
/// </summary>
void Level::spawnGem(int deadTiny)
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
		gems.spawn(index, tinyAsteroids[deadTiny].getPos());//spawn that gem
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
		if (isColliding(player.getPos(), player.getRadius(), largeAsteroids[i].getPos(), largeAsteroids[i].getRadius()) && largeAsteroids[i].getActive())
		{
			std::cout << "player hit large asteroid" << std::endl;

		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), medAsteroids[i].getPos(), medAsteroids[i].getRadius()) && medAsteroids[i].getActive())
		{
			std::cout << "player hit med asteroid" << std::endl;

		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), smallAsteroids[i].getPos(), smallAsteroids[i].getRadius()) && smallAsteroids[i].getActive())
		{
			std::cout << "player hit small asteroid" << std::endl;

		}
	}
	for (int i = 0; i < 36; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), tinyAsteroids[i].getPos(), tinyAsteroids[i].getRadius()) && tinyAsteroids[i].getActive())
		{
			std::cout << "player hit tiny asteroid" << std::endl;

		}
	}		
	
	for (int i = 0; i < 5; i++)
	{
		if (isColliding(player.getPos(), player.getRadius(), gems.getPos(i), gems.getRadius()))
		{
			std::cout << "hit a gem" << std::endl;
		}
	}
}

void Level::bulletCollsions()
{
	if (playerBullet.getActive())
	{
		for (int i = 0; i < 2; i++)
		{
			if (isColliding(playerBullet.getPos(), player.getRadius(), largeAsteroids[i].getPos(), largeAsteroids[i].getRadius()) && largeAsteroids[i].getActive())
			{
				std::cout << "bullet hit Large" << std::endl;
				largeAsteroids[i].setActive(false);
				addMed(i);
				largeAsteroids[i].setOffScr();
				playerBullet.setActive(false);
			}
		}
	}
	if (playerBullet.getActive())
	{
		for (int i = 0; i < 6; i++)
		{
			if (isColliding(playerBullet.getPos(), player.getRadius(), medAsteroids[i].getPos(), medAsteroids[i].getRadius()) && medAsteroids[i].getActive())
			{
				std::cout << "bullet hit med" << std::endl;
				medAsteroids[i].setActive(false);
				addSmall(i);
				medAsteroids[i].setOffScr();
				playerBullet.setActive(false);
			}
		}
	}
	if (playerBullet.getActive())
	{
		for (int i = 0; i < 16; i++)
		{
			if (isColliding(playerBullet.getPos(), player.getRadius(), smallAsteroids[i].getPos(), smallAsteroids[i].getRadius()) && smallAsteroids[i].getActive())
			{
				std::cout << "bullet hit small" << std::endl;
				smallAsteroids[i].setActive(false);
				addTiny(i);
				smallAsteroids[i].setOffScr();
				playerBullet.setActive(false);
			}
		}
	}
	if (playerBullet.getActive())
	{
		for (int i = 0; i < 36; i++)
		{
			if (isColliding(playerBullet.getPos(), player.getRadius(), tinyAsteroids[i].getPos(), tinyAsteroids[i].getRadius()) && tinyAsteroids[i].getActive())
			{
				std::cout << "bullet hit tiny" << std::endl;
				tinyAsteroids[i].setActive(false);
				spawnGem(i);
				tinyAsteroids[i].setOffScr();
				playerBullet.setActive(false);
			}
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

void Level::addMed(int deadLarge)
{
	for (int i = 0; i < MAX_ASTEROIDS + 4; i++)
	{
		if (medAsteroids[i].getActive() == false)
		{
			medAsteroids[i].setupType(2);
			medAsteroids[i].loadContent();
			medAsteroids[i].setPos(largeAsteroids[deadLarge].getPos());
			medAsteroids[i].setActive(true);
			std::cout << "2 med added" << std::endl;
		}
	}
}

void Level::addSmall(int deadMed)
{
	for (int i = 0; i < MAX_ASTEROIDS + 14; i++)
	{
		if (smallAsteroids[i].getActive() == false)
		{
			smallAsteroids[i].setupType(3);
			smallAsteroids[i].loadContent();
			smallAsteroids[i].setPos(medAsteroids[deadMed].getPos());
			smallAsteroids[i].setActive(true);
			std::cout << "2 small added" << std::endl;
		}
	}
}

void Level::addTiny(int deadSmall)
{
	for (int i = 0; i < MAX_ASTEROIDS + 34; i++)
	{
		if (tinyAsteroids[i].getActive() == false)
		{
			tinyAsteroids[i].setupType(4);
			tinyAsteroids[i].loadContent();
			tinyAsteroids[i].setPos(smallAsteroids[deadSmall].getPos());
			tinyAsteroids[i].setActive(true);
			std::cout << "2 tiny added" << std::endl;
		}
	}
}
