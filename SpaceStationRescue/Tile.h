#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Tile
{
public:
	Tile(sf::Vector2f t_pos, int size);

	//functional functions
	void render(sf::RenderWindow& t_window, sf::Vector2f offset);
	void reset();
	static float distanceBetween(Tile first, Tile second);

	//accessors
	void setPosition(sf::Vector2f t_pos) { pos = t_pos; };
	sf::Vector2f getPosition() { return pos; };

	std::vector<Tile*>* getNeightbours() { return &neighbours; };

	void setWall(bool wall) { isWall = wall; };
	bool getWall() { return isWall; };

	int getSize() { return tileSize; };

	float getDistance() { return distance; };
	void setDistance(float d) { distance = d; };

	float getTotalDistance() { return totalDistance; };
	void setTotalDistance(float d) { totalDistance = d; };

	Tile* getPrevious() { return previous; };
	void setPrevious(Tile* p) { previous = p; };

	bool operator < (const Tile& lhs);

	float totalDistance;
private:

	sf::Vector2f pos;
	bool isWall;

	float tileSize;
	int weight;
	sf::RectangleShape shape;
	std::vector<Tile*> neighbours;

	float distance;
	Tile* previous;
	bool searched;

	sf::Vertex line[2];
};

struct LessThanByTotalDistance
{
	bool operator()(const Tile* lhs, const Tile* rhs) const
	{
		return lhs->totalDistance > rhs->totalDistance;
	}
};