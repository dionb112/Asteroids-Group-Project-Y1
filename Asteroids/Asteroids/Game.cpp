#include "Game.h"

Game::Game() : m_window(sf::VideoMode(800, 480), "Asteroids")
{
}

Game::~Game()
{
}


void Game::loadContent()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
}

void Game::init()
{
	currScreen = (MenuScreen::License);
	m_licenseTime = 120; //set back to 260 when finished
	m_menuDelay = 0;
	license.init(m_font);
	splash.init(m_font);
	mainMenu.init(m_font);
	levelSelect.init(m_font);
	help.init(m_font);
	upgrade.init(m_font);
	level.init();
	m_levelSelect = -1;
}

void Game::run()
{
	loadContent();
	init();
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	while (m_window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update();
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (currScreen != MenuScreen::License && currScreen != MenuScreen::Level)
		{ 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_menuDelay <= 0)
			{
				m_window.close();
			}
		}
		if (m_menuDelay <= 0)
		{
			if (currScreen == MenuScreen::Splash)
			{
				processSplashEvents();
			}
		}
		if (m_menuDelay <= 0)
		{
			if (currScreen == MenuScreen::MainMenu)
			{
				processMainMenuEvents();
			}
		}
		if (m_menuDelay <= 0)
		{
			if (currScreen == MenuScreen::LevelSelect)
			{
				processLevelSelectEvents();
			}
		}
		if (m_menuDelay <= 0)
		{
			if (currScreen == MenuScreen::Help)
			{
				processHelpEvents();
			}
		}
		if (m_menuDelay <= 0)
		{
			if (currScreen == MenuScreen::Upgrade)
			{
				processUpgradeEvents();
			}
		}
	}
	
	if (currScreen == MenuScreen::Level)
	{
		processLevelEvents();
	}
}

void Game::processSplashEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
		m_menuDelay = DELAY;
	}
}

void Game::processMainMenuEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		currScreen = MenuScreen::LevelSelect;
		m_menuDelay = DELAY;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		currScreen = MenuScreen::Upgrade;

		upgrade.updateCredits(level.getCredits());
		upgrade.updateCost(getCost());
		upgrade.updateArmour(level.getArmourLevel());
		upgrade.updateBoost(level.getBoostLevel());
		upgrade.updateCapacity(level.getCapacityLevel());
		upgrade.updateFire(level.getFireLevel());
		upgrade.updateFuel(level.getFuelLevel());


		m_menuDelay = DELAY;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		currScreen = MenuScreen::Help;
		m_menuDelay = DELAY;
	}
}

void Game::processLevelSelectEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
		m_levelSelect = -1;
		levelSelect.setPlanet(m_levelSelect);
		m_menuDelay = DELAY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (m_levelSelect != -1)
		{
			level.levelSetup(m_levelSelect);
			currScreen = MenuScreen::Level;
			m_menuDelay = DELAY;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		m_levelSelect = 0;
		levelSelect.setPlanet(m_levelSelect);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		m_levelSelect = 1;
		levelSelect.setPlanet(m_levelSelect);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		m_levelSelect = 2;
		levelSelect.setPlanet(m_levelSelect);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		m_levelSelect = 3;
		levelSelect.setPlanet(m_levelSelect);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		m_levelSelect = 4;
		levelSelect.setPlanet(m_levelSelect);
	}
}

void Game::processHelpEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
		m_menuDelay = DELAY;
	}
}

void Game::processUpgradeEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
		m_menuDelay = DELAY;
	}

	if (getCost() <= level.getCredits())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			level.addCredits(-getCost());
			level.fireUp();
			upgrade.updateCredits(level.getCredits());
			upgrade.updateFire(level.getFireLevel());
			upgrade.updateCost(getCost());
			m_menuDelay = DELAY;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			level.addCredits(-getCost());
			upgrade.updateCredits(level.getCredits());
			level.boostUp();
			upgrade.updateBoost(level.getBoostLevel());
			upgrade.updateCost(getCost());
			m_menuDelay = DELAY;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			level.addCredits(-getCost());
			upgrade.updateCredits(level.getCredits());
			level.armourUp();
			upgrade.updateArmour(level.getArmourLevel());
			upgrade.updateCost(getCost());
			m_menuDelay = DELAY;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			level.addCredits(-getCost());
			upgrade.updateCredits(level.getCredits());
			level.capacityUp();
			upgrade.updateCapacity(level.getCapacityLevel());
			upgrade.updateCost(getCost());
			m_menuDelay = DELAY;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			level.addCredits(-getCost());
			upgrade.updateCredits(level.getCredits());
			level.fuelUp();
			upgrade.updateFuel(level.getFuelLevel());
			upgrade.updateCost(getCost());
			m_menuDelay = DELAY;
		}
	}
}

void Game::processLevelEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		level.playerShoot();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		level.movePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		level.rotatePlayer(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		level.rotatePlayer(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		currScreen = MenuScreen::MainMenu;
		m_menuDelay = DELAY;
	}
}

int Game::getCost()
{
	int cost = 0;

	cost += level.getArmourLevel();
	cost += level.getBoostLevel();
	cost += level.getCapacityLevel();
	cost += level.getFireLevel();
	cost += level.getFuelLevel();
	cost -= 5;
	cost *= 500;
	cost += 1000;

	return cost;
}

void Game::update()
{
	if (currScreen == MenuScreen::License)
	{
		m_licenseTime--;

		if (m_licenseTime <= 0)
		{
			currScreen = MenuScreen::Splash;
		}
	}
	
	m_menuDelay--;
	if (m_menuDelay < 0)
	{
		m_menuDelay = 0;
	}

	if (currScreen == MenuScreen::Level)
	{
		level.update();
	}
}

void Game::render()
{
	m_window.clear();

	if (currScreen == MenuScreen::License)
	{
		license.render(m_window);
	}
	if (currScreen == MenuScreen::Splash)
	{
		splash.render(m_window);
	}
	if (currScreen == MenuScreen::MainMenu)
	{
		mainMenu.render(m_window);
	}
	if (currScreen == MenuScreen::LevelSelect)
	{
		levelSelect.render(m_window);
	}
	if (currScreen == MenuScreen::Help)
	{
		help.render(m_window);
	}
	if (currScreen == MenuScreen::Upgrade)
	{
		upgrade.render(m_window);
	}
	if (currScreen == MenuScreen::Level)
	{
		level.render(m_window);
	}

	m_window.display();
}
