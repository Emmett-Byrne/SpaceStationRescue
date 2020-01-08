#include "Player.h"

Player::Player(sf::Vector2f pos, float speed, float size, Grid& grid) : 
	Character(pos, speed, size, grid),
	moveUp(false),
	moveDown(false),
	moveLeft(false),
	moveRight(false)
{
}

void Player::update(sf::Time t_deltaTime)
{
	if (moveUp)
	{
		Character::move(sf::Vector2f(0, -1));
	}
	if (moveDown)
	{
		Character::move(sf::Vector2f(0, 1));
	}
	if (moveLeft)
	{
		Character::move(sf::Vector2f(-1, 0));
	}
	if (moveRight)
	{
		Character::move(sf::Vector2f(1, 0));
	}
}