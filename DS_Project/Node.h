#ifndef NODE_H
#define NODE_H


#pragma once
#include"Graph_Node.h"

class Node
{
public:
	Graph_Node *Data;
	Node *Next; //address of the object.
	Node();
};


#endif // !NODE_H
