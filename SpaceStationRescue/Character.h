#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <algorithm>
#include <iostream>

class Character
{
public:
	Character(sf::Vector2f _pos, float _speed, float _size, Grid& _grid);

	void move(sf::Vector2f direction);
	void pathTo(sf::Vector2f location);
	void followPath();

	sf::Vector2f getPosition() { return position; };

	Tile* collidesWithWorld();
	void collidesWithBounds();
	bool circleRectCollision(sf::Vector2f circlePosition, int circleRadius, sf::Vector2f rectPosition, int rectWidth, int rectHeight);

	virtual void render(sf::RenderWindow& t_window, sf::Vector2f offset, sf::Color colour);

	Tile* target;
private:

	sf::Vector2f position;
	float speed;
	float radius;

	Grid& grid;

	sf::CircleShape shape;
};

