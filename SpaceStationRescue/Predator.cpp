#include "Predator.h"

Predator::Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p) :
	Character(pos, speed, size, 2, grid),
	player(p),
	fireRange(500)
{
}

void Predator::update(sf::Time t_deltaTime)
{
	if (getHealth() > 0)
	{
		if (fireCooldown > sf::Time::Zero)
		{
			fireCooldown -= t_deltaTime;

		}
		else
		{
			sf::Vector2f distanceToPlayer = player.getPosition() - getPosition();
			if (sqrt(distanceToPlayer.x * distanceToPlayer.x + distanceToPlayer.y * distanceToPlayer.y) < fireRange)
			{
				shootBullet(getPosition(), distanceToPlayer);
				fireCooldown = sf::seconds(1.5);
			}
		}

		updateBullet(t_deltaTime);

		if (collidesWithPlayer() || playerCollidseWithBullet())
		{
			player.takeDamage(1);
		}
		if (collidesWithBullet())
		{
			takeDamage(1);
		}

		if (player.getHealth() > 0)
		{
			Character::pathTo(player.getPosition());
			Character::followPath();
		}
	}
}

bool Predator::collidesWithPlayer()
{
	sf::Vector2f distanceBetween = getPosition() - player.getPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + player.getRadius();
}

bool Predator::collidesWithBullet()
{
	sf::Vector2f distanceBetween = getPosition() - player.getBulletPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + player.getBulletRadius();
}

bool Predator::playerCollidseWithBullet()
{
	sf::Vector2f distanceBetween = getBulletPosition() - player.getPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getBulletRadius() + player.getRadius();
}
