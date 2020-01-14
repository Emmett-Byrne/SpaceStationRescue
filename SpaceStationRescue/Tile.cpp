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

void Tile::reset()
{
	distance = 9999999;
	totalDistance = 9999999;
	searched = false;
}

float Tile::distanceBetween(Tile first, Tile second)
{
	sf::Vector2f vector = first.getPosition() - second.getPosition();
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

bool Tile::operator<(const Tile& lhs)
{
	return this->totalDistance < lhs.totalDistance;
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
