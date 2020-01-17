#include "PowerUp.h"

PowerUp::PowerUp(sf::Vector2f pos, float size, Grid& grid, Player& p) :
	Character(pos, 0.0f, size, 1, grid),
	m_player(p)
{
	m_active = false;
}

void PowerUp::update(sf::Time t_deltaTime)
{
	if (m_active)
	{
		m_timer -= t_deltaTime;

		if (m_timer.asSeconds() < 0)
		{
			m_player.setSpeed(m_player.getSpeed() * 0.5);
			m_active = false;
		}
	}
	else
	{
		if (Character::circleCircleCollision(m_player.getPosition(), m_player.getRadius(), getPosition(), getRadius()))
		{
			m_active = true;
			m_timer = sf::seconds(5.0f);

			m_player.setSpeed(m_player.getSpeed() * 1.5);
		}
	}
}