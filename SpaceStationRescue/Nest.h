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

	void spawnPredator(sf::Vector2f t_pos);

	float defenceRadius;

	void render(sf::RenderWindow& t_window, sf::Vector2f t_offset, sf::Color t_colour);

	std::vector<Predator> pList;


private:
	Player& m_player;
	Missile& m_missile;


	Predator p1;
	Predator p2;
	Predator p3;
};

