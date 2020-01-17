#include "Predator.h"

Predator::Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p) :
	Character(pos, speed, size, 0, grid),
	player(p),
	fireRange(500),
	m_respawnPos(pos)
{
	m_respawn = false;
	srand((unsigned)time(0));
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
	else if (getHealth() <= 0 && m_respawn)
	{
		m_timer -= t_deltaTime;

		if (m_timer.asSeconds() < 0)
		{
			Character::setPosition(m_respawnPos);

			setHealth(2);
			
			m_respawn = false;
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

void Predator::respawn()
{
	if (!m_respawn)
	{
		m_timer = sf::seconds((std::rand() % 6) + 1);
		std::cout << m_timer.asSeconds() << std::endl;
		m_respawn = true;
	}
}