#pragma once
#include "Character.h"
#include "Player.h"
#include<ctime>



class Predator : public Character
{
public:
	Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p);
	void update(sf::Time t_deltaTime);

	void respawn();

	bool getAlive();

private:
	Player& player;

	sf::Vector2f m_respawnPos;

	bool m_alive;
	bool m_respawn;
	
	sf::Time m_timer;
};

