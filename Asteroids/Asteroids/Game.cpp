#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(800, 480), "Asteroids")
	,currScreen(MenuScreen::License)
	,m_licenseTime(260)
{

}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	while (m_window.isOpen())
	{
		processEvents();
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
		if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
		}

		if (currScreen == MenuScreen::Splash)
		{
			processSplashEvents();
		}
		if (currScreen == MenuScreen::MainMenu)
		{
			processMainMenuEvents();
		}
		if (currScreen == MenuScreen::LevelSelect)
		{
			processLevelSelectEvents();
		}
		if (currScreen == MenuScreen::Help)
		{
			processHelpEvents();
		}
		if (currScreen == MenuScreen::Upgrade)
		{
			processUpgradeEvents();
		}
	}
}

void Game::processSplashEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
	}
}

void Game::processMainMenuEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		currScreen = MenuScreen::LevelSelect;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		currScreen = MenuScreen::Upgrade;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		currScreen = MenuScreen::Help;
	}
}

void Game::processLevelSelectEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
	}
}

void Game::processHelpEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
	}
}

void Game::processUpgradeEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currScreen = MenuScreen::MainMenu;
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

		std::cout << "You are on the License screen" << std::endl;
	}
	if (currScreen == MenuScreen::Splash)
	{
		std::cout << "You are on the Splash screen" << std::endl;
	}
	if (currScreen == MenuScreen::MainMenu)
	{
		std::cout << "You are on the MainMenu screen" << std::endl;
	}
	if (currScreen == MenuScreen::LevelSelect)
	{
		std::cout << "You are on the LevelSelect screen" << std::endl;
	}
	if (currScreen == MenuScreen::Help)
	{
		std::cout << "You are on the Help screen" << std::endl;
	}
	if (currScreen == MenuScreen::Upgrade)
	{
		std::cout << "You are on the Upgrade screen" << std::endl;
	}
}

void Game::render()
{
	m_window.clear();

	if (currScreen == MenuScreen::License)
	{
		//m_license.render();
	}
	if (currScreen == MenuScreen::Splash)
	{
		//m_splash.render();
	}
	if (currScreen == MenuScreen::MainMenu)
	{
		//m_mainMenu.render();
	}
	if (currScreen == MenuScreen::LevelSelect)
	{
		//m_levelSelect.render();
	}
	if (currScreen == MenuScreen::Help)
	{
		//m_help.render();
	}
	if (currScreen == MenuScreen::Upgrade)
	{
		//m_upgrade.render();
	}
	
	m_window.display();
}
