#ifndef PRIORITYQUEUE_NODE_H
#define PRIORITYQUEUE_NODE_H


#pragma once
#include"Graph.h"
#include"Graph_Node.h"

#include<conio.h>
#include<string>
struct PriorityQueue_Node
{
	Graph_Node *Data;
	PriorityQueue_Node *Next;
	float Priority;
	PriorityQueue_Node(); 
};

#endif // !PRIORITYQUEUE_NODE_H


