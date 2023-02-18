#pragma once
#include "Potion.h"

/************************************************************************
* Class: Node
*
* Purpose: This class is designed to contain the information of another class
*			and be added to a List.
*
* Manager functions:
* 	Node ()
* 		The default constructor for the Node.
*	Node(Potion data)
*		The one arg constructor for the Node.
*	Node (const Node& copy)
*		Creates a copy of a Node.
*	Node operator =(const Node& rhs)
*	~Node()
*		Destructor for Node
* Methods:
*	Node* getNext()
*		Returns the m_next data member
*	void setNext(Node* next)
*		Set m_next to variable.
*	Potion getData()
*		Returns item that is being held in the Node
*	void setData(Potion data)
*		Set m_data to the variable.
*	void Save(ofstream& fout)
*		Save the Node to a binary file.
*	void Load(ifstream& fout)
*		Load the Node to a binary file.
*************************************************************************/

class Node
{
public:
	static int count;
private:
	friend class List;
	Potion m_data;
	Node* m_next;
	Node();
	Node(Potion data);
	Node(const Node& copy);
	Node& operator = (const Node& rhs);
	~Node();
	Node* getNext();
	void setNext(Node* next);
	Potion getData();
	void setData(Potion data);
	void Save(ofstream& fout);
	void Load(ifstream& fout);
};

