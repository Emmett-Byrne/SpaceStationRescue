#include "Tile.h"

Tile::Tile(sf::Vector2f t_pos, int size) : 
	weight(999), 
	pos(t_pos), 
	tileSize(size), 
	isWall(false)
{
	neighbours.resize(8);
	shape.setOutlineColor(sf::Color::Black);
	//shape.setOutlineThickness(-tileSize / 20);
	shape.setSize(sf::Vector2f(tileSize, tileSize));
	shape.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));

	line[0] = pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2);
	line[1] = pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2);
}

sf::Vector2f Tile::getDirectionFromField(sf::Vector2f position)
{
	int x = position.x / tileSize;
	int y = position.y / tileSize;
	position = sf::Vector2f(x, y);

	for (int i = 0; i < vectorField.size(); i++)
	{
		if (position.x == vectorField[i].getPosition().x && position.y == vectorField[i].getPosition().y)
		{
			sf::Vector2f direction = vectorField[i].getDirection();
			std::cout << direction.x << ", " << direction.y << std::endl;
			return vectorField[i].getDirection();
		}
	}

	return sf::Vector2f(0,0);
}

void Tile::generateVectorField()
{
	resetVectorField();
	std::vector<VectorTile*> queue;
	VectorTile* start = VectorTile::findFromField(vectorField, pos);
	start->setWeight(0);
	queue.push_back(start);


	//extra check added to make sure corners are not cut
	while (!queue.empty())
	{
		VectorTile* tile = queue.back();
		std::vector<VectorTile*>* neighbours = tile->getNeightbours();
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

void Tile::updateVectorDirections()
{
	for (int i = 0; i < vectorField.size(); i++)
	{
		vectorField[i].setClosestNeighbour();
	}
}

void Tile::reset()
{
	weight = 999;
}

void Tile::resetVectorField()
{
	for (int i = 0; i < vectorField.size(); i++)
	{
		vectorField[i].setWeight(999);
	}
}

void Tile::setupFieldNeighbours()
{
	for (int i = 0; i < vectorField.size(); i++)
	{
		sf::Vector2f gridPos = vectorField[i].getPosition();
		std::vector<VectorTile*>* vNeighbours = vectorField[i].getNeightbours();

		//top centre
		if (gridPos.y > 0)
		{
			vNeighbours->at(0) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(0, -1)));
		}

		//left
		if (gridPos.x > 0)
		{
			vNeighbours->at(1) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(-1, 0)));
		}

		//right
		if (gridPos.x < 50)
		{
			vNeighbours->at(2) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(1, 0)));
		}

		//bottom centre
		if (gridPos.y < 50)
		{
			vNeighbours->at(3) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(0, 1)));
		}


		//top left
		if (gridPos.x > 0 && gridPos.y > 0)
		{
			vNeighbours->at(4) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(-1, -1)));
		}

		//top right
		if (gridPos.x < 50 && gridPos.y > 0)
		{
			vNeighbours->at(5) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(1, -1)));
		}

		//bottom left
		if (gridPos.x > 0 && gridPos.y < 50)
		{
			vNeighbours->at(6) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(-1, 1)));
		}

		//bottom right
		if (gridPos.x < 50 && gridPos.y < 50)
		{
			vNeighbours->at(7) = VectorTile::findFromField(vectorField, (gridPos + sf::Vector2f(1, 1)));
		}
	}
}

void Tile::render(sf::RenderWindow& t_window, sf::Vector2f offset)
{
	shape.setPosition(pos * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2) + offset);
	if (isWall)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	else
	{
		shape.setFillColor(sf::Color::Black);
	}

	t_window.draw(shape);
}

void Tile::showField(sf::RenderWindow& t_window, sf::Vector2f offset)
{/*
	for (int i = 0; i < vectorField.size(); i++)
	{
		line[0] = vectorField[i].getPosition() * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2) + offset;
		line[1] = vectorField[i].getClosestNeighbour()->getPosition() * tileSize + sf::Vector2f(tileSize / 2, tileSize / 2) + offset;
	}*/

}
