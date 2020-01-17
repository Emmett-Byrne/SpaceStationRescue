#include "Predator.h"

Predator::Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p) :
	Character(pos, speed, size, 2, grid),
	player(p),
	m_respawnPos(pos)
{
	m_alive = false;
	m_respawn = false;
	srand((unsigned)time(0));
}

void Predator::update(sf::Time t_deltaTime)
{
	if (m_alive)
	{
		Character::pathTo(player.getPosition());
		Character::followPath();
	}
	else if ((!m_alive) && m_respawn)
	{
		m_timer -= t_deltaTime;

		if (m_timer.asSeconds() < 0)
		{
			Character::setPosition(m_respawnPos);
			m_alive = true;
			m_respawn = false;
		}
	}
}

void Predator::respawn()
{
	if (!m_alive)
	{
		if (!m_respawn)
		{
			m_timer = sf::seconds((std::rand() % 6) + 1);
			std::cout << m_timer.asSeconds() << std::endl;
			m_respawn = true;
		}
	}
}

bool Predator::getAlive()
{
	return m_alive;
}
