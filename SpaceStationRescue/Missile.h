#pragma once
#include "Character.h"
#include "Player.h"
class Missile :
	public Character
{
public:

	Missile(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, sf::Vector2f t_spawn, Player& t_player);

	void update(sf::Time t_deltaTime);

	bool collidesWithPlayer();
	bool collidesWithBullet();


	void fireMissile();

	sf::Vector2f m_spawnPoint;

	sf::Time m_lifeTimer;
	bool m_active;
	
	Player& m_player;

};

