#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE



#pragma once
#include"PriorityQueue_Node.h"
#include<string>

#include"Graph.h"
#include"Graph_Node.h"


struct PriorityQueue
{
	PriorityQueue_Node *Front_;
	PriorityQueue_Node *Rear_;
public:
	PriorityQueue();
	void ENQUEUE_(Graph_Node *data, float Prio);
	void DEQUEUE_();
	void DEQUEUE_REAR_();
	void GET_FRONT();
	void TRAVERSE_();
	void Check_n_Swap();
};

#endif // !PRIORITYQUEUE_H
