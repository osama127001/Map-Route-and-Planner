#include "PriorityQueue.h"
#include"PriorityQueue_Node.h"

#include"Graph.h"
#include"Graph_Node.h"


#include<conio.h>
#include<iostream>
#include<string>

	PriorityQueue::PriorityQueue() : Front_(NULL), Rear_(NULL) {}

	void PriorityQueue::ENQUEUE_(Graph_Node *data, float Prio)
	{
		PriorityQueue_Node *Element = new PriorityQueue_Node;
		Element->Data = data;
		Element->Priority = Prio;
		Element->Next = Rear_;
		Rear_ = Element;

		PriorityQueue_Node *temp = Rear_;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		Front_ = temp;
		if (Rear_ != NULL && Rear_ != Front_)
		{
			Check_n_Swap();
		}
	}

	void PriorityQueue:: DEQUEUE_()
	{
		PriorityQueue_Node *temp = Rear_;
		PriorityQueue_Node *Node_to_Dequeue = Front_;
		if (Front_ == Rear_)
		{
			delete temp;
			Rear_ = NULL;
			Front_ = NULL;
		}
		else if (Front_ != Rear_)
		{
			while (temp->Next != Front_)
			{
				temp = temp->Next;
			}
			temp->Next = NULL;
			Front_ = temp;
			delete Node_to_Dequeue;
			Node_to_Dequeue = NULL;
		}
	}

	void PriorityQueue::DEQUEUE_REAR_()
	{
		PriorityQueue_Node *temp = Rear_;
		if (Front_ == Rear_)
		{
			delete temp;
			Rear_ = NULL;
			Front_ = NULL;
		}
		else if (Front_ != Rear_)
		{
			Rear_ = Rear_->Next;
			delete temp;
			temp = NULL;
		}

	}

	void PriorityQueue:: GET_FRONT()
	{
		std::cout << Front_->Data << std::endl << std::endl;
	}

	void PriorityQueue:: TRAVERSE_()
	{
		PriorityQueue_Node *temp = Rear_;
		std::cout << "Rear ->  ";
		if (Rear_ == NULL)
		{
			std::cout << "Queue is Empty!";
		}
		else if (Rear_ != NULL)
		{
			while (temp != NULL)
			{
				std::cout << temp->Data->City_Name << "(" << temp->Priority << ")" << "  ";
				temp = temp->Next;
			}
			std::cout << "<- Front";
		}
		std::cout << std::endl;
	}

	void PriorityQueue:: Check_n_Swap()
	{
		PriorityQueue_Node *temp = Rear_;
		PriorityQueue_Node *Swapping_Agent;
		while (true)
		{
			if (temp == NULL) { break; }
			else if (temp->Next != NULL && temp->Next->Priority < temp->Priority)
			{
				if (temp == Rear_)
				{
					Swapping_Agent = temp->Next;
					temp->Next = temp->Next->Next;
					Swapping_Agent->Next = temp;
					Rear_ = Swapping_Agent;
					if (temp->Next != NULL && temp->Next->Priority < temp->Priority) { goto again; }
				}
				else if (temp != Rear_)
				{
				again:
					Swapping_Agent = temp->Next;
					PriorityQueue_Node *temp2 = Rear_;
					while (temp2->Next != temp)
					{
						temp2 = temp2->Next;
					}
					temp2->Next = Swapping_Agent;
					temp->Next = Swapping_Agent->Next;
					Swapping_Agent->Next = temp;
					if (temp->Next != NULL && temp->Next->Priority < temp->Priority) { goto again; }
				}
			}
			temp = temp->Next;
		}
		temp = Rear_;
		while (temp->Next != NULL) { temp = temp->Next; }
		Front_ = temp;
	}

