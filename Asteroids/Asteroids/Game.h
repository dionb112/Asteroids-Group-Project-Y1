#ifndef GAME
#define GAME

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>

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
	Upgrade
};

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void update();
	void processEvents();
	void render();

	sf::RenderWindow m_window;
};


#endif // !GAME