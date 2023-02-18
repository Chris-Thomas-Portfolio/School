#pragma once

#include "Node.h"
class List
{
public:
	List();
	List(const List& copy);
	List& operator =(const List& rhs);
	~List();
	void Prepend(Movies data);
	void Append(Movies data);
	void InsertOrdered(Movies data);
	void Purge();
	void Display();
	void DeleteNode(string name);
private:
	Node* m_head;
};

