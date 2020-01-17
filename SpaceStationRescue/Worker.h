#pragma once
#include "Character.h"
#include "Player.h"
#include<ctime>

class Worker : public Character
{
public:
	Worker(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid, Player& t_player);
	void update(sf::Time t_deltaTime);

private:

	sf::Vector2f endPos;

	bool collidesWithPlayer();

	Player& m_player;
	bool movement;

	sf::Time m_timer;
};