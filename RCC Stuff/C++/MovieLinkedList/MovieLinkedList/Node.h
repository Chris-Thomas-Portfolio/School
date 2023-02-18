#pragma once

#include "Movies.h"

class Node
{
public:
	Node(Movies data);
	Node(const Node& copy);
	Node& operator = (const Node& rhs);
	~Node();
	Node* getNext();
	void setNext(Node* next);
	Movies getData();
	void setData(Movies data);
private:
	Movies m_data;
	Node * m_next;                                  
};

