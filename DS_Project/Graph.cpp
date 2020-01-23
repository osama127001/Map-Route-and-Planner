#include "Graph_Node.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include"Node.h"

#include<string>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<limits>


Graph::Graph()
{
	for (int i = 0; i < 1000; i++)
	{
		Nodes[i] = NULL;
	}
	Nodes_iterator = 0;
}

void Graph::Connect_GraphNode(Graph_Node *X, Graph_Node *Y, float distance)
{
	//Returns if already connected.
	for (int i = 0; X->Next[i] != NULL; i++)
	{
		if (X->Next[i]->City_Name == Y->City_Name)
		{
			return;
		}
	}

	//connects X with Y
	int iterator = 0;
	while (true)
	{
		if (X->Next[iterator] == NULL)
		{
			X->Next[iterator] = Y;
			X->Distances[iterator] = distance;
			break;
		}
		else
		{
			if (iterator > 101)
			{
				break;
			}
		}
		iterator++;
	}

	//connects Y with X
	iterator = 0;
	while (true)
	{
		if (Y->Next[iterator] == NULL)
		{
			Y->Next[iterator] = X;
			Y->Distances[iterator] = distance;
			break;
		}
		else
		{
			if (iterator > 101)
			{
				break;
			}
		}
		iterator++;
	}
}

void Graph::Create_GraphNode(std::string C_Name)
{
	Graph_Node *N = new Graph_Node;
	N->City_Name = C_Name;
	Nodes[Nodes_iterator] = N;
	Nodes_iterator++;
}

Graph_Node *Graph::Search_andReturn(std::string C_name)
{
	int iterator = 0;
	while (true)
	{
		if (Nodes[iterator] != NULL && Nodes[iterator]->City_Name == C_name)
		{
			break;
		}
		else if(Nodes[iterator] == NULL)
		{
			break;
		}
		iterator++;
	}
	return Nodes[iterator];
}

void Graph::Display_Connections()
{
	int iterator = 0;
	while (true)
	{
		if (Nodes[iterator] == NULL)
		{
			break;
		}
		else
		{
			std::cout << Nodes[iterator]->City_Name << "\n";
			std::cout << "Connections: \n";
			for(int i = 0; Search_andReturn(Nodes[iterator]->City_Name)->Next[i] != NULL; i++)
			{
				std::cout << Nodes[iterator]->Next[i]->City_Name << "(" << Nodes[iterator]->Distances[i] << ")\n";
			}
			std::cout << std::endl;
		}
		iterator++;
	}
}

void Graph::Read_andCreateGraph(std::string File_Path)
{
	std::ifstream File;
	File.open(File_Path);
	char use[100];
	char Dist[10];
	if (File.is_open())
	{
		std::string Read;
		std::string Read2;
		File >> Read;
		while (true)
		{
			if (Read == "x")
			{
			y:
				File >> Read2; //city without distance
				File >> Read; //city with distance
			z:
				for (int i = 0; i < 100; i++) { use[i] = NULL; }
				for (int i = 0; i < 10; i++) { Dist[i] = NULL; }
				for (int i = 0; Read[i] != '('; i++) 
				{
					use[i] = Read[i];
				}
				int i = 0;
				int j = 0;
				while (true)
				{
					if (Read[i] == '(')
					{
						i++;
						while (Read[i] != ')')
						{
							Dist[j] = Read[i];
							i++;
							j++;
						}
						break;
					}
					i++;
				}

				//Converting char array to string.	
				std::string C_to_Connect(use);

				//converting string distance into integer.
				std::stringstream Convert(Dist);
				int Distance_ = 0;
				Convert >> Distance_;

				//std::cout << C_to_Connect << std::endl;
				//std::cout << Read2 << std::endl;
				//std::cout << Distance_ << std::endl;

				//check if node exists, if not then create;
				bool Check = false;
				bool Check2 = false;
				for (int i = 0; Nodes[i] != NULL; i++)
				{
					if (Nodes[i] != NULL && Nodes[i]->City_Name == Read2) { Check = true; }
					if (Nodes[i] != NULL && Nodes[i]->City_Name == C_to_Connect) { Check2 = true; }
				}
				if (!Check) { Create_GraphNode(Read2); }
				if (!Check2) { Create_GraphNode(C_to_Connect); }

				Connect_GraphNode(Search_andReturn(Read2), Search_andReturn(C_to_Connect), Distance_);
				File >> Read;
				if (Read == "y") { break; }
				else if (Read == "x") { goto y; }
				else { goto z; }

				
			}
			break;
		}
		//if (Search_andReturn(Read) == NULL)
		//{
		//	Create_GraphNode(Read);
		//}
	}
	File.close();

}

LinkedList Graph::TjKSTRA_ALGO_ForShortestPath(Graph_Node *Source, Graph_Node *Destination)
{
	LinkedList Paths;
	PriorityQueue Q; //call check_n_swap menually

	//Making the Distances of every Node -1(inf) and source to 0.
	for (int i = 0; Nodes[i] != NULL; i++)
	{
		Nodes[i]->Shortest_Distance = std::numeric_limits<float>::infinity();
	}
	Source->Shortest_Distance = 0;

	//insert in queue
	for (int i = 0; Nodes[i] != NULL; i++)
	{
		Q.ENQUEUE_(Nodes[i], Nodes[i]->Shortest_Distance);
	}

	//
	while (Q.Rear_ != NULL)
	{
		Graph_Node *U = Q.Rear_->Data;

		//Relax_Function
		for (int i = 0; U->Next[i] != NULL; i++)
		{
			if (U->Next[i]->Shortest_Distance > U->Shortest_Distance + U->Distances[i])
			{
				U->Next[i]->Shortest_Distance = U->Shortest_Distance + U->Distances[i];
				Paths.Insert_Once(U);
				U->Next[i]->Previous = U;


				//Updating Queue with Shortest Distance.
				PriorityQueue_Node *temp = Q.Rear_;
				while (temp != NULL)
				{
					if (temp->Data == U->Next[i]) //&& temp->Data->Shortest_Distance > U->Next[i]->Shortest_Distance)
					{
						temp->Priority = U->Next[i]->Shortest_Distance;
						temp->Data->Shortest_Distance = U->Next[i]->Shortest_Distance;
					}
					temp = temp->Next;
				}
			}
		}
		PriorityQueue_Node *temp = Q.Rear_;
		while (temp != NULL) { Q.Check_n_Swap(); temp = temp->Next; }
		Q.DEQUEUE_REAR_();
	}
	Paths.Insert_Once(Destination);
	return Paths;
}

LinkedList Graph::SHORTEST_PATH(Graph_Node *Source, Graph_Node *Destination, LinkedList Paths)
{
	LinkedList Exceptional_Path; Exceptional_Path.Insert_End(Source); Exceptional_Path.Insert_End(Destination);
	LinkedList Nodes_to_Check;
	LinkedList Shortest_Path;
	Node *Temp = NULL;


again:
	Node *Continue = Paths.GetHead();
	Shortest_Path.Insert_Start(Source);

again2:
	Temp = Continue;
	while (Temp != NULL) 
	{
		if (Temp->Data->Previous != NULL && Temp->Data->Previous == Continue->Data)
		{
			Nodes_to_Check.Insert_End(Temp->Data);
		}
		Temp = Temp->Next;
	}
		
	Temp = Nodes_to_Check.GetHead();
	while (Temp != NULL)
	{
		if (Temp->Data == Destination)
		{
			Shortest_Path.Insert_End(Destination);
			return Shortest_Path;
		}
		Temp = Temp->Next;
	}

	Temp = Nodes_to_Check.GetHead();
	while (Temp != NULL)
	{
		if (Temp->Data->check != false) 
		{ 
			Shortest_Path.Insert_End(Temp->Data); 
			Continue = Paths.Search(Temp->Data);
			Nodes_to_Check.Destroy_LinkedList();
			goto again2; 
		}
		Temp = Temp->Next;
	}

	Temp = Nodes_to_Check.GetHead();
	bool check_check = false;
	while (Temp != NULL)
	{
		if (Temp->Data->check == true)
		{
			check_check = true;
		}
		Temp = Temp->Next;
	}

	if (Nodes_to_Check.IsEmpty() || !check_check)
	{
		Temp = Shortest_Path.GetHead();
		while (Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		Temp->Data->check = false;
		Shortest_Path.Destroy_LinkedList();
		goto again;
	}

	return Exceptional_Path;
}

void Graph::Convert_SystemString_to_STD_STRING(System::String^ X, std::string &s)
{
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(X)).ToPointer();
	s = chars;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}


