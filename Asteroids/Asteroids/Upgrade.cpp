#include "Upgrade.h"
#include "Globals.h"
void Upgrade::init(sf::Font &font)
{
	m_screenText.setFont(font);
	m_creditsText.setFont(font);
	m_costText.setFont(font);
	m_fireText.setFont(font);
	m_boostText.setFont(font);
	m_armourText.setFont(font);
	m_capacityText.setFont(font);
	m_fuelText.setFont(font);

	m_screenText.setPosition(sf::Vector2f(SCR_W / 2.75f - 100, SCR_H / 6.0f));
	m_creditsText.setPosition(20, 20);
	m_costText.setPosition(600, 20);
	m_fireText.setPosition(100, 250);
	m_boostText.setPosition(100, 300);
	m_armourText.setPosition(100, 350);
	m_capacityText.setPosition(500, 250);
	m_fuelText.setPosition(500, 300);

	m_screenText.setColor(sf::Color::White);
	m_creditsText.setColor(sf::Color::White);
	m_costText.setColor(sf::Color::White);
	m_fireText.setColor(sf::Color::White);
	m_boostText.setColor(sf::Color::White);
	m_armourText.setColor(sf::Color::White);
	m_capacityText.setColor(sf::Color::White);
	m_fuelText.setColor(sf::Color::White);

	m_screenText.setString("Upgrade Screen\nPress Space for Main Menu\nPress a corresponding number to upgrade a stat\nPress Escape to Exit");
	m_creditsText.setString("Credits:0");
	m_costText.setString("Cost:0");
	m_fireText.setString("1. FireRate:0");
	m_boostText.setString("2. Boost:0");
	m_armourText.setString("3. Armour:0");
	m_capacityText.setString("4. Capacity:0");
	m_fuelText.setString("5. Fuel:0");
}

void Upgrade::updateCredits(int value)
{
	m_creditsText.setString("Credits:" + std::to_string(value));
}

void Upgrade::updateCost(int value)
{
	m_costText.setString("Cost:" + std::to_string(value));
}

void Upgrade::updateFire(int value)
{
	m_fireText.setString("1. Fire Rate:" + std::to_string(value));
}

void Upgrade::updateBoost(int value)
{
	m_boostText.setString("2. Boost:" + std::to_string(value));
}

void Upgrade::updateArmour(int value)
{

	m_armourText.setString("3. Armour:" + std::to_string(value));
}

void Upgrade::updateCapacity(int value)
{
	m_capacityText.setString("4. Capacity:" + std::to_string(value));
}

void Upgrade::updateFuel(int value)
{
	m_fuelText.setString("5. Fuel:" + std::to_string(value));
}

void Upgrade::render(sf::RenderWindow & window)
{
	window.draw(m_screenText);
	window.draw(m_creditsText);
	window.draw(m_costText);
	window.draw(m_fireText);
	window.draw(m_boostText);
	window.draw(m_armourText);
	window.draw(m_capacityText);
	window.draw(m_fuelText);
}