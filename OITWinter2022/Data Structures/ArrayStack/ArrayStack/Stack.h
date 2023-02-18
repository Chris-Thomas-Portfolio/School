/*************************************************************
* Author: Chris Thomas
* Filename: Stack.h
* Date Created: 1/19/2022 9:35 AM
* Modifications: N/A
**************************************************************/
/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be
* started at any base.
*
* Manager functions:
*	Stack()
*		Default c'tor for stack class.
*	Stack(int size);
*		1 arg constructor for stack class.
*	~Stack();
*		Destructor for stack class.
*	Stack(const Stack<T>& copy);
*		Stack class coy constructor.
* 	Stack& operator = (const Stack& rhs);
*		Op = for stack class
* Methods:
* 	void Push(T data);
*		Add data onto stack.
*	T Pop();
*		Remove data from stack.
*	T Peek() const;
*		Return what is currently at top of stack.
*	int getNumElements();
*		Return m_top.
*	int getSize() const;
*		Return m_size.
*	void setSize(int new_size);
*		Sets the size of the stack to new value.
*	bool isEmpty() const;
*		Checks to see if the stack is empty and returns true or false.
*	bool isFull() const;
*		Checks to see if the stack is full and returns true or false.
*************************************************************************/
#pragma once
#include "Array.h"

template <typename T>

class Stack
{
public:
	Stack();
	Stack(int size);
	~Stack();
	Stack(const Stack<T>& copy);
	Stack& operator = (const Stack& rhs);
	void Push(T data);
	T Pop();
	T Peek() const;
	int getNumElements() const;
	int getSize() const;
	void setSize(int new_size);
	bool isEmpty() const;
	bool isFull() const;
private:
	Array<T> m_stack;
	int m_size;
	int m_top;
};

/**********************************************************************
* Purpose: C'tor.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default stack .
*      
************************************************************************/

template<typename T>
inline Stack<T>::Stack() : m_size(0), m_top(0)
{ }


/**********************************************************************
* Purpose: 1 arg c'tor.
*
* Precondition:	N/A.
*
* Postcondition: Creates a stack of the size indicated.
*
************************************************************************/

template<typename T>
inline Stack<T>::Stack(int size) : m_stack(size), m_size(size), m_top(0)
{ }

/**********************************************************************
* Purpose: D'tor.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Gets rid of a Stack object.
*
************************************************************************/

template<typename T>
inline Stack<T>::~Stack()
{
	m_size = 0;
	m_top = 0;
}

/**********************************************************************
* Purpose: Copy Constructor.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Creates a copy of a stack object.
*
************************************************************************/

template<typename T>
inline Stack<T>::Stack(const Stack<T>& copy) : m_stack(copy.m_stack), m_size(copy.m_size), m_top(copy.m_top)
{ }

/**********************************************************************
* Purpose: Operator =.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Sets lhs Stack object to the same values of the rhs Stack object.
*
************************************************************************/

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack & rhs)
{
	if (this != &rhs)				//check for self assignment
	{
		m_stack = rhs.m_stack;		//set lhs data members to equal to rhs data members
		m_size = rhs.m_size;
		m_top = rhs.m_top;
	}
	return *this;
}

/**********************************************************************
* Purpose: Push data onto stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Adds new data to top of Stack.
*
************************************************************************/

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (m_size == m_top)					//check if stack is full
		throw Exception("Overflow");
	m_stack[m_top] = data;					//put data on stack top
	++m_top;								//increment stack top
}	

/**********************************************************************
* Purpose: Pop data of the stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Removes data from the top of the Stack.
*
************************************************************************/

template<typename T>
inline T Stack<T>::Pop()
{
	if (m_top == 0)							//make sure stack is not empty
	{
		throw Exception("Underflow");
	}
	{
		--m_top;							//decrement m_top to get to desired data
		return m_stack[m_top];				//return desired data
	}	
}

/**********************************************************************
* Purpose: Show current data at top of stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns data from the top of the Stack.
*
************************************************************************/

template<typename T>
inline T Stack<T>::Peek() const
{
	return m_stack[m_top - 1];		//go one down from m_top to get top data and return.
}

/**********************************************************************
* Purpose: Show how many elements are currently on stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns m_top.
*
************************************************************************/

template<typename T>
inline int Stack<T>::getNumElements() const
{
	return m_top;				//return m_top to see how many elements are in stack
}

/**********************************************************************
* Purpose: Show how many elements are currently on stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns m_top.
*
************************************************************************/

template<typename T>
inline int Stack<T>::getSize() const
{
	return m_size;					//return m_size
}

/**********************************************************************
* Purpose: Set the size of the stack to a new value.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Changes the size of m_stack and sets m_size to new value.
*
************************************************************************/

template<typename T>
inline void Stack<T>::setSize(int new_size)
{
	if (new_size < 0)														//check for negative size value
		throw Exception("Cannot have a negative sized stacked");
	if (new_size > m_size)													//if new size is bigger set the lenght and m_size
	{
		m_stack.SetLength(new_size);
		m_size = new_size;
	}
	else
	{
		m_stack.SetLength(new_size);				//if size is smaller set length and set m_size and m_top
		m_size = new_size;
		m_top = new_size;
	}
}

/**********************************************************************
* Purpose: Return true if stack is empty.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns true if the stack is empty false if not.
*
************************************************************************/

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	if (m_top == 0)					//check if stack is empty and return appropriate bool
		return true;
	return false;
}

/**********************************************************************
* Purpose: Return true if stack is full.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns true if the stack is full false if not.
*
************************************************************************/

template<typename T>
inline bool Stack<T>::isFull() const
{
	if (m_top == m_size)			//check to see if stack is full and return appropriate bool.
		return true;
	return false;
}
