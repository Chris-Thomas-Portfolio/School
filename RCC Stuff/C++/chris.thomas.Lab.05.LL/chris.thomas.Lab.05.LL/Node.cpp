#include <iostream>
using std::cout;
using std::endl;
#include "Node.h"

/**********************************************************************
* Purpose: This is the default constructor for the Node class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default List.
*
************************************************************************/

Node::Node() : m_data(), m_next(nullptr)
{ }

/**********************************************************************
* Purpose: This is the one arg constructor for the Node class
*
* Precondition:	N/A.
*
* Postcondition: Creates a Node with containing the arg.
*
************************************************************************/

Node::Node(Potion data) : m_data(data), m_next(nullptr)
{
	cout << "Node 1 Arg CTOR Called..." << endl;
	count++;
}

/**********************************************************************
* Purpose: This is the copy constructor for the Node class
*
* Precondition:	Need a Node.
*
* Postcondition: Creates a copy of the Node.
*
************************************************************************/

Node::Node(const Node& copy) : m_data(copy.m_data), m_next(copy.m_next)
{
	cout << "Node Copy CTOR Called..." << endl;
}

/**********************************************************************
* Purpose: This is the operator equals for the Node class
*
* Precondition:	Need a Node.
*
* Postcondition: Sets the Node equal to the Node on the rhs.
*
************************************************************************/

Node& Node::operator=(const Node& rhs)
{
	cout << "Node Operator = Called..." << endl;
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
	}

	return *this;
}

/**********************************************************************
* Purpose: This is the DTOR for the Node class
*
* Precondition:	Need a Node.
*
* Postcondition: Destroys a the Node.
*
************************************************************************/

Node::~Node()
{
	cout << "Node DTOR Called..." << endl;
}

/**********************************************************************
* Purpose: This function returns the data member m_next
*
* Precondition:	Need a Node.
*
* Postcondition: Return the data member m_next.
*
************************************************************************/

Node* Node::getNext()
{
	return m_next;
}

/**********************************************************************
* Purpose: This function sets the data member m_next
*
* Precondition:	Need a Node.
*
* Postcondition: Set the data member m_next.
*
************************************************************************/

void Node::setNext(Node* next)
{
	m_next = next;
}

/**********************************************************************
* Purpose: This function returns the data member m_data
*
* Precondition:	Need a Node.
*
* Postcondition: Return the data member m_data.
*
************************************************************************/

Potion Node::getData()
{
	return m_data;
}

/**********************************************************************
* Purpose: This function sets the data member m_data
*
* Precondition:	Need a Node.
*
* Postcondition: Set the data member m_data.
*
************************************************************************/

void Node::setData(Potion data)
{
	m_data = data;
}

/**********************************************************************
* Purpose: This function saves the Node to a binary file
*
* Precondition:	Need a Node.
*
* Postcondition: Binary file created with information of Node.
*
************************************************************************/

void Node::Save(ofstream& fout)
{
	m_data.Save(fout);
}

/**********************************************************************
* Purpose: This function loads the Node from a binary file
*
* Precondition:	Need a Node.
*
* Postcondition: Node created with information of binary file.
*
************************************************************************/

void Node::Load(ifstream& fout)
{
	m_data.Load(fout);
}