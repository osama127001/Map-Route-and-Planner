#pragma once


#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <string>
#include <list>

struct Graph_Node
{	
	std::string City_Name = " ";
	Graph_Node *Next[100];
	Graph_Node *Previous;
	float Distances[100];
	float Shortest_Distance;
	Graph_Node();
	bool check;
};

#endif // !GRAPH_NODE_H




