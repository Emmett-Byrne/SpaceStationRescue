#include "Grid.h"

Grid::Grid(int x, int y, int size) : drawLines(false), tileSize(size)
{ 
	font.loadFromFile("Assets\\ariblk.ttf");

	setUpGrid(x, y, size); 
	setUpNeighbours(); 

	setupWorld();
	generateVectorField();
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

void Grid::switchDrawLines()
{
	drawLines = !drawLines;
}

void Grid::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i].render(t_window, drawLines);
	}
}

void Grid::setUpGrid(int x, int y, int size)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{ 
			Tile newTile(sf::Vector2f(j, i), size);
			grid.push_back(newTile);
		}
	}
}

void Grid::setUpNeighbours()
{
	for (int i = 0; i < grid.size(); i++)
	{
		sf::Vector2f gridPos = grid[i].getPosition();
		std::vector<Tile*>* neighbours = grid[i].getNeightbours();

		//top centre
		if (gridPos.y > 0)
		{
			neighbours->at(0) = findAtPosition(gridPos + sf::Vector2f(0, -1));
		}

		//left
		if (gridPos.x > 0)
		{
			neighbours->at(1) = findAtPosition(gridPos + sf::Vector2f(-1, 0));
		}

		//right
		if (gridPos.x < 50)
		{
			neighbours->at(2) = findAtPosition(gridPos + sf::Vector2f(1, 0));
		}

		//bottom centre
		if (gridPos.y < 50)
		{
			neighbours->at(3) = findAtPosition(gridPos + sf::Vector2f(0, 1));
		}


		//top left
		if (gridPos.x > 0 && gridPos.y > 0)
		{
			neighbours->at(4) = findAtPosition(gridPos + sf::Vector2f(-1, -1));
		}

		//top right
		if (gridPos.x < 50 && gridPos.y > 0)
		{
			neighbours->at(5) = findAtPosition(gridPos + sf::Vector2f(1, -1));
		}

		//bottom left
		if (gridPos.x > 0 && gridPos.y < 50)
		{
			neighbours->at(6) = findAtPosition(gridPos + sf::Vector2f(-1, 1));
		}

		//bottom right
		if (gridPos.x < 50 && gridPos.y < 50)
		{
			neighbours->at(7) = findAtPosition(gridPos + sf::Vector2f(1, 1));
		}
	}
}

void Grid::setupWorld()
{
	findAtPosition(sf::Vector2f(0, 5))->setWall(true);
	findAtPosition(sf::Vector2f(1, 5))->setWall(true);
	findAtPosition(sf::Vector2f(2, 5))->setWall(true);
	findAtPosition(sf::Vector2f(3, 5))->setWall(true);
	findAtPosition(sf::Vector2f(4, 5))->setWall(true);
	findAtPosition(sf::Vector2f(5, 5))->setWall(true);
	findAtPosition(sf::Vector2f(5, 4))->setWall(true);
	findAtPosition(sf::Vector2f(5, 3))->setWall(true);
	findAtPosition(sf::Vector2f(5, 2))->setWall(true);
	findAtPosition(sf::Vector2f(5, 1))->setWall(true);
}

void Grid::generateVectorField()
{
	resetTiles();
	std::vector<Tile*> queue;
	findAtPosition(sf::Vector2f(4,4))->setWeight(0);
	queue.push_back(findAtPosition(sf::Vector2f(4, 4)));


	//extra check added to make sure corners are not cut
	while (!queue.empty())
	{
		Tile* tile = queue.back();
		std::vector<Tile*>* neighbours = tile->getNeightbours();
		queue.pop_back();
		
		for (int i = 0; i < neighbours->size(); i++)
		{
			if (
				neighbours->at(i) != nullptr &&
				tile->getWeight() + 1 < neighbours->at(i)->getWeight() &&
				!neighbours->at(i)->getWall()
				)
			{
				queue.insert(queue.begin(), neighbours->at(i));
				neighbours->at(i)->setWeight(tile->getWeight() + 1);
			}
		}
	}

	updateVectorDirections();
}

void Grid::updateVectorDirections()
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i].setClosestNeighbour();
	}
}

void Grid::resetTiles()
{
	for (int i = 0; i < grid.size(); i++)
	{
		grid[i].reset();
	}
}
