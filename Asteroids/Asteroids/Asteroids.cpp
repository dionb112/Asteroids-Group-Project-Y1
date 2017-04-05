#include "Asteroids.h"

Asteroids::Asteroids()
{
	init();
}

Asteroids::~Asteroids()
{
}

void Asteroids::loadContent()
{
	if (!m_largeTexture.loadFromFile("ASSETS/IMAGES/asteroid3.png"))
	{
		std::cout << "Error loading big asteroid texture" << std::endl;
	}
	if (!m_medTexture.loadFromFile("ASSETS/IMAGES/asteroid2.png"))
	{
		std::cout << "Error loading medium asteroid texture" << std::endl;
	}
	if (!m_smallTexture.loadFromFile("ASSETS/IMAGES/asteroid1.png"))
	{
		std::cout << "Error loading small asteroid texture" << std::endl;
	}
	if (!m_tinyTexture.loadFromFile("ASSETS/IMAGES/asteroid0.png"))
	{
		std::cout << "Error loading tiny asteroid texture" << std::endl;
	}
}


void Asteroids::setupSprites()
{
	m_largePos = { 100,100 };
	m_largeSprite.setPosition(m_largePos);
	m_largeSprite.setTexture(m_largeTexture);

	m_medSprite.setTexture(m_medTexture);
	m_medPos = { 300,300 };
	m_medSprite.setPosition(m_medPos);

	m_smallSprite.setTexture(m_smallTexture);
	m_smallPos = { 200,200 };
	m_smallSprite.setPosition(m_smallPos);

	m_tinySprite.setTexture(m_tinyTexture);
	m_tinyPos = { 420,420 };
	m_tinySprite.setPosition(m_tinyPos);
}


void Asteroids::init()
{
	loadContent();
	setupSprites();
}

void Asteroids::render(sf::RenderWindow & window)
{
	window.draw(m_largeSprite);
	window.draw(m_medSprite);
	window.draw(m_smallSprite);
	window.draw(m_tinySprite);
}

void Asteroids::update()
{

}
