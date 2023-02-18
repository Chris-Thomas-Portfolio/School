#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "Node.h"
#include "String.h"

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
template <class T>
class List
{
public:
	List();
	List(const List<T>& copy);
	List<T>& operator = (const List<T>& rhs);
	~List();
	void PushFront(T data);
	void PushBack(T data);
	void InsertOrdered(T data);
	void Purge();
	void Display() const;
	void DeleteNode(String name);
	T Front();
	T Back();
	T PopFront();
	T PopBack();
	T GetIthElement(int element);
	void Save(ofstream& fout);
	void Load(ifstream& fout);
	int getCount();
private:
	Node<T>* m_head;

	int m_counter;
};

/**********************************************************************
* Purpose: This is the default constructor for the List class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default List.
*
************************************************************************/

template<class T>
inline List<T>::List() : m_head(nullptr), m_counter(0)
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the List class
*
* Precondition:	Need a List.
*
* Postcondition: Creates a copy of the List.
*
************************************************************************/

template<class T>
inline List<T>::List(const List<T> & copy) : m_head(nullptr)
{
	if (copy.m_head != nullptr)
	{
		Node<T>* travel = copy.m_head;

		while (travel != nullptr)
		{
			PushBack(travel->m_data);
			travel = travel->m_next;
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
template<class T>
List<T>& List<T>::operator =(const List<T>& rhs)
{
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Purge the LHS
		Purge();

		// 3. Deep copy
		if (rhs.m_head != nullptr)
		{
			Node<T>* travel = rhs.m_head;

			while (travel != nullptr)
			{
				PushBack(travel->m_data);
				travel = travel->m_next;
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

template<class T>
inline List<T>::~List()
{ 
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

template<class T>
inline void List<T>::PushFront(T data)
{
	Node<T>* nn = new Node<T>(data);

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

template<class T>
inline void List<T>::PushBack(T data)
{
	Node<T>* nn = new Node<T>(data);

	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else
	{
		Node<T>* travel = m_head;

		while (travel->m_next != nullptr)
		{
			travel = travel->m_next;
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

template<class T>
inline void List<T>::InsertOrdered(T data)
{
	Node<T>* nn = new Node<T>(data);

	if ((m_head == nullptr) || (nn->m_data.getName() <= m_head->m_data.getName()))
	{
		nn->setNext(m_head);
		m_head = nn;
	}
	else
	{
		Node<T>* travel = m_head;
		Node<T>* trail = nullptr;

		while ((travel != nullptr) && (travel->m_data.getName() <= nn->m_data.getName()))
		{
			trail = travel;
			travel = travel->m_next;
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

template<class T>
inline void List<T>::Purge()
{
	Node<T>* trail = nullptr;

	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	m_counter = 0;
}

/**********************************************************************
* Purpose: This function displays all the information in the List to the user
*
* Precondition:	Need a List.
*
* Postcondition: The entire list is displayed.
*
************************************************************************/

template<class T>
inline void List<T>::Display() const
{
	if (m_head == nullptr)
	{
		throw EMPTY_LIST;
	}
	else
	{
		Node<T>* travel = m_head;

		while (travel != nullptr)
		{
			travel->m_data.Display();
			travel = travel->m_next;
		}
		cout << endl;
	}
}

/**********************************************************************
* Purpose: This function deletes a specific Node from the List
*
* Precondition:	Need a List.
*
* Postcondition: Deletes specified Node from the List.
*
************************************************************************/

template<class T>
inline void List<T>::DeleteNode(String name)
{
	if (m_head == nullptr)
	{
		throw EMPTY_LIST;
	}
	else if (m_head->m_data.getName() == name)
	{
		Node<T>* trail = m_head;
		m_head = m_head->m_next;
		delete trail;
		--m_counter;
	}
	else
	{
		Node<T>* travel = m_head;
		Node<T>* trail = nullptr;

		while (travel != nullptr && travel->m_data.getName() != name)
		{
			trail = travel;
			travel = travel->m_next;
		}

		if (travel == nullptr)
		{
			cout << name << " not found in the list." << endl;
		}
		else
		{
			trail->m_next = (travel->m_next);
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

template<class T>
inline T List<T>::Front()
{
	return m_head->m_data;
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

template<class T>
inline T List<T>::Back()
{
	Node<T>* travel = m_head;

	while (travel->m_next != nullptr)
	{
		travel = travel->m_next;
	}
	return travel->m_data;
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

template<class T>
inline T List<T>::PopFront()
{
	if (m_head != nullptr)
	{
		Node<T>* temp = m_head;
		m_head = m_head->m_next;
		--m_counter;
		return temp->m_data;
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

template<class T>
inline T List<T>::PopBack()
{
	if (m_head != nullptr)
	{
		Node* travel = m_head;

		while (travel->m_next != nullptr)
		{
			travel = travel->m_next;
		}
		T temp = travel->m_data;
		DeleteNode(travel->m_data.getName());
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

template<class T>
inline T List<T>::GetIthElement(int element)
{
	Node<T>* travel = m_head;
	for (int i = 0; i < element; ++i)
	{
		travel = travel->m_next;
	}

	return travel->m_data;
}

/**********************************************************************
* Purpose: This function saves the list to a binary file
*
* Precondition:	Need a List.
*
* Postcondition: Binary file created with information of List.
*
************************************************************************/

template<class T>
inline void List<T>::Save(ofstream& fout)
{
	Node<T>* travel = m_head;

	fout.write(reinterpret_cast<char*>(&m_counter), sizeof(m_counter));

	while (travel != nullptr)
	{
		travel->Save(fout);
		travel = travel->m_next;
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

template<class T>
inline void List<T>::Load(ifstream& fout)
{
	T temp;
	int counter = 0;
	Purge();
	fout.read(reinterpret_cast<char*> (&counter), sizeof(counter));

	for (int i = 0; i < counter; i++)
	{
		temp.Load(fout);
		PushBack(temp);
	}
}

/**********************************************************************
* Purpose: This function returns the value of m_counter
*
* Precondition:	Need a List.
*
* Postcondition: Returns an int that has the value of m_counter.
*
************************************************************************/

template<class T>
inline int List<T>::getCount()
{
	return m_counter;
}