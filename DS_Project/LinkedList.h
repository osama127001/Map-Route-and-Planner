#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#pragma once
#include"Node.h"
#include"Graph_Node.h"

class LinkedList
{

private:
	Node* Head;

public:

	LinkedList();
	//LinkedList(LinkedList  &N);
	void Insert_Start(Graph_Node *data);
	void Delete_Start();
	void Insert_End(Graph_Node *data);
	void Delete_End();
	void Traverse();
	Node *Search(Graph_Node *data);
	bool IsEmpty();
	int Counter();
	void Insert_AtAnyPosition(int Pos, Graph_Node *data);
	void Delete_AtAnyPosition(int Pos);
	Node *GetHead();
	void Insert_Once(Graph_Node *data);
	bool SearchTheElement(Graph_Node *data);
	void Destroy_LinkedList();
	void Traverse_2();


};


#endif // !LINKEDLIST_H
