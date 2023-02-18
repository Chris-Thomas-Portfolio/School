/************************************************************************
* Author: Chris Thomas
* Filename: CircularQueue.h
* Date Created: 1/23/2022 10:00 AM
* Modifications: N/A
*************************************************************************/
/************************************************************************
*
* Lab/Assignment: Lab 7 Array based Circular Queue
*
* Overview: This class creates a Circular Queue class based off a one
*			dimensional array.
*
*
* Input: Inputs all come from the consumer.
*
*
* Output: No specific outputs as we are creating a stack for data storage.
*
*
*************************************************************************/
/************************************************************************
* Class: CircularQueue
*
* Purpose: This class creates a circular queue using a one dimensional array as
*			a base.
*
* Manager functions:
*	CircularQueue();
*		Creates a default CircularQueue.
*	CircularQueue(int size);
*		Creates a CircularQueue of given size.
*	CircularQueue(CircularQueue<T>& copy);
*		Creates a copy of given CircularQueue.
*	CircularQueue& operator = (CircularQueue<T>& rhs);
*		Creates a copy of the CircularQueue on the rhs.
* Methods:
*	int getSize() const;
*		Returns the value of m_size.
*	void Enqueue(T data);
*		Adds data to the queue.
*	T Dequeue();
*		Returns and removes data from the front of the queue.
*	T Peek() const;
*		Return data at front of queue.
*	bool isEmpty() const;
*		Return true if queue is empty.
*************************************************************************/
#pragma once
#include "Array.h"

template <typename T>

class CircularQueue
{
public:
	CircularQueue();
	CircularQueue(int size);
	CircularQueue(CircularQueue<T>& copy);
	CircularQueue& operator = (CircularQueue<T>& rhs);
	int getSize() const;
	void Enqueue(T data);
	T Dequeue();
	T Peek() const;
	bool isEmpty() const;
	bool isFull() const;
private:
	Array<T> m_queue;
	int m_size;
	int m_head;
	int m_tail;
};

/**********************************************************************
* Purpose: C'tor.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default CircularQueue.
*
************************************************************************/

template<typename T>
inline CircularQueue<T>::CircularQueue() : m_size(0), m_head(-1), m_tail(-1)
{ }

/**********************************************************************
* Purpose: 1 arg Constructor.
*
* Precondition:	N/A.
*
* Postcondition: Creates a CirularQueue object with given size.
*
************************************************************************/

template<typename T>
inline CircularQueue<T>::CircularQueue(int size) : m_queue(size), m_size(size), m_head(-1), m_tail(-1)
{ }

/**********************************************************************
* Purpose: Copy Constructor.
*
* Precondition:	Need a CircularQueue object.
*
* Postcondition: Creates a copy of a CirularQueue object.
*
************************************************************************/

template<typename T>
inline CircularQueue<T>::CircularQueue(CircularQueue<T>&copy) : m_queue(copy.m_queue), m_size(copy.m_size), m_head(copy.m_head), m_tail(copy.m_tail)
{ }

/**********************************************************************
* Purpose: Op =.
*
* Precondition:	Need a CircularQueue object.
*
* Postcondition: Creates a copy of a CirularQueue object on the rhs.
*
************************************************************************/

template<typename T>
inline CircularQueue<T>& CircularQueue<T>::operator=(CircularQueue<T>&rhs)
{
	if (*this != &rhs)					//check for self assignment
	{
		m_queue = rhs.m_queue;			//copy over values
		m_size = rhs.m_size;
		m_head = rhs.m_head;
		m_tail = rhs.m_tail;
	}
	return *this;
}

/**********************************************************************
* Purpose: Return m_size.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Returns the value of m_size.
*
************************************************************************/

template<typename T>
inline int CircularQueue<T>::getSize() const
{
	return m_size;				//return m_size
}

/**********************************************************************
* Purpose: Add a piece of data to the CircularQueue.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Add data to a free spot of the CircularQueue.
*
************************************************************************/

template<typename T>
inline void CircularQueue<T>::Enqueue(T data)
{		//if m_head = 0 and m_tail = m_size -1 or m_tail is right behind m_head the queue is full throw exception
	if ((m_head == 0 && m_tail == m_size - 1) || (m_tail == (m_head - 1) ))
		throw Exception("Queue is full");
	else if (m_head == -1)							//if its the first element in the queue set m_head and m_tail to 0
	{												
		m_head = 0;
		m_tail = 0;
		m_queue[m_tail] = data;						//put the data in first spot of queue
	}
	else if (m_tail == m_size - 1 && m_head != 0)	//check if m_tail is at the end and there is open space at the front
	{
		m_tail = 0;									//set m_tail to open spot in queue
		m_queue[m_tail] = data;						//put data there
	}
	else
	{
		m_tail++;									//increment m_tail
		m_queue[m_tail] = data;						//put data in next spot in queue
	}
}

/**********************************************************************
* Purpose: Remove a piece of data from the CircularQueue.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Remove data from the front of the CircularQueue.
*
************************************************************************/

template<typename T>
inline T CircularQueue<T>::Dequeue()
{
	if (m_head == -1)						//if m_head is -1 queue is empty throw exception
	{
		throw Exception("Queue is empty");
	}

	T data = m_queue[m_head];				//create new data to hold data at front of queue					
	if (m_head == m_tail)					//if at last element of queue set both m_head and m_tail back to -1
	{
		m_head = -1;
		m_tail = -1;
	}
	else if (m_head == m_size - 1)			//check if m_head is at the end of queue if it is set back to beginning
	{
		m_head = 0;
	}
	else
	{
		m_head++;							//else increment m_head to next spot
	}

	return data;							//return data from front of CircularQueue
}

/**********************************************************************
* Purpose: Get the data at the front of the queue with removing it from the queue.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Return data at the front of queue.
*
************************************************************************/

template<typename T>
inline T CircularQueue<T>::Peek() const
{
	if (m_head == -1)						//check for empty queue if empty throw exception
		throw Exception("Queue is empty");
	return m_queue[m_head];					//else return data
}

/**********************************************************************
* Purpose: Check if queue is empty.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Return true if queue is empty and false if not.
*
************************************************************************/

template<typename T>
inline bool CircularQueue<T>::isEmpty() const
{
	if (m_head == -1)				//if m_head == -1 queue is empty return true
	{
		return true;
	}
	else
	{
		return false;				//if not empty return false
	}
}

/**********************************************************************
* Purpose: Check if queue is full.
*
* Precondition:	Need a CircualrQueue object.
*
* Postcondition: Return true if queue is full and false if not.
*
************************************************************************/

template<typename T>
inline bool CircularQueue<T>::isFull() const
{
	if ((m_head == 0 && m_tail == m_size - 1) || (m_tail == (m_head - 1)))	//check if queue is full
	{
		return true;														//if it is return true
	}
	else
	{
		return false;														//if not return false
	}
}
