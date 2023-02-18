#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
/************************************************************************
* Class: Node
*
* Purpose: This class is designed to contain the information of another class
*			and be added to a List.
*
* Manager functions:
* 	Node ()
* 		The default constructor for the Node.
*	Node (const Node& copy)
*		Creates a copy of a Node.
*	Node operator =(const Node& rhs)
*	~Node()
*		Destructor for Node
* Methods:
*	Node<T>* getNext()
*		Returns the m_next data member
*	void setNext(Node* next)
*		Set m_next to variable.
*	T getData()
*		Returns item that is being held in the Node
*	void setData(T data)
*		Set m_data to the variable.
*	Node<T>* getPrevious()
*		Returns the m_previous data member
*	void setPrevious(Node* previous)
*		Set m_previous to variable.
*************************************************************************/
template <class T>
class List;
template <class T>
class Node
{
	friend class List<T>;
public:
	
private:
	Node();
	Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr);
	Node(const Node<T>& copy);
	T& operator = (const Node<T>& rhs);
	~Node();
	Node<T>* getNext();
	void setNext(Node<T>* next);
	T getData() const;
	void setData(T data);
	Node<T>* getPrevious();
	void setPrevious(Node<T>* previous);

	T m_data;
	Node<T>* m_next;
	Node<T>* m_previous;
};

/**********************************************************************
* Purpose: This is the default constructor for the Node class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default List.
*
************************************************************************/

template<class T>
inline Node<T>::Node() : m_data(), m_next(nullptr), m_previous(nullptr)
{ }

/**********************************************************************
* Purpose: This is the one arg constructor for the Node class
*
* Precondition:	N/A.
*
* Postcondition: Creates a Node with containing the arg.
*
************************************************************************/

template<class T>
inline Node<T>::Node(T data, Node<T>* next, Node<T>* previous) : m_data(data), m_next(next), m_previous(previous)
{
	
}

/**********************************************************************
* Purpose: This is the copy constructor for the Node class
*
* Precondition:	Need a Node.
*
* Postcondition: Creates a copy of the Node.
*
************************************************************************/


template<class T>
inline Node<T>::Node(const Node<T>& copy) : m_data(copy.m_data), m_next(copy.m_next), m_previous(copy.m_previous)
{ }

/**********************************************************************
* Purpose: This is the operator equals for the Node class
*
* Precondition:	Need a Node.
*
* Postcondition: Sets the Node equal to the Node on the rhs.
*
************************************************************************/

template<class T>
inline T& Node<T>::operator=(const Node<T>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
		m_previous = rhs.m_previous;
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

template<class T>
inline Node<T>::~Node()
{
	m_next = nullptr;
	m_previous = nullptr;
	delete m_next;
	delete m_previous;
}

/**********************************************************************
* Purpose: This function returns the data member m_next
*
* Precondition:	Need a Node.
*
* Postcondition: Return the data member m_next.
*
************************************************************************/

template<class T>
inline Node<T>* Node<T>::getNext()
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

template<class T>
inline void Node<T>::setNext(Node<T>* next)
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

template<class T>
inline T Node<T>::getData() const
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

template<class T>
inline void Node<T>::setData(T data)
{
	m_data = data;
}

/**********************************************************************
* Purpose: This function returns the data member m_previous
*
* Precondition:	Need a Node.
*
* Postcondition: Return the data member m_previous.
*
************************************************************************/

template<class T>
inline Node<T>* Node<T>::getPrevious()
{
	return m_previous;
}

/**********************************************************************
* Purpose: This function sets the data member m_previous
*
* Precondition:	Need a Node.
*
* Postcondition: Set the data member m_previous.
*
************************************************************************/

template<class T>
inline void Node<T>::setPrevious(Node<T>* previous)
{
	m_previous = previous;
}
