#pragma once
#include "Character.h"
#include "Player.h"
class Predator : public Character
{
public:
	Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p);
	void update(sf::Time t_deltaTime);
private:
	Player& player;
};

