#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

/**********************************************************************
* Purpose: This is the default constructor for the List class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default List.
*
************************************************************************/

List::List() : m_head(nullptr), m_counter(0)
{
	cout << "List default CTOR called..." << endl;
}

/**********************************************************************
* Purpose: This is the copy constructor for the List class
*
* Precondition:	Need a List.
*
* Postcondition: Creates a copy of the List.
*
************************************************************************/

List::List(const List& copy) : m_head(nullptr)
{
	cout << "List copy CTOR called..." << endl;
	if (copy.m_head != nullptr)
	{
		Node* travel = copy.m_head;

		while (travel != nullptr)
		{
			PushFront(travel->getData());
			travel = travel->getNext();
		}
	}
}

/**********************************************************************
* Purpose: This is the operator equals for the List class
*
* Precondition:	Need a List.
*
* Postcondition: Sets the List equal to the List on the rhs.
*
************************************************************************/

List& List::operator =(const List& rhs)
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
				PushBack(travel->getData());
				travel = travel->getNext();
			}
		}
	}


	// 4. Return reference to class
	return *this;
}

/**********************************************************************
* Purpose: This is the DTOR for the List class
*
* Precondition:	Need a List.
*
* Postcondition: Destroys a the List.
*
************************************************************************/

List::~List()
{
	cout << "List DTOR called..." << endl;
	Purge();
}

/**********************************************************************
* Purpose: This function adds a new Node to the List and puts it at the front
*
* Precondition:	Need a List.
*
* Postcondition: New node is at front of List.
*
************************************************************************/

void List::PushFront(Potion data)
{
	Node* nn = new Node(data);

	nn->setNext(m_head);
	m_head = nn;
	m_counter++;
}

/**********************************************************************
* Purpose: This function adds a new Node to the List and puts it at the back
*
* Precondition:	Need a List.
*
* Postcondition: New node is at back of List.
*
************************************************************************/

void List::PushBack(Potion data)
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
	m_counter++;
}

/**********************************************************************
* Purpose: This function adds a new Node to the List and puts it in order
*			in the List based off of name.
*
* Precondition:	Need a List.
*
* Postcondition: Have a new Node in the List at the in the proper order.
*
************************************************************************/

void List::InsertOrdered(Potion data)
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
	m_counter++;
}

/**********************************************************************
* Purpose: This function removes all Nodes from the List
*
* Precondition:	Need a List.
*
* Postcondition: Have an empty List
*
************************************************************************/

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

/**********************************************************************
* Purpose: This function displays all the information in the List to the user
*
* Precondition:	Need a List.
*
* Postcondition: The entire list is displayed.
*
************************************************************************/

void List::Display() const
{
	Node* travel = m_head;

	while (travel != nullptr)
	{
		travel->getData().Display();
		travel = travel->getNext();
	}
	cout << endl;
}

/**********************************************************************
* Purpose: This function deletes a specific Node from the List
*
* Precondition:	Need a List.
*
* Postcondition: Deletes specified Node from the List.
*
************************************************************************/

void List::DeleteNode(String name)
{
	if (m_head == nullptr)
	{
		throw EMPTY_LIST;
	}
	else if (m_head->getData().getName() == name)
	{
		Node* trail = m_head;
		m_head = m_head->getNext();
		delete trail;
		--m_counter;
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
		--m_counter;
	}
}

/**********************************************************************
* Purpose: This function returns the information of the item at the front
*			of the List
*
* Precondition:	Need a List.
*
* Postcondition: Front item returned.
*
************************************************************************/

Potion List::Front()
{
	return m_head->getData();
}

/**********************************************************************
* Purpose: This function returns the information of the item at the back
*			of the List
*
* Precondition:	Need a List.
*
* Postcondition: Back item returned.
*
************************************************************************/

Potion List::Back()
{
	Node* travel = m_head;

	while (travel->getNext() != nullptr)
	{
		travel = travel->getNext();
	}
	return travel->getData();
}

/**********************************************************************
* Purpose: This function returns the information of the item at the front
*			of the List and then deletes the node
*
* Precondition:	Need a List.
*
* Postcondition: Front item returned and then the Node is deleted.
*
************************************************************************/

Potion List::PopFront()
{
	if (m_head != nullptr)
	{
		Node* temp = m_head;
		m_head = m_head->getNext();
		--m_counter;
		return temp->getData();
	}
	else
	{
		throw EMPTY_LIST;
	}
}

/**********************************************************************
* Purpose: This function returns the information of the item at the back
*			of the List and then deletes the node
*
* Precondition:	Need a List.
*
* Postcondition: Back item returned and then the Node is deleted.
*
************************************************************************/

Potion List::PopBack()
{
	if (m_head != nullptr)
	{
		Node* travel = m_head;

		while (travel->getNext() != nullptr)
		{
			travel = travel->getNext();
		}
		Potion temp = travel->getData();
		DeleteNode(travel->getData().getName());
		m_counter--;
		return temp;
	}
	else
	{
		throw EMPTY_LIST;
	}
}

/**********************************************************************
* Purpose: This function returns the information of the item at a specific
*			location of the List.
*
* Precondition:	Need a List.
*
* Postcondition: Item returned.
*
************************************************************************/

Potion List::GetIthElement(int element)
{
	Node* travel = m_head;
	for (int i = 0; i < element; ++i)
	{
		travel = travel->getNext();
	}

	return travel->getData();
}

/**********************************************************************
* Purpose: This function saves the list to a binary file
*
* Precondition:	Need a List.
*
* Postcondition: Binary file created with information of List.
*
************************************************************************/

void List::Save(ofstream& fout)
{
	Node* travel = m_head;

	fout.write(reinterpret_cast<char*>(&m_counter), sizeof(m_counter));

	while (travel != nullptr)
	{
		travel->Save(fout);
		travel = travel->getNext();
	}
}

/**********************************************************************
* Purpose: This function loads the list from a binary file
*
* Precondition:	Need a List.
*
* Postcondition: List created with information of binary file.
*
************************************************************************/

void List::Load(ifstream& fout)
{
	Potion temp;
	int counter = 0;

	fout.read(reinterpret_cast<char*> (&counter), sizeof(counter));
	
	for (int i = 0; i < counter; i++)
	{
		temp.Load(fout);
		PushBack(temp);
	}
}
