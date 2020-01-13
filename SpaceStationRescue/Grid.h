#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include <iostream>
#include <queue>

class Grid
{
public:
	Grid(int x, int y, int size);

	Tile* findAtPosition(sf::Vector2f position);
	Tile* findAtCoordinatePosition(sf::Vector2f position);

	void render(sf::RenderWindow& t_window, sf::Vector2f offset);
private:
	void setUpGrid(int x, int y, int size);
	void setUpNeighbours();
	void setupWorld();
	void setAsWall(sf::Vector2f pos);
	void createHorizontalWall(sf::Vector2f pos, int len);
	void createVerticalWall(sf::Vector2f pos, int len);
	void resetTiles();

	std::vector<sf::Vector2f> createPath(sf::Vector2f start, sf::Vector2f target);

	std::vector<Tile> grid;
	int tileSize;

	bool drawLines;

	sf::Font font;
};

