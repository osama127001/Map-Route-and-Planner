#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include "Graph_Node.h"
#include "LinkedList.h"
#include<string>
struct Graph
{

	Graph_Node *Nodes[1000];
	int Nodes_iterator;

	Graph();
	void Connect_GraphNode(Graph_Node *X, Graph_Node *Y, float distances);
	void Create_GraphNode(std::string);
	Graph_Node* Search_andReturn(std::string C_name);
	void Display_Connections();
	void Read_andCreateGraph(std::string File_Path);
	LinkedList TjKSTRA_ALGO_ForShortestPath(Graph_Node *Source, Graph_Node *Destination);
	LinkedList SHORTEST_PATH(Graph_Node *Source, Graph_Node *Destination, LinkedList Paths);
	void Convert_SystemString_to_STD_STRING(System::String^ X, std::string &s);

};

#endif // !GRAPH_H

