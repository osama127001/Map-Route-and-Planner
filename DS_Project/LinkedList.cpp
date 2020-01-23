#include"Node.h"
#include"LinkedList.h"
#include<conio.h>
#include<iostream>
#include"Graph_Node.h"

LinkedList::LinkedList()
{
	Head = NULL;
}
	
//LinkedList::LinkedList(LinkedList &N)
//{
//	std::cout << "Copy Constructor called" << std::endl;
//	//Head = N.Head;
//	Node  *temp = N.Head;
//	while (temp != NULL)
//	{
//		Insert_End(temp->Data);
//		temp = temp->Next;
//	}
//}

void LinkedList::Insert_Start(Graph_Node *data)
{
	Node  *n = new Node ;
	n->Data = data;
	n->Next = Head;
	Head = n;
}

	
void LinkedList::Delete_Start()
{
	if (Head != NULL)
	{
		Node  *temp = Head;
		Head = Head->Next;
		delete temp;
		temp = NULL;
	}
}

	
void LinkedList::Insert_End(Graph_Node *data)
{
	if (Head == NULL)
	{
		Insert_Start(data);
	}
	else
	{
		Node  *n = new Node ;
		n->Data = data;

		Node  *temp = Head;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = n;
		n->Next = NULL;
	}
}

	
void LinkedList::Delete_End()
{
	Node  *temp = Head;
	if (Head->Next == NULL)
	{
		Head = NULL;
		delete temp;
		temp = NULL;
	}
	else if (Head->Next != NULL)
	{
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		Node  *temp2 = temp;
		temp = Head;
		while (temp->Next != temp2)
		{
			temp = temp->Next;
		}
		temp->Next = NULL;
		delete temp2;
		temp2 = NULL;
	}
}

	
void LinkedList::Traverse()
{
	Node  *temp = Head;
	if (temp == NULL)
	{
		std::cout << "Lindked List is Empty!!" << std::endl;
	}
	else
	{
		while (temp != NULL)
		{
			std::cout << temp->Data->City_Name << " ";
			temp = temp->Next;
		}
	}
	std::cout << std::endl;
}

	
Node *LinkedList::Search(Graph_Node *data)
{
	if (Head != NULL)
	{
		Node  *temp = Head;
		int Counter = 0;
		bool flag;
		while (temp != NULL)
		{
			Counter = Counter + 1;
			if (temp->Data == data) { flag = true; break; }
			else { flag = false; }
			temp = temp->Next;
		}
		return temp;
	}
	else { std::cout << "Nothing to search!, Linked list is Empty." << std::endl << std::endl; }
}

	
bool LinkedList::IsEmpty()
{
	if (Head == NULL)
	{
		return true;
	}
	else if (Head != NULL)
	{
		return false;
	}
}

	
int LinkedList::Counter()
{
	Node  *temp = Head;
	int Counter = 0;
	while (temp != NULL)
	{
		Counter = Counter + 1;
		temp = temp->Next;
	}
	return Counter;
}

	
void LinkedList::Insert_AtAnyPosition(int Pos, Graph_Node *data)
{
	Node  *temp = Head;
	Node  *temp2 = Head;
	Node  *N = new Node ;
	N->Data = data;
	if (Pos == 1)
	{
		Insert_Start(data);
	}
	else if (Pos == Counter() + 1)
	{
		Insert_End(data);
	}
	else if (Pos > Counter() + 1)
	{
		std::cout << "Position Does Not Exist. " << std::endl;
	}
	else
	{
		for (int i = 0; i < Pos - 2; i++)
		{
			temp = temp->Next;
		}
		for (int i = 0; i < Pos - 1; i++)
		{
			temp2 = temp2->Next;
		}
		temp->Next = N;
		N->Next = temp2;
	}
}

	
void LinkedList::Delete_AtAnyPosition(int Pos)
{
	Node  *temp = Head;
	Node  *temp2 = Head;
	if (Pos == 1)
	{
		Delete_Start();
	}
	else if (Pos == Counter())
	{
		Delete_End();
	}
	else if (Pos > Counter())
	{
		std::cout << "Position Does Not Exist. " << std::endl;
	}
	else
	{
		for (int i = 0; i < Pos - 2; i++)
		{
			temp = temp->Next;
		}
		for (int i = 0; i < Pos - 1; i++)
		{
			temp2 = temp2->Next;
		}
		temp->Next = temp2->Next;
		delete temp2;
		temp2 = NULL;
	}
}

Node *LinkedList::GetHead()
{
	return Head;
}

void LinkedList::Insert_Once(Graph_Node *data)
{
	if (!SearchTheElement(data))
	{
		Insert_End(data);
	}
}

bool LinkedList::SearchTheElement(Graph_Node *data)
{
	if (Head != NULL)
	{
		Node  *temp = Head;
		bool flag;
		while (temp != NULL)
		{
			if (temp->Data == data) { flag = true; break; }
			else { flag = false; }
			temp = temp->Next;
		}
		return flag;
	}
	else { return false; }

}

void LinkedList::Destroy_LinkedList()
{
	while (Head != NULL)
	{
		Delete_Start();
	}
}

void LinkedList::Traverse_2() // Traverse Nodes With Prevous Nodes (Nodes that Updated the distances)
{
	Node  *temp = Head;
	if (temp == NULL)
	{
		std::cout << "Lindked List is Empty!!" << std::endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->Data->Previous != NULL) { std::cout << temp->Data->City_Name << "(" << temp->Data->Previous->City_Name << ")" << " "; }
			else if (temp->Data->Previous == NULL) { std::cout << temp->Data->City_Name << " "; }
			temp = temp->Next;
		}
	}
	std::cout << std::endl;
}


