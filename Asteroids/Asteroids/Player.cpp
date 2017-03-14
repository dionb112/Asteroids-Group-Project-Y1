#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
	m_body.setPosition(sf::Vector2f(400, 280));
	m_body.setRadius(10);
	m_body.setFillColor(sf::Color::Green);
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_body);
}

sf::CircleShape Player::getBody()
{
	return m_body;
}

double Player::getRotation()
{
	return m_rotation;
}

void Player::rotate(int rotate)
{
	m_rotation += rotate;
}