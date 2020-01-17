#pragma once
#include "Character.h"
class Missile :
	public Character
{
public:

	Missile(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, sf::Vector2f t_spawn);

	void update(sf::Time t_deltaTime, sf::Vector2f t_pos);


	void fireMissile(sf::Vector2f t_pos);

	sf::Vector2f m_spawnPoint;

	sf::Time m_lifeTimer;
	bool m_active;
	
};

