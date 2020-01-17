#pragma once

#include"Player.h"
#include"Missile.h"
#include"Predator.h"
#include <vector>


class Nest : public Character
{
public:
	Nest(sf::Vector2f t_pos, float t_size, Grid& t_grid, float t_defenceRadius, Player& t_player, Missile& t_missile);

	void update(sf::Time t_deltaTime);

	float defenceRadius;

	void render(sf::RenderWindow& t_window, sf::Vector2f t_offset, sf::Color t_colour);


private:
	Player& m_player;
	Missile& m_missile;

	bool m_alive;


	Predator p1;
	Predator p2;
	Predator p3;
};

