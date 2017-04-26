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
	currScreen = (MenuScreen::MainMenu);
	m_licenseTime = 0; //set back to 260 when finished
	m_menuDelay = 0;
	license.init(m_font);
	splash.init(m_font);
	mainMenu.init(m_font);
	levelSelect.init(m_font);
	help.init(m_font);
	upgrade.init(m_font);
	level.init();
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
		if (currScreen != MenuScreen::License)
		{ 
			if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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
		m_menuDelay = DELAY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		level.levelSetup(0);
		//currScreen = MenuScreen::Level;
		m_menuDelay = DELAY;
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		level.fireUp();
		m_menuDelay = DELAY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		level.boostUp();
		m_menuDelay = DELAY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		level.armourUp();
		m_menuDelay = DELAY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		level.capacityUp();
		m_menuDelay = DELAY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		level.shieldUp();
		m_menuDelay = DELAY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		level.fuelUp();
		m_menuDelay = DELAY;
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
	//Testing add and remove before collisions
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		level.deleteLarge();
		level.addMed();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		level.deleteMed();
		level.addSmall();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		level.deleteSmall();
		level.addTiny();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		level.deleteTiny();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		level.addMed();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		level.addSmall();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		level.addTiny();
	}
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
