#pragma once
#include "Node.h"

const int EMPTY_LIST = -2;
/************************************************************************
* Class: List
*
* Purpose: This class is designed to contain the Node class and handle the organization,
*			addition, and deletion of Nodes.
*
* Manager functions:
* 	List ()
* 		The default constructor for the List.
*	List (const List& copy)
*		Creates a copy of a List.
*	List operator =(const List& rhs)
*	~List()
*		Destructor for List
* Methods:
*	void Display() const;		
*			Displays the List to the screen.
*	void PushFront(Potion data);
*		add a new Node to the list and put it at the front of the list.
*	void PushBack(Potion data)
*		add a new Node to the list and put it at the back of the list.
*	void InsertOrdered(Potion data)
*		add a new Node to the list and put it in order with with the list
*		based on the Name.
*	void Purge();
*		Purge all the Nodes from the list.
*	void DeleteNode()
*		Delete a Node from the list based on its name.
*	Potion Front()
*		Return the information for the item at the front of the list
*	Potion Back()
*		Return the information for the item at the back of the list
*	Potion PopFront()
*		Return the information for the item at the front of the list and
*		then delete that node.
*	Potion PopBack()
*		Return the information for the item at the back of the list and
*		then delete that node
*	Potion GetIthElement(int element)
*		Return the information for the item at a specified location of the list.
*	void Save(ofstream& fout)
*		Save the List to a binary file.
*	void Load(ifstream& fout)
*		Load the List to a binary file.
*************************************************************************/

class List
{
public:
	List();
	List(const List& copy);
	List& operator =(const List& rhs);
	~List();
	void PushFront(Potion data);
	void PushBack(Potion data);
	void InsertOrdered(Potion data);
	void Purge();
	void Display() const;
	void DeleteNode(String name);
	Potion Front();
	Potion Back();
	Potion PopFront();
	Potion PopBack();
	Potion GetIthElement(int element);
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	Node* m_head;

	int m_counter;
};