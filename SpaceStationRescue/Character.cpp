#include "Character.h"

Character::Character(sf::Vector2f _pos, float _speed, float _size, Grid& _grid) :
	grid(_grid),
	radius(_size),
	speed(_speed),
	position(_pos)
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
}

void Character::render(sf::RenderWindow& t_window)
{
	shape.setPosition(position);
	t_window.draw(shape);
}
