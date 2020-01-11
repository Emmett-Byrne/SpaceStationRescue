#include "VectorTile.h"

VectorTile::VectorTile(sf::Vector2f t_pos) : 
	pos(t_pos),
	closestNeighbour(nullptr)
{
	neighbours.resize(8);
}

void VectorTile::reset()
{
}

void VectorTile::setClosestNeighbour()
{
	VectorTile* closest = nullptr;
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

	closestNeighbour = closest;
}

VectorTile* VectorTile::getClosestNeighbour()
{
	if (closestNeighbour == nullptr)
	{
		setClosestNeighbour();
	}
	return closestNeighbour;
}

VectorTile* VectorTile::findFromField(std::vector<VectorTile>& field, sf::Vector2f position)
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
