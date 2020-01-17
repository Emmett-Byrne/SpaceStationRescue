#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <algorithm>
#include <iostream>

class Character
{
public:
	Character(sf::Vector2f _pos, float _speed, float _size, int h, Grid& _grid);

	void move(sf::Vector2f direction);
	void pathTo(sf::Vector2f location);
	void followPath();

	void wander();

	sf::Vector2f getPosition() { return position; };
	float getRadius() { return radius; };
	sf::Vector2f getBulletPosition() { return bulletPosition; };
	float getBulletRadius() { return bulletRadius; };
	void takeDamage(int damage);
	int getHealth() { return health; };
	void updateBullet(sf::Time dt);
	void shootBullet(sf::Vector2f location, sf::Vector2f direction);
	void setHealth(int num);
	void setSpeed(float t_speed);
	float getSpeed();

	Tile* collidesWithWorld(sf::Vector2f pos, float rad);
	bool collidesWithBounds(sf::Vector2f& pos, float rad);
	static bool circleRectCollision(sf::Vector2f circlePosition, int circleRadius, sf::Vector2f rectPosition, int rectWidth, int rectHeight);
	static bool circleCircleCollision(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2);

	void setPosition(sf::Vector2f t_pos);
	Grid getGrid();

	virtual void render(sf::RenderWindow& t_window, sf::Vector2f offset, sf::Color colour);

	Tile* target;
private:

	sf::Vector2f position;
	sf::Vector2f bulletPosition;
	sf::Vector2f bulletDirection;
	float speed;
	float bulletSpeed;
	float radius;
	float bulletRadius;

	bool bulletAlive;
	sf::Time bulletTimer;
	int health;

	std::vector<sf::Vector2f> path;

	Grid& grid;

	sf::CircleShape shape;
	sf::CircleShape bulletShape;
};

