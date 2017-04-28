#pragma once
#include "SFML/Graphics.hpp"
class Upgrade
{
private:
	sf::Text m_screenText;
	sf::Text m_creditsText;
	sf::Text m_costText;
	sf::Text m_fireText;
	sf::Text m_boostText;
	sf::Text m_armourText;
	sf::Text m_capacityText;
	sf::Text m_fuelText;
public:
	void init(sf::Font &font);
	void updateCredits(int value);
	void updateCost(int value);
	void updateFire(int value);
	void updateBoost(int value);
	void updateArmour(int value);
	void updateCapacity(int value);
	void updateFuel(int value);
	void render(sf::RenderWindow &window);
};