#include "Nest.h"

Nest::Nest(sf::Vector2f t_pos, float t_size, Grid& t_grid, float t_defenceRadius, Player& t_player, Missile& t_missile)
	:
	Character(t_pos, 0.0f, t_size, 4, t_grid),
	defenceRadius(t_defenceRadius),
	m_player(t_player),
	m_missile(t_missile)
{
	missileActive = false;
}

void Nest::update(sf::Time t_deltaTime)
{
	if (!missileActive)
	{
		if (Character::circleCircleCollision(m_player.getPosition(), m_player.getRadius(), getPosition(), defenceRadius))
		{
			
		}
	}


	m_missile.update(t_deltaTime, m_player.getPosition());
}

void Nest::fireMissile(sf::Vector2f t_pos)
{
}

void Nest::spawnPredator(sf::Vector2f t_pos)
{
}
