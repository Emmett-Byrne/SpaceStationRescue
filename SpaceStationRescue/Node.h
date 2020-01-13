#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Node
{
public:
	Node() : position(sf::Vector2f(0, 0)), searched(false), distance(9999) {};
	Node(sf::Vector2f t_position) : position(t_position), searched(false), distance(9999) 
	{};

	sf::Vector2f position;
	bool searched;
	float distance;
	std::vector<Node*> neighbours;
};