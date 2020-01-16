#pragma once
#include "Character.h"
class Worker : public Character
{
public:
	Worker(sf::Vector2f t_pos, float t_speed, float t_size, Grid& t_grid);
	void update(sf::Time t_deltaTime);

private:

};

