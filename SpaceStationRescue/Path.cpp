#include "Path.h"

Path::Path()
{
	nodes.resize(36);
}

void Path::addNode(Node node, int index, int links[], int arraySize)
{
	nodes[index] = node;

	for (int i = 0; i < arraySize; i++)
	{
		nodes[index].neighbours.push_back(&nodes[links[i]]);
	}
}

void Path::setup()
{
	int arr[4] = { 0,0,0,0 };
	addNode(Node(sf::Vector2f(900, 100)), 0, arr, 1);
}
