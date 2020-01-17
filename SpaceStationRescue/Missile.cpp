#include "Missile.h"

Missile::Missile(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, sf::Vector2f t_spawn, Player& t_player) :
	Character(t_pos, t_speed, t_size, 1, t_grid),
	m_spawnPoint(t_spawn),
	m_player(t_player)
{
	m_active = false;
}

void Missile::update(sf::Time t_deltaTime)
{
	if (m_active)
	{
		m_lifeTimer -= t_deltaTime;

		Character::pathTo(m_player.getPosition());
		Character::followPath();

		if (collidesWithPlayer())
		{
			m_player.takeDamage(1);
			takeDamage(1);
			m_active = false;
		}

		if (collidesWithBullet())
		{
			takeDamage(1);
			m_active = false;
		}


		if (m_lifeTimer.asSeconds() < 0)
		{
			takeDamage(1);
			m_active = false;
		}
	}
	else
	{
		
	}
}

void Missile::fireMissile()
{
	if (!m_active)
	{
		m_lifeTimer = sf::seconds(5.0f);
		setHealth(1);
		Character::setPosition(m_spawnPoint);
		m_active = true;
	}
}


bool Missile::collidesWithPlayer()
{
	sf::Vector2f distanceBetween = getPosition() - m_player.getPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + m_player.getRadius();
}

bool Missile::collidesWithBullet()
{
	sf::Vector2f distanceBetween = getPosition() - m_player.getBulletPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + m_player.getBulletRadius();
}
