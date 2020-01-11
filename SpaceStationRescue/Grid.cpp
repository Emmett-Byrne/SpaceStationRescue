#include "Grid.h"

Grid::Grid(int x, int y, int size) : drawLines(false), tileSize(size)
{ 
	font.loadFromFile("Assets\\ariblk.ttf");

	setUpGrid(x, y, size); 
	setUpNeighbours(); 

	setupWorld();
}

Tile* Grid::findAtPosition(sf::Vector2f position)
{
	for (int i = 0; i < grid.size(); i++)
	{
		if (position.x == grid[i].getPosition().x && position.y == grid[i].getPosition().y)
		{
			return &grid[i];
		}
	}
	return nullptr;
}

VectorTile* Grid::findVectorAtPosition(sf::Vector2f position)
{
	for (int i = 0; i < field.size(); i++)
	{
		if (position.x == field[i].getPosition().x && position.y == field[i].getPosition().y)
		{
			return &field[i];
		}
	}
	return nullptr;
}

Tile* Grid::findAtCoordinatePosition(sf::Vector2f position)
{
	int x = position.x / tileSize;
	int y = position.y / tileSize;
	position = sf::Vector2f(x, y);

	for (int i = 0; i < grid.size(); i++)
	{
		if (position.x == grid[i].getPosition().x && position.y == grid[i].getPosition().y)
		{
			return &grid[i];
		}
	}
	return nullptr;
}

void Grid::render(sf::RenderWindow& t_window, sf::Vector2f offset)
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i].render(t_window, offset);
	}
}

void Grid::setUpGrid(int x, int y, int size)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{ 
			Tile newTile(sf::Vector2f(j, i), size);
			VectorTile newVectorTile(sf::Vector2f(j, i));
			grid.push_back(newTile);
			field.push_back(newVectorTile);
		}
	}
}

void Grid::setUpNeighbours()
{
	for (int i = 0; i < grid.size(); i++)
	{
		sf::Vector2f gridPos = grid[i].getPosition();
		std::vector<Tile*>* neighbours = grid[i].getNeightbours();
		std::vector<VectorTile*>* vNeighbours = field[i].getNeightbours();

		//top centre
		if (gridPos.y > 0)
		{
			neighbours->at(0) = findAtPosition(gridPos + sf::Vector2f(0, -1));
			vNeighbours->at(0) = findVectorAtPosition(gridPos + sf::Vector2f(0, -1));
		}

		//left
		if (gridPos.x > 0)
		{
			neighbours->at(1) = findAtPosition(gridPos + sf::Vector2f(-1, 0));
			vNeighbours->at(1) = findVectorAtPosition(gridPos + sf::Vector2f(-1, 0));
		}

		//right
		if (gridPos.x < 50)
		{
			neighbours->at(2) = findAtPosition(gridPos + sf::Vector2f(1, 0));
			vNeighbours->at(2) = findVectorAtPosition(gridPos + sf::Vector2f(1, 0));
		}

		//bottom centre
		if (gridPos.y < 50)
		{
			neighbours->at(3) = findAtPosition(gridPos + sf::Vector2f(0, 1));
			vNeighbours->at(3) = findVectorAtPosition(gridPos + sf::Vector2f(0, 1));
		}


		//top left
		if (gridPos.x > 0 && gridPos.y > 0)
		{
			neighbours->at(4) = findAtPosition(gridPos + sf::Vector2f(-1, -1));
			vNeighbours->at(4) = findVectorAtPosition(gridPos + sf::Vector2f(-1, -1));
		}

		//top right
		if (gridPos.x < 50 && gridPos.y > 0)
		{
			neighbours->at(5) = findAtPosition(gridPos + sf::Vector2f(1, -1));
			vNeighbours->at(5) = findVectorAtPosition(gridPos + sf::Vector2f(1, -1));
		}

		//bottom left
		if (gridPos.x > 0 && gridPos.y < 50)
		{
			neighbours->at(6) = findAtPosition(gridPos + sf::Vector2f(-1, 1));
			vNeighbours->at(6) = findVectorAtPosition(gridPos + sf::Vector2f(-1, 1));
		}

		//bottom right
		if (gridPos.x < 50 && gridPos.y < 50)
		{
			neighbours->at(7) = findAtPosition(gridPos + sf::Vector2f(1, 1));
			vNeighbours->at(7) = findVectorAtPosition(gridPos + sf::Vector2f(1, 1));
		}
	}
}

void Grid::setupWorld()
{
	// top row of rooms
	createHorizontalWall(sf::Vector2f(0, 5), 6);
	createHorizontalWall(sf::Vector2f(24, 5), 6);
	createHorizontalWall(sf::Vector2f(10, 5), 10);
	createVerticalWall(sf::Vector2f(5, 1), 4);
	createVerticalWall(sf::Vector2f(8, 0), 6);
	createVerticalWall(sf::Vector2f(14, 0), 5);
	createVerticalWall(sf::Vector2f(15, 0), 5);
	createVerticalWall(sf::Vector2f(21, 0), 6);
	createVerticalWall(sf::Vector2f(24, 1), 4);

	// left column of rooms
	createHorizontalWall(sf::Vector2f(0, 9), 6);
	createHorizontalWall(sf::Vector2f(0, 14), 6);
	createHorizontalWall(sf::Vector2f(0, 15), 6);
	createHorizontalWall(sf::Vector2f(0, 20), 6);
	createVerticalWall(sf::Vector2f(5, 7), 6);
	createVerticalWall(sf::Vector2f(5, 17), 6);

	// right column row of rooms
	createHorizontalWall(sf::Vector2f(24, 9), 6);
	createHorizontalWall(sf::Vector2f(24, 14), 6);
	createHorizontalWall(sf::Vector2f(24, 15), 6);
	createHorizontalWall(sf::Vector2f(24, 20), 6);
	createVerticalWall(sf::Vector2f(24, 7), 6);
	createVerticalWall(sf::Vector2f(24, 17), 6);


	// bottom row of rooms
	createHorizontalWall(sf::Vector2f(0, 24), 6);
	createHorizontalWall(sf::Vector2f(24, 24), 6);
	createHorizontalWall(sf::Vector2f(10, 24), 10);
	createVerticalWall(sf::Vector2f(5, 26), 4);
	createVerticalWall(sf::Vector2f(8, 24), 6);
	createVerticalWall(sf::Vector2f(14, 25), 5);
	createVerticalWall(sf::Vector2f(15, 25), 5);
	createVerticalWall(sf::Vector2f(21, 24), 6);
	createVerticalWall(sf::Vector2f(24, 26), 4);

	//centre
	createHorizontalWall(sf::Vector2f(10, 8), 10);
	createHorizontalWall(sf::Vector2f(9, 14), 12);
	createHorizontalWall(sf::Vector2f(9, 15), 12);
	createHorizontalWall(sf::Vector2f(10, 21), 10);
	createVerticalWall(sf::Vector2f(8, 8), 14);
	createVerticalWall(sf::Vector2f(14, 8), 14);
	createVerticalWall(sf::Vector2f(15, 8), 14);
	createVerticalWall(sf::Vector2f(21, 8), 14);

	for (int i = 0; i < grid.size(); i++)
	{

		std::cout << "Pre-Processing vector field: (" << (i + 1.0f) / grid.size() * 100 << "%)" << std::endl;
		grid[i].setField(field);
		if (!grid[i].getWall())
		{
			grid[i].setupFieldNeighbours();
			grid[i].generateVectorField();
		}
	}
}

void Grid::setAsWall(sf::Vector2f pos)
{
	findAtPosition(pos)->setWall(true);
	findVectorAtPosition(pos)->setWall(true);
}

void Grid::createHorizontalWall(sf::Vector2f pos, int len)
{
	for (int i = 0; i < len; i++)
	{
		sf::Vector2f newPos = sf::Vector2f(pos.x + i, pos.y);
		findAtPosition(newPos)->setWall(true);
		findVectorAtPosition(newPos)->setWall(true);
	}
}

void Grid::createVerticalWall(sf::Vector2f pos, int len)
{
	for (int i = 0; i < len; i++)
	{
		sf::Vector2f newPos = sf::Vector2f(pos.x, pos.y + i);
		findAtPosition(newPos)->setWall(true);
		findVectorAtPosition(newPos)->setWall(true);
	}
}

void Grid::resetTiles()
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i].reset();
	}
}
