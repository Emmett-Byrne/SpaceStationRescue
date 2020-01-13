#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Node
{
public:
	Node(sf::Vector2f t_position) : position(t_position), searched(false), distance(9999) 
	{};

	sf::Vector2f position;
	bool searched;
	float distance;
	std::vector<Node*> neighbours;
};