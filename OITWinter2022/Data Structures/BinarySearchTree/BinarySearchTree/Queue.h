/*************************************************************
* Author: Chris Thomas
* Filename: Queue.h
* Date Created: 1/22/2022 1:04 PM
* Modifications: N/A
**************************************************************/
/************************************************************************
* Class: Queue
*
* Purpose: This class is creates a Queue of data to be accessed on a first in
*			first out basis.
*
* Manager functions:
* 	Queue();
*	Queue(const Queue& copy);
*	~Queue();
*	Queue<T>& operator = (const Queue<T>& rhs)
* Methods:
*	void Enqueue(T data);
*	T Dequeue();
*	T Peek() const;
*	int getSize() const;
*	bool isEmpty() const;
*************************************************************************/
#pragma once
#include "List.h"

template <typename T>

class Queue
{
public:
	Queue();
	Queue(const Queue& copy);
	~Queue();
	Queue<T>& operator = (const Queue<T>& rhs);
	void Enqueue(T data);
	T Dequeue();
	T Peek() const;
	int getSize() const;
	bool isEmpty() const;
private:
	List<T> m_queue;
	int m_size;
};

/**********************************************************************
* Purpose: C'tor.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Queue.
*
************************************************************************/
template<typename T>
inline Queue<T>::Queue() : m_size(0)
{ }

/**********************************************************************
* Purpose: Copy Constructor.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Creates a copy of a Queue object.
*
************************************************************************/

template<typename T>
inline Queue<T>::Queue(const Queue& copy) : m_queue(copy.m_queue), m_size(copy.m_size)
{ }

/**********************************************************************
* Purpose: D'tor.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Gets rid of a Queue object.
*
************************************************************************/

template<typename T>
inline Queue<T>::~Queue()
{
	m_size = 0;
}

/**********************************************************************
* Purpose: Operator =.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Sets lhs Queue object to the same values of the rhs Queue object.
*
************************************************************************/

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& rhs)
{
	if (this != &rhs)						//check for self assignment
	{
		m_queue = rhs.m_queue;				//set lhs to rhs values
		m_size = rhs.m_size;
	}
	return *this;
}

/**********************************************************************
* Purpose: Adds data onto Queue.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Adds new data to back of Queue.
*
************************************************************************/

template<typename T>
inline void Queue<T>::Enqueue(T data)
{
	m_queue.Append(data);				//put new node with new data at back of List
	m_size++;							//increment m_size
}

/**********************************************************************
* Purpose: Remove data from the Queue.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Removes data from the front of the Queue.
*
************************************************************************/

template<typename T>
inline T Queue<T>::Dequeue()
{
	if (m_size == 0)										//if Queue is empty cannot Dequeue throw exception
	{
		throw Exception("Cannot Dequeue from empty Queue");
	}
	T data = m_queue.First();								//create a new T with the information at front of Queue
	m_queue.Extract(m_queue.First());						//delete the front of the Queue
	m_size--;												//decrease the number of m_size in Queue
	return data;											//return the copy of the desired data
}

/**********************************************************************
* Purpose: Show current data at front of Queue.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Returns data from the front of the Queue.
*
************************************************************************/

template<typename T>
inline T Queue<T>::Peek() const
{
	if (m_size == 0)							//make sure Queue is not empty if it is throw exception
		throw Exception("Queue empty");
	return m_queue.First();						//return the information of the item at front of the Queue
}

/**********************************************************************
* Purpose: Show the size of Queue currently.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Returns m_size.
*
************************************************************************/

template<typename T>
inline int Queue<T>::getSize() const
{
	return m_size;						//return the size
}

/**********************************************************************
* Purpose: Return true if Queue is empty.
*
* Precondition:	Need a Queue object.
*
* Postcondition: Returns true if the Queue is empty false if not.
*
************************************************************************/

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	if (m_size == 0)				//if m_size is 0 the Queue is empty and return true
	{
		return true;
	}
	else
	{
		return false;				//if not return false
	}
}

