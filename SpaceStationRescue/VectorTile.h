#pragma once
#include <SFML/Graphics.hpp>

class VectorTile
{
public:
	VectorTile(sf::Vector2f t_pos);

	//functional functions
	void reset();

	//accessors
	void setPosition(sf::Vector2f t_pos) { pos = t_pos; };
	sf::Vector2f getPosition() { return pos; };

	void setWeight(int t_weight) { weight = t_weight; ; };
	int getWeight() { return weight; };

	std::vector<VectorTile*>* getNeightbours() { return &neighbours; };

	void setClosestNeighbour();
	VectorTile* getClosestNeighbour();

	void setWall(bool wall) { isWall = wall; };
	bool getWall() { return isWall; };

	sf::Vector2f getDirection() { return getClosestNeighbour()->getPosition() - pos; };

	static VectorTile* findFromField(std::vector<VectorTile>& field, sf::Vector2f position);

private:
	sf::Vector2f pos;
	bool isWall;

	int weight;
	std::vector<VectorTile*> neighbours;
	VectorTile* closestNeighbour;
};

