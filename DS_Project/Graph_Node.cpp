#include "Graph_Node.h"

Graph_Node::Graph_Node()
{
	Shortest_Distance = -1;
	Previous = NULL;
	check = true;
	for (int i = 0; i < 100; i++)
	{
		Distances[i] = -1;
		Next[i] = NULL;
	}
}