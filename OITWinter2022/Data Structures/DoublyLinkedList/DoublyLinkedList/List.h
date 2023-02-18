#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "Node.h"
#include "Exception.h"

/*************************************************************
* Author: Chris Thomas
* Filename: List.h
* Date Created: 1/8/2022 6:41 PM
* Modifications: N/A
**************************************************************/

/*************************************************************
*
* Lab/Assignment: Lab 2 - Doubly Linked List
*
* Overview:
* This class is designed to contain the Node class and handle the organization,
* addition, and deletion of Nodes. The list will be able to be traversed both forwards and backwards.
*
* Input:
* Inputs are all provided by Todd to test the list.
*
* Output:
* The output of this program will be a series of statements on whether or not
* the specific passed or failed. I also added some output for specific exceptions when
* an exception was thrown.
*
************************************************************/
/************************************************************************
* Class: List
*
* Purpose: This class is designed to contain the Node class and handle the organization,
*			addition, and deletion of Nodes.
*
* Manager functions:
* 	List ()
* 		The default constructor for the List.
*	List (const List<T>& copy)
*		Creates a copy of a List.
*	List (List<T>&& copy)
*	List operator =(const List<T>& rhs)
*	List operator =(List<T>&& rhs)
*	~List()
*		Destructor for List
* Methods:
*	void Append(T data);
*		Adds new node to back of List.
*	void Extract(T data);
*		Removes specific Node from List.
*	T& First() const;
*		Returns a reference to the first Node in List
*	Node<T>* getHead();
*		Returns a pointer to the head Node.
*	Node<T>* getTail();
*		Returns a pointer to the tail node.
*	void InsertAfter(T data, T original);
*		Inserts Node after specified Node in List.
*	void InsertBefore(T data, T original);
*		Inserts Node before specified Node in List.
*	bool isEmpty();
*		Returns true if List is empty.
*	T& Last() const;
*		Returns a reference to the last Node in List.
*	void Prepend(T data);
*		Adds a Node to the front of the List.
*	void Purge();
*		Removes all Nodes from the List.
*	void PrintBackwards() const;
*		Displays all the Nodes data in reverse order.
*	void PrintForwards() const;
*		Displays all the Nodes data.
*************************************************************************/
template <class T>
class List
{
public:
	List();
	List(const List<T>& copy);
	List(List<T>&& copy) noexcept;
	List<T>& operator = (const List<T>& rhs);
	List<T>& operator = (List<T>&& rhs) noexcept;
	~List();
	void Append(T data);
	void Extract(T data);
	T& First() const;
	Node<T>* getHead();
	Node<T>* getTail();
	void InsertAfter(T data, T original);
	void InsertBefore(T data, T original);
	bool isEmpty();
	T& Last() const;
	void Prepend(T data);
	void Purge();
	void PrintBackwards() const;
	void PrintForwards() const;
private:
	Node<T>* m_head;
	Node<T>* m_tail;
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
inline List<T>::List() : m_head(nullptr), m_tail(nullptr)
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
inline List<T>::List(const List<T>& copy) : m_head(nullptr), m_tail(nullptr)
{
	if (copy.m_head != nullptr)
	{
		Node<T>* travel = copy.m_head;

		while (travel != nullptr)
		{
			Append(travel->m_data);
			travel = travel->m_next;
		}
	}
}

template<class T>
inline List<T>::List(List<T>&& copy) noexcept
{
	if (copy.m_head != nullptr)
	{
		m_head = copy.m_head;
		m_tail = m_tail;
		copy.m_head = nullptr;
		copy.m_tail = nullptr;
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
				Append(travel->m_data);
				travel = travel->m_next;
			}
		}
	}
	// 4. Return reference to class
	return *this;
}

template<class T>
inline List<T>& List<T>::operator=(List<T>&& rhs) noexcept
{
	if (this != &rhs)
	{
		Purge();					//clear lhs List
		if (rhs.m_head != nullptr)	//copy rhs List and then clear rhs
		{
			m_head = rhs.m_head;
			m_tail = rhs.m_tail;
			rhs.m_head = nullptr;
			rhs.m_tail = nullptr;
		}
	}
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
	Purge();			//clear List
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
inline void List<T>::Append(T data)
{
	Node<T>* nn = new Node<T>(data);

	if (m_head == nullptr)			//check for empty List
	{
		nn->setPrevious(nullptr);	//set new nodes previous to nullptr
		nn->setNext(nullptr);		//set new nodes next to nullptr
		m_head = nn;				//set m_head and m_tail to new node since its the only node in List.
		m_tail = nn;
	}
	else
	{
		nn->setPrevious(m_tail);	//set new nodes previous to tail of list
		nn->setNext(nullptr);		//set new nodes next to nullptr since it is the end of the list.
		m_tail->setNext(nn);		//set old tails next to new node.
		m_tail = nn;				//set m_tail to new node since it is the new tail.
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
inline void List<T>::Extract(T data)
{
	if (m_head == nullptr)						//check for exmpty list and throw exception if list is empty
		throw Exception("List empty cannot extract");

	if (m_head->getData() == data)			//check to see if head node is the node we are looking for
	{
		Node<T>* temp = m_head;
		m_head = temp->getNext();
		delete temp;
		if (m_head != nullptr)					//if m_head is not nullptr set its previous to null pointer
			m_head->setPrevious(nullptr);
		if (m_head == nullptr)					//if m_head is nullptr set tail to nullptr since list is now empty.
			m_tail = nullptr;
	}
	else if (m_tail->getData() == data)			//check to see if tail is the node we are looking for
	{
		Node<T>* temp = m_tail;
		m_tail = temp->getPrevious();			//if it is set the tail to the node before current tail.
		delete temp;
		if (m_tail != nullptr)					//if list is not empty set tails next to nullptr.
			m_tail->setNext(nullptr);
	}
	else
	{
		Node<T>* travel = m_head;									//create a travel and trail to traverse list
		Node<T>* trail = nullptr;

		while (travel != nullptr && travel->getData() != data)		//move from node to node looking for specified data
		{
			trail = travel;
			travel = travel->m_next;
		}
		if (travel == nullptr)										//if you reach the end of list data not found throw exception.
		{
			throw Exception("Data was not found in List");
		}
		else
		{
			trail->m_next->setNext(travel->m_next);					//once data found set trails next to travels next
			travel->m_next->setPrevious(trail);						//set travels nexts previous to trail.
		}
		delete travel;
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
inline T& List<T>::First() const
{
	if (m_head == nullptr)										//if list is empty throw exception
		throw Exception("List empty there is no first node");
	return m_head->m_data;										//return data at head.
}

/**********************************************************************
* Purpose: This function returns pointer to the head node.
*
* Precondition:	Need a List.
*
* Postcondition: Returns a pointer to the head node.
*
************************************************************************/

template<class T>
inline Node<T>* List<T>::getHead()
{
	return m_head;
}

/**********************************************************************
* Purpose: This function returns pointer to the tail node.
*
* Precondition:	Need a List.
*
* Postcondition: Returns a pointer to the tail node.
*
************************************************************************/

template<class T>
inline Node<T>* List<T>::getTail()
{
	return m_tail;
}

/**********************************************************************
* Purpose: This function inserts a new node after the specified node in
*			the List.
*
* Precondition:	Need a List.
*
* Postcondition: Node is added to List after specified node.
*
************************************************************************/

template<class T>
inline void List<T>::InsertAfter(T data, T original)
{
	if (m_head == nullptr)								//if list is empty throw exception
		throw Exception("Empty List");

	if (original == m_head->getData())				//check if head is node we are looking for
	{
		Node<T>* nn = new Node<T>(data);				//create new node with new data
		nn->setPrevious(m_head);						//set new nodes previous to m_head
		if (m_tail == m_head)							//check if new node will be new tail
		{
			m_tail = nn;								//set m_tail to new node
			nn->setNext(nullptr);						//set new node next to nullptr
			m_head->setNext(nn);						//set m_heads next to new node
		}
		else
		{
			nn->setNext(m_head->getNext());				//set new nodes next to heads old next
			m_head->setNext(nn);						//set heads next to new node
			nn->getNext()->setPrevious(nn);				//set new nodes nexts previous to nn
		}
	}
	else if (original == m_tail->getData())				//check to see if tail is node we are looking for
	{
		Node<T>* nn = new Node<T>(data);				//create new node with new data
		nn->setPrevious(m_tail);						//set new nodes previous to old tail
		nn->setNext(nullptr);							//set new nodes next to nullptr
		m_tail->setNext(nn);							//set old tails next to new node
		m_tail = nn;									//set tail to new node
	}
	else
	{
		Node<T>* travel = m_head;
		Node<T>* trail = nullptr;

		while ((travel != nullptr) && (travel->getData() != original))	//traverse list until we find specified node
		{
			trail = travel;
			travel = travel->m_next;
		}
		if (travel == nullptr)
			throw Exception("Data not found in List");					//if not found in list throw exception
		Node<T>* nn = new Node<T>(data);								//create new node with new data
		nn->setPrevious(travel);										//set new nodes previous to travel
		nn->setNext(travel->m_next);									//set new nodes next to travels next
		travel->setNext(nn);											//set travels next to new node
		delete travel;													//delete travel.
		delete trail;													//delete trail.
	}
}

/**********************************************************************
* Purpose: This function inserts a new node before the specified node in
*			the List.
*
* Precondition:	Need a List.
*
* Postcondition: Node is added to List before specified node.
*
************************************************************************/

template<class T>
inline void List<T>::InsertBefore(T data, T original)
{
	if (m_head == nullptr)							//if list is empty throw exception
		throw Exception("Empty List");


	if (original == m_head->getData())			//check to see if head is node we need
	{
		Node<T>* nn = new Node<T>(data);				//create new node with new data
		nn->setNext(m_head);						//set new nodes next to head
		nn->setPrevious(nullptr);					//set new nodes previous to nullptr
		m_head->setPrevious(nn);					//set old heads previous to new node
		m_head = nn;								//set m_head to new node
	}
	else if (original == m_tail->getData())			//check if tail is node we need
	{
		Node<T>* nn = new Node<T>(data);				//create new node with new data
		nn->setNext(m_tail);						//set new nodes next to tail
		nn->setPrevious(m_tail->getPrevious());		//set new nodes previous to tails previous
		m_tail->getPrevious()->setNext(nn);			//set tails previous next to new node
		m_tail->setPrevious(nn);					//set tails previous to new node					
	}
	else
	{
		Node<T>* travel = m_head;										//create travel to traverse list
		Node<T>* trail = nullptr;

		while ((travel != nullptr) && (travel->getData() != original))	//traverse list while data is not found
		{
			trail = travel;
			travel = travel->m_next;
		}
		if (travel == nullptr)											//if data is not found throw exception
			throw Exception("Data not found in List");
		Node<T>* nn = new Node<T>(data);				//create new node with new data
		nn->setPrevious(trail);											//set new nodes previous to trail
		trail->setNext(nn);												//set trails next to new node
		nn->setNext(travel);											//set new nodes next to travel
		delete travel;													//delete travel.
		trail = nullptr;
		delete trail;													//delete trail.
	}
}

/**********************************************************************
* Purpose: This function checks to see if a List is empty and returns
*			a bool.
*
* Precondition:	Need a List.
*
* Postcondition: Returns a bool for true if List is empty and false if not.
*
************************************************************************/

template<class T>
inline bool List<T>::isEmpty()
{
	if (m_head == nullptr)				//if list is empty return true else return false
		return true;
	return false;
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
inline T& List<T>::Last() const
{
	if (m_head == nullptr)
		throw Exception("Empty List");
	return m_tail->m_data;
}
/**********************************************************************
* Purpose: This function adds a new Node to the List and puts it at the front.
*
* Precondition:	Need a List.
*
* Postcondition: New node is at front of List.
*
************************************************************************/

template<class T>
inline void List<T>::Prepend(T data)
{
	Node<T>* nn = new Node<T>(data);			//create new node with data

	nn->setNext(m_head);						//set new nodes next to old head
	nn->setPrevious(nullptr);					//set new nodes previous to nullptr
	if (m_head != nullptr)						
	{
		m_head->setPrevious(nn);				//set old heads previous to new node
	}
	if (m_tail == nullptr)
	{
		m_tail = nn;							//if tail is nullptr make new node tail as well
	}
	
	m_head = nn;								//set new node as head
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
	Node<T>* trail = nullptr;			//create node to traverse list

	while (m_head != nullptr)			//while m_head is not nullptr traverse the list and delete all nodes
	{
		trail = m_head;
		m_head = m_head->m_next;
		m_tail = nullptr;
		delete trail;
	}
}

/**********************************************************************
* Purpose: This function displays all the information in the List to the user
*			in reverse order
*
* Precondition:	Need a List.
*
* Postcondition: The entire list is displayed in reverse order.
*
************************************************************************/

template<class T>
inline void List<T>::PrintBackwards() const
{
	if (m_head == nullptr)						//if list is empty throw exception
	{
		throw Exception("Empty List");
	}
	else
	{
		Node<T>* travel = m_tail;				//create node to traverse the list

		while (travel != nullptr)
		{
			cout << travel->getData() << endl;	//traverse the list and cout the data of each node in reverse order
			travel = travel->m_previous;
		}
		cout << endl;
		delete travel;
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

template<class T>
inline void List<T>::PrintForwards() const
{
	if (m_head == nullptr)						//if list is empty throw exception
	{
		throw Exception("Empty List");
	}
	else
	{
		Node<T>* travel = m_head;				//create node to traverse the list

		while (travel != nullptr)
		{
			cout << travel->getData() << endl;	//traverse the list and cout the data of each node in reverse order
			travel = travel->m_next;
		}
		cout << endl;
		delete travel;
	}
}