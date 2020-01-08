#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Character
{
public:
	Character(sf::Vector2f _pos, float _speed, float _size, Grid& _grid);

	void move(sf::Vector2f direction);
	void pathTo(sf::Vector2f location);
	void followPath();

	virtual void render(sf::RenderWindow& t_window);
private:
	sf::Vector2f position;
	float speed;
	float radius;

	Grid& grid;

	sf::CircleShape shape;
};

