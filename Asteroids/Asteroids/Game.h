#ifndef GAME
#define GAME

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>
#include "License.h"
#include "Splash.h"
#include "MainMenu.h"
#include "LevelSelect.h"
#include "Help.h"
#include "Upgrade.h"
#include "Level.h"
/// <summary>
/// our game states
/// </summary>
enum class MenuScreen
{
	License,
	Splash,
	MainMenu,
	LevelSelect,
	Help,
	Upgrade,
	Level
};

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void loadContent();
	void init();
	void update();

	void processEvents();
	void processSplashEvents();
	void processMainMenuEvents();
	void processLevelSelectEvents();
	void processHelpEvents();
	void processUpgradeEvents();
	void processLevelEvents();

	void render();

	sf::RenderWindow m_window;
	sf::Font m_font;
	MenuScreen currScreen;
	int m_licenseTime;

	License license;
	Splash splash;
	MainMenu mainMenu;
	LevelSelect levelSelect;
	Help help;
	Upgrade upgrade;
	Level level;

};


#endif // !GAME