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
	int arr[4] = { 1,0,0,0 };
	addNode(Node(sf::Vector2f(900, 100)), 0, arr, 1);

	arr[0] = 0;
	arr[1] = 2;
	addNode(Node(sf::Vector2f(1400, 100)), 1, arr, 2);

	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 7;
	addNode(Node(sf::Vector2f(1400, 1300)), 2, arr, 4);

	arr[0] = 2;
	addNode(Node(sf::Vector2f(900, 1300)), 3, arr, 1);

	arr[0] = 2;
	arr[1] = 5;
	arr[2] = 6;
	arr[3] = 18;
	addNode(Node(sf::Vector2f(900, 100)), 4, arr, 3);
	addNode(Node(sf::Vector2f(900, 100)), 5, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 6, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 7, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 8, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 9, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 10, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 11, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 12, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 13, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 14, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 15, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 16, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 17, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 18, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 19, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 20, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 21, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 22, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 23, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 24, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 25, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 26, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 27, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 28, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 29, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 30, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 31, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 32, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 33, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 34, arr, 1);
	addNode(Node(sf::Vector2f(900, 100)), 35, arr, 1);
}
