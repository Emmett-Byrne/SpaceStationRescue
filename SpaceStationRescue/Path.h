#pragma once
#include <vector>
#include "Node.h"
class Path
{
public:
	Path();
	
	void addNode(Node node, int index, int links[], int arraySize);
	void setup();
private:
	std::vector<Node> nodes;
};

