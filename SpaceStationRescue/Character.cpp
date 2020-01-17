#include "Character.h"

Character::Character(sf::Vector2f _pos, float _speed, float _size, int h, Grid& _grid) :
	grid(_grid),
	radius(_size),
	speed(_speed),
	position(_pos),
	target(nullptr),
	health(h),
	bulletAlive(false),
	bulletRadius(10),
	bulletSpeed(20)
{
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	bulletShape.setRadius(bulletRadius);
	bulletShape.setOrigin(radius, radius);
	bulletShape.setFillColor(sf::Color::Yellow);
}

void Character::move(sf::Vector2f direction)
{
	if (health > 0)
	{
		float length = sqrt(direction.x * direction.x + direction.y * direction.y);
		position += direction / length * speed;

		//TODO: check if collides with wall
		collidesWithBounds(position, radius);
		if (collidesWithWorld(position, radius) != nullptr)
		{
			position -= direction / length * speed;
		}
	}
	
}

void Character::pathTo(sf::Vector2f location)
{
	if (health > 0)
	{
		target = grid.findAtCoordinatePosition(location);
		path = grid.createPath(position, target->getPosition());
	}
}

void Character::followPath()
{
	if (health > 0)
	{
		if (!path.empty())
		{
			move(path.back() - position);
		}
	}
}

void Character::wander()
{


}

float Character::getRadius()
{
	return radius;
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		position = sf::Vector2f(-1000, -1000);
	}
}

void Character::updateBullet(sf::Time dt)
{
	if (bulletAlive)
	{
		bulletTimer -= dt;

		if (bulletTimer.asSeconds() < 0)
		{
			bulletAlive = false;
			bulletPosition = sf::Vector2f(-1000, -1000);
		}
		else
		{
			bulletPosition += (bulletDirection / sqrt(bulletDirection.x * bulletDirection.x + bulletDirection.y * bulletDirection.y)) * bulletSpeed;
		}

	}
}

void Character::shootBullet(sf::Vector2f location, sf::Vector2f direction)
{

	if (!bulletAlive)
	{
		bulletTimer = sf::seconds(1.0f);
		bulletAlive = true;
		bulletPosition = location;
		bulletDirection = direction;
	}
}

Tile* Character::collidesWithWorld(sf::Vector2f pos, float rad)
{
	Tile* currTile = grid.findAtCoordinatePosition(pos);

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
			if (circleRectCollision(pos, rad, rectPosition, size, size) && neighbours->at(i)->getWall())
			{
				return neighbours->at(i);
			}
		}
	}

	return nullptr;
}

void Character::collidesWithBounds(sf::Vector2f& pos, float rad)
{
	if (pos.x - rad < 0)
	{
		pos.x = rad;
	}
	if (pos.y - rad < 0)
	{
		pos.y = rad;
	}
	if (pos.x + rad > 30 * 200)
	{
		pos.x = 30 * 200 - rad;
	}
	if (pos.y + rad > 30 * 200)
	{
		pos.y = 30 * 200 - rad;
	}
}

bool Character::circleRectCollision(sf::Vector2f circlePosition, int circleRadius, sf::Vector2f rectPosition, int rectWidth, int rectHeight)
{
	int DeltaX = circlePosition.x - std::max(rectPosition.x, std::min(circlePosition.x, rectPosition.x + rectWidth));
	int DeltaY = circlePosition.y - std::max(rectPosition.y, std::min(circlePosition.y, rectPosition.y + rectHeight));
	return (DeltaX * DeltaX + DeltaY * DeltaY) < (circleRadius * circleRadius);
}

bool Character::circleCircleCollision(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2)
{
	sf::Vector2f between = position1 - position2;
	return sqrt(between.x * between.x + between.y * between.y) < radius1 + radius2;
}

void Character::setPosition(sf::Vector2f t_pos)
{
	position = t_pos;
}

Grid Character::getGrid()
{
	return grid;
}

void Character::render(sf::RenderWindow& t_window, sf::Vector2f offset, sf::Color colour)
{
	if (health > 0)
	{
		shape.setFillColor(colour);
		shape.setPosition(position + offset);
		t_window.draw(shape);
	}
	if (bulletAlive)
	{
		bulletShape.setPosition(bulletPosition + offset);
		t_window.draw(bulletShape);
	}
}
