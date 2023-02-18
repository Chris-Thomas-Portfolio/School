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
*	Node(Potion data)
*		The one arg constructor for the Node.
*	Node (const Node& copy)
*		Creates a copy of a Node.
*	Node operator =(const Node& rhs)
*	~Node()
*		Destructor for Node
* Methods:
*	Node* getNext()
*		Returns the m_next data member
*	void setNext(Node* next)
*		Set m_next to variable.
*	Potion getData()
*		Returns item that is being held in the Node
*	void setData(Potion data)
*		Set m_data to the variable.
*	void Save(ofstream& fout)
*		Save the Node to a binary file.
*	void Load(ifstream& fout)
*		Load the Node to a binary file.
*************************************************************************/
template <class T>
class List;
template <class T>
class Node
{
	friend class List<T>;
public:
	static int count;
private:
	Node();
	Node(T data, Node<T>* next = nullptr);
	Node(const Node<T>& copy);
	T& operator = (const Node<T>& rhs);
	~Node();
	Node<T>* getNext();
	void setNext(Node<T>* next);
	T getData() const;
	void setData(T data);
	void Save(ofstream& fout);
	void Load(ifstream& fout);

	T m_data;
	Node<T>* m_next;
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
inline Node<T>::Node() : m_data(), m_next(nullptr)
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
inline Node<T>::Node(T data, Node<T>* next) : m_data(data), m_next(next)
{
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


template<class T>
inline Node<T>::Node(const Node<T>& copy) : m_data(copy.m_data), m_next(copy.m_next)
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
* Purpose: This function saves the Node to a binary file
*
* Precondition:	Need a Node.
*
* Postcondition: Binary file created with information of Node.
*
************************************************************************/

template<class T>
inline void Node<T>::Save(ofstream& fout)
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

template<class T>
inline void Node<T>::Load(ifstream& fout)
{
	m_data.Load(fout);
}