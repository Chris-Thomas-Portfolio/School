#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

List::List() : m_head(nullptr)
{
	cout << "List default CTOR called..." << endl;
}

List::List(const List& copy) : m_head(nullptr)
{
	cout << "List copy CTOR called..." << endl;
	if (copy.m_head != nullptr)
	{
		Node* travel = copy.m_head;

		while (travel != nullptr)
		{
			Append(travel->getData());
			travel = travel->getNext();
		}
	}
}

List & List::operator =(const List& rhs)
{
	cout << "List operator = called..." << endl;
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Purge the LHS
		Purge();

		// 3. Deep copy
		if (rhs.m_head != nullptr)                                                  
		{
			Node* travel = rhs.m_head;

			while (travel != nullptr)
			{
				Append(travel->getData());
				travel = travel->getNext();
			}
		}
	}


	// 4. Return reference to class
	return *this;
}

List::~List()
{
	cout << "List DTOR called..." << endl;
	Purge();
}

void List::Prepend(Movies data)
{
	Node* nn = new Node(data);

	nn->setNext(m_head);
	m_head = nn;
}

void List::Append(Movies data)
{
	Node* nn = new Node(data);

	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else 
	{
		Node* travel = m_head;

		while (travel->getNext() != nullptr)
		{
			travel = travel->getNext();
		}

		travel->setNext(nn);
	}
}

void List::InsertOrdered(Movies data)
{
	Node* nn = new Node(data);

	if ((m_head == nullptr) || (nn->getData().getName() <= m_head->getData().getName()))
	{
		nn->setNext(m_head);
		m_head = nn;
	}
	else
	{
		Node* travel = m_head;
		Node* trail = nullptr;

		while ((travel != nullptr) && (travel->getData().getName() <= nn->getData().getName()))
		{
			trail = travel;
			travel = travel->getNext();
		}
		trail->setNext(nn);
		nn->setNext(travel);
	}
}

void List::Purge()
{
	Node* trail = nullptr;

	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->getNext();
		delete trail;
	}
}

void List::Display()
{
	Node* travel = m_head;
	
	while (travel != nullptr)
	{
		travel->getData().Display();
		travel = travel->getNext();
	}
}

void List::DeleteNode(string name)
{
	if (m_head == nullptr)
	{
		cout << "Sorry, List is currently empty." << endl;
	}
	else if (m_head->getData().getName() == name)
	{
		Node* trail = m_head;
		m_head = m_head->getNext();
		delete trail;
	}
	else
	{
		Node* travel = m_head;
		Node* trail = nullptr;

		while (travel != nullptr && travel->getData().getName() != name)
		{
			trail = travel;
			travel = travel->getNext();
		}

		if (travel == nullptr)
		{
			cout << name << " not found in the list." << endl;
		}
		else
		{
			trail->setNext(travel->getNext());
			delete travel;
		}
	}
}
