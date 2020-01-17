#include "Nest.h"

Nest::Nest(sf::Vector2f t_pos, float t_size, Grid& t_grid, float t_defenceRadius, Player& t_player, Missile& t_missile)
	:
	Character(t_pos, 0.0f, t_size, 4, t_grid),
	defenceRadius(t_defenceRadius),
	m_player(t_player),
	m_missile(t_missile),
	p1(t_pos, 8.0f, t_size, t_grid, t_player),
	p2(t_pos, 8.0f, t_size, t_grid, t_player),
	p3(t_pos, 8.0f, t_size, t_grid, t_player)
{
	m_alive = true;
}

void Nest::update(sf::Time t_deltaTime)
{
	if (getHealth() > 0)
	{
		if (!m_missile.m_active)
		{
			if (Character::circleCircleCollision(m_player.getPosition(), m_player.getRadius(), getPosition(), defenceRadius))
			{
				m_missile.fireMissile();
			}
		}

		if (collidesWithPlayer())
		{
			m_player.takeDamage(1);
		}
		if (collidesWithBullet())
		{
			takeDamage(1);
		}


		if (p1.getHealth() <= 0)
		{
			p1.respawn();
		}
		if (p2.getHealth() <= 0)
		{
			p2.respawn();
		}
		if (p3.getHealth() <= 0)
		{
			p3.respawn();
		}
	}


	m_missile.update(t_deltaTime);

	p1.update(t_deltaTime);
	p2.update(t_deltaTime);
	p3.update(t_deltaTime);
}

void Nest::render(sf::RenderWindow& t_window, sf::Vector2f t_offset, sf::Color t_colour)
{
	if (p1.getHealth() > 0) { p1.render(t_window, t_offset, sf::Color::Red); }
	if (p2.getHealth() > 0) { p2.render(t_window, t_offset, sf::Color::Red); }
	if (p3.getHealth() > 0) { p3.render(t_window, t_offset, sf::Color::Red); }

	Character::render(t_window, t_offset, t_colour);
}



bool Nest::collidesWithPlayer()
{
	sf::Vector2f distanceBetween = getPosition() - m_player.getPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + m_player.getRadius();
}

bool Nest::collidesWithBullet()
{
	sf::Vector2f distanceBetween = getPosition() - m_player.getBulletPosition();
	return sqrt(distanceBetween.x * distanceBetween.x + distanceBetween.y * distanceBetween.y) < getRadius() + m_player.getBulletRadius();
}
