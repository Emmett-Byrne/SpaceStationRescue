#pragma once

#include"Player.h"
#include"Missile.h"

const int MAX_PREDATORS = 1;

class Nest : public Character
{
public:
	Nest(sf::Vector2f t_pos, float t_size, Grid& t_grid, float t_defenceRadius, Player& t_player, Missile& t_missile);

	void update(sf::Time t_deltaTime);
	void fireMissile(sf::Vector2f t_pos);


	void spawnPredator(sf::Vector2f t_pos);


	float defenceRadius;

	bool missileActive;

private:
	Player& m_player;
	Missile& m_missile;
};

