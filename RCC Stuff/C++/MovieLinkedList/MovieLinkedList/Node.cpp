#include <iostream>
using std::cout;
using std::endl;
#include "Node.h"

Node::Node(Movies data) : m_data(data), m_next(nullptr)
{ 
	cout << "Node 1 Arg CTOR Called..." << endl;
}

Node::Node(const Node& copy) : m_data(copy.m_data), m_next(copy.m_next)
{ 
	cout << "Node Copy CTOR Called..." << endl;
}

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

Node::~Node()
{
	cout << "Node DTOR Called..." << endl;
}

Node* Node::getNext()
{
	return m_next;
}

void Node::setNext(Node* next)
{
	m_next = next;
}

Movies Node::getData()
{
	return m_data;
}

void Node::setData(Movies data)
{
	m_data = data;
}
