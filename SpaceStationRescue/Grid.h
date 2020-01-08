#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
class Grid
{
public:
	Grid(int x, int y, int size);

	Tile* findAtPosition(sf::Vector2f position);
	Tile* findAtCoordinatePosition(sf::Vector2f position);
	void switchDrawLines();
	void generateVectorField();

	void render(sf::RenderWindow& t_window);
private:
	void setUpGrid(int x, int y, int size);
	void setUpNeighbours();
	void setupWorld();
	void updateVectorDirections();
	void resetTiles();

	std::vector<Tile> grid;
	int tileSize;

	bool drawLines;

	sf::Font font;
};

