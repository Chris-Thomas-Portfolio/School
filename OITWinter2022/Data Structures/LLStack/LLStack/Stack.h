/*************************************************************
* Author: Chris Thomas
* Filename: Stack.h
* Date Created: 1/22/2022 11:04 AM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 6 Linked List based Stack
*
* Overview: This class creates a Stack class using a Linked List class
*			as a base.
* 
*
* Input: Inputs all come from the consumer.
* 
*
* Output: No specific outputs as we are creating a stack for data storage.
* 
*
************************************************************/
/************************************************************************
* Class: Stack
*
* Purpose: This class is designed to create a Stack using a linked List as a base.
*
* Manager functions:
* 	Stack();
*		Default constructor for Stack
*	Stack(const Stack& copy);
*		Copy constructor for Stack
*	~Stack();
*		Destructor for Stack
*	Stack<T>& operator = (const Stack<T>& rhs);
*		Op = for Stack
* Methods:
*	void Push(T data);
*		Pushes data onto top to Stack
*	T Pop();
*		Pops the top data from the Stack
*	T Peek() const;
*		Shows what is currently at top of Stack
*	int getNumElements() const;
*		Returns value showing number of elements in Stack
*	bool isEmpty() const;
*		Return true or false for if the Stack is empty
*************************************************************************/
#pragma once
#include "List.h"

template <typename T>

class Stack
{
public:
	Stack();
	Stack(const Stack& copy);
	~Stack();
	Stack<T>& operator = (const Stack<T>& rhs);
	void Push(T data);
	T Pop();
	T Peek() const;
	int getNumElements() const;
	bool isEmpty() const;
private:
	List<T> m_stack;
	int num_elements;
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
inline Stack<T>::Stack() : num_elements(0)
{ }

/**********************************************************************
* Purpose: Copy Constructor.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Creates a copy of a stack object.
*
************************************************************************/

template<typename T>
inline Stack<T>::Stack(const Stack & copy) : m_stack(copy.m_stack), num_elements(copy.num_elements)
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
	num_elements = 0;
}

/**********************************************************************
* Purpose: Operator =.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Sets lhs Stack object to the same values of the rhs Stack object.
*
************************************************************************/

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
	if (this != &rhs)				//check for self assignment
	{
		m_stack = rhs.m_stack;				//set lhs to rhs values
		num_elements = rhs.num_elements;
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
	m_stack.Prepend(data);				//put new node with new data at front of List
	num_elements++;						//increment num_elements 
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
	if (num_elements == 0)									//if stack is empty cannot Pop throw exception
	{
		throw Exception("Cannot Pop from empty stack");
	}
	T data = m_stack.First();								//create a new T with the information at top of stack
	m_stack.Extract(m_stack.First());						//delete the top of the stack
	num_elements--;											//decrease the number of elements in stack
	return data;											//return the copy of the desired data
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
	if (num_elements == 0)						//make sure stack is not empty if it is throw exception
		throw Exception("Stack empty");
	return m_stack.First();						//return the information of the item at top of stack
}

/**********************************************************************
* Purpose: Show how many elements are currently on stack.
*
* Precondition:	Need a Stack object.
*
* Postcondition: Returns num_elements.
*
************************************************************************/

template<typename T>
inline int Stack<T>::getNumElements() const
{
	return num_elements;						//return number of elements
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
	if (num_elements == 0)			//if num_elements is 0 the stack is empty and return true
	{
		return true;
	}
	else
	{
		return false;				//if not return false
	}
}
