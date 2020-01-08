#include "Tile.h"

Tile::Tile(sf::Vector2f t_pos, int size) : 
	weight(999), 
	pos(t_pos), 
	tileSize(size), 
	isWall(false),
	closestNeighbour(nullptr)
{
	neighbours.resize(8);
	shape.setOutlineColor(sf::Color::Black);
	//shape.setOutlineThickness(-tileSize / 20);
	shape.setSize(sf::Vector2f(tileSize, tileSize));
	shape.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));

	line[0] = pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2);
	line[1] = pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2);
}

void Tile::setClosestNeighbour()
{
	Tile* closest = nullptr;
	for (int i = 0; i < neighbours.size(); i++)
	{
		if (i < 4 && neighbours[i] != nullptr)
		{
			if (closest == nullptr)
			{
				closest = neighbours[i];
			}
			else if (neighbours[i]->getWeight() < closest->getWeight())
			{
				closest = neighbours[i];
			}
		}

		//putting in extra checks on corners so we dont cut diagonally through tiles
		if (i == 4 && neighbours[i] != nullptr &&
			neighbours[0] != nullptr && !neighbours[0]->getWall() &&
			neighbours[1] != nullptr && !neighbours[1]->getWall()
			)
		{
			if (closest == nullptr)
			{
				closest = neighbours[i];
			}
			else if (neighbours[i]->getWeight() < closest->getWeight())
			{
				closest = neighbours[i];
			}
		}

		if (i == 5 && neighbours[i] != nullptr &&
			neighbours[0] != nullptr && !neighbours[0]->getWall() &&
			neighbours[2] != nullptr && !neighbours[2]->getWall()
			)
		{
			if (closest == nullptr)
			{
				closest = neighbours[i];
			}
			else if (neighbours[i]->getWeight() < closest->getWeight())
			{
				closest = neighbours[i];
			}
		}

		if (i == 6 && neighbours[i] != nullptr &&
			neighbours[3] != nullptr && !neighbours[3]->getWall() &&
			neighbours[1] != nullptr && !neighbours[1]->getWall()
			)
		{
			if (closest == nullptr)
			{
				closest = neighbours[i];
			}
			else if (neighbours[i]->getWeight() < closest->getWeight())
			{
				closest = neighbours[i];
			}
		}

		if (i == 7 && neighbours[i] != nullptr &&
			neighbours[3] != nullptr && !neighbours[3]->getWall() &&
			neighbours[2] != nullptr && !neighbours[2]->getWall()
			)
		{
			if (closest == nullptr)
			{
				closest = neighbours[i];
			}
			else if (neighbours[i]->getWeight() < closest->getWeight())
			{
				closest = neighbours[i];
			}
		}
	}

	if (closest != nullptr)
	{
		sf::Vector2f toNeighbour = ((closest->getPosition() - pos) / 2.0f);
		line[1].position = (pos + toNeighbour) * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2);
	}

	closestNeighbour = closest;
}

Tile* Tile::getClosestNeighbour()
{
	return closestNeighbour;
}

void Tile::reset()
{
	weight = 999;
}

void Tile::render(sf::RenderWindow& t_window, bool drawLine)
{
	shape.setPosition(pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2));
	if (isWall)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else
	{
		shape.setFillColor(sf::Color::Black);
	}

	t_window.draw(shape);
	if (drawLine)
	{
		t_window.draw(line, 2, sf::Lines);
	}
}
