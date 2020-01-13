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

	//accessors
	void setPosition(sf::Vector2f t_pos) { pos = t_pos; };
	sf::Vector2f getPosition() { return pos; };

	std::vector<Tile*>* getNeightbours() { return &neighbours; };

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

	sf::Vertex line[2];
};

