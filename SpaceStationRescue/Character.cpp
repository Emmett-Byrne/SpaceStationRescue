#include "Character.h"

Character::Character(sf::Vector2f _pos, float _speed, float _size, Grid& _grid) :
	grid(_grid),
	radius(_size),
	speed(_speed),
	position(_pos),
	target(nullptr)
{
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(sf::Color::Green);
}

void Character::move(sf::Vector2f direction)
{
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	position += direction / length * speed;

	//TODO: check if collides with wall
	if (collidesWithWorld() != nullptr)
	{
		position -= direction / length * speed;
	}
	collidesWithBounds();
}

void Character::pathTo(sf::Vector2f location)
{
	target = grid.findAtCoordinatePosition(location);
	path = grid.createPath(position, target->getPosition());
}

void Character::followPath()
{
	if (!path.empty())
	{
		move(path.back() - position);
	}
}

Tile* Character::collidesWithWorld()
{
	Tile* currTile = grid.findAtCoordinatePosition(position);

	if (currTile->getWall())
	{
		return currTile;
	}

	std::vector<Tile*>* neighbours = currTile->getNeightbours();
	for (int i = 0; i < neighbours->size(); i++)
	{
		if (neighbours->at(i) != nullptr)
		{
			int size = neighbours->at(i)->getSize();
			sf::Vector2f rectPosition = (neighbours->at(i)->getPosition() * (float)size);
			if (circleRectCollision(position, radius, rectPosition, size, size) && neighbours->at(i)->getWall())
			{
				return neighbours->at(i);
			}
		}
	}

	return nullptr;
}

void Character::collidesWithBounds()
{
	if (position.x - radius < 0)
	{
		position.x = radius;
	}
	if (position.y - radius < 0)
	{
		position.y = radius;
	}
	if (position.x + radius > 30 * 200)
	{
		position.x = 30 * 200 - radius;
	}
	if (position.y + radius > 30 * 200)
	{
		position.y = 30 * 200 - radius;
	}
}

bool Character::circleRectCollision(sf::Vector2f circlePosition, int circleRadius, sf::Vector2f rectPosition, int rectWidth, int rectHeight)
{
	int DeltaX = circlePosition.x - std::max(rectPosition.x, std::min(circlePosition.x, rectPosition.x + rectWidth));
	int DeltaY = circlePosition.y - std::max(rectPosition.y, std::min(circlePosition.y, rectPosition.y + rectHeight));
	return (DeltaX * DeltaX + DeltaY * DeltaY) < (circleRadius * circleRadius);
}

void Character::render(sf::RenderWindow& t_window, sf::Vector2f offset, sf::Color colour)
{
	shape.setFillColor(colour);
	shape.setPosition(position + offset);
	t_window.draw(shape);
}
