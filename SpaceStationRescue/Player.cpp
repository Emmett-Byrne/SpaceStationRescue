#include "Player.h"

Player::Player(sf::Vector2f pos, float speed, float size, Grid& grid) : 
	Character(pos, speed, size, 5, grid),
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

	updateBullet(t_deltaTime);
}

void Player::fire(sf::Vector2f target)
{
	sf::Vector2f direction = target - getPosition();
	shootBullet(getPosition(), direction);
}
