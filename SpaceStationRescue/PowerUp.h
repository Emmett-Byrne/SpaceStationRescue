#pragma once
#include "Character.h"
#include "Player.h"
class PowerUp :
	public Character
{
public:
	PowerUp(sf::Vector2f pos, float size, Grid& grid, Player& p);

	void update(sf::Time t_deltaTime);

private:
	Player& m_player;

	sf::Time m_timer;

	bool m_active;

	int m_type;
};

