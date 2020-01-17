#include "Worker.h"

Worker::Worker(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, Player& t_player) :
	Character(t_pos, t_speed, t_size, 1, t_grid),
	m_player(t_player)
{
	srand((unsigned)time(0));
	m_timer = sf::seconds((std::rand() % 6) + 1);
}

void Worker::update(sf::Time t_deltaTime)
{
	if (getHealth() > 0)
	{
		Character::pathTo(endPos);
		Character::followPath();


		if (collidesWithPlayer())
		{
			takeDamage(1);
			m_player.score++;
		}

		m_timer -= t_deltaTime;

		if (m_timer.asSeconds() < 0)
		{
			m_timer = sf::seconds(10.0f);
			endPos.x = (std::rand() % 6000) + 1;
			endPos.y = (std::rand() % 6000) + 1;
		}
	}
}

bool Worker::collidesWithPlayer()
{
	sf::Vector2f distanceBetween = getPosition() - m_player.getPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + m_player.getRadius();
}
