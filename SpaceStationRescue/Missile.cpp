#include "Missile.h"

Missile::Missile(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, sf::Vector2f t_spawn) :
	Character(t_pos, t_speed, t_size, 1, t_grid),
	m_spawnPoint(t_spawn)
{
	m_active = false;
}

void Missile::update(sf::Time t_deltaTime, sf::Vector2f t_pos)
{
	if (m_active)
	{
		m_lifeTimer -= t_deltaTime;

		Character::pathTo(t_pos);
		Character::followPath();

		if (m_lifeTimer.asSeconds() < 0)
		{
			m_active = false;
		}
	}
	else
	{
		Character::setPosition(m_spawnPoint);
	}
}

void Missile::fireMissile()
{
	if (!m_active)
	{
		m_lifeTimer = sf::seconds(5.0f);
		m_active = true;
	}
}
