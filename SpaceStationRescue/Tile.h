#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Tile
{
public:
	Tile(sf::Vector2f t_pos, int size);

	//functional functions
	void render(sf::RenderWindow& t_window, bool drawLine);
	void reset();

	//accessors
	void setPosition(sf::Vector2f t_pos) { pos = t_pos; };
	sf::Vector2f getPosition() { return pos; };

	void setWeight(int t_weight) { weight = t_weight; ; };
	int getWeight() { return weight; };

	std::vector<Tile*>* getNeightbours() { return &neighbours; };

	void setClosestNeighbour();
	Tile* getClosestNeighbour();

	void setWall(bool wall) { isWall = wall; };
	bool getWall() { return isWall; };

	int getSize() { return tileSize; };

private:
	sf::Vector2f pos;
	bool isWall;

	float tileSize;
	int weight;
	sf::RectangleShape shape;
	std::vector<Tile*> neighbours;
	Tile* closestNeighbour;

	sf::Vertex line[2];
};

