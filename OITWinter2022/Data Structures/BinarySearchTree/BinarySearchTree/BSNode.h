/*************************************************************
* Author: Chris Thomas
* Filename: BSNode.h
* Date Created: 1/8/2022 6:41 PM
* Modifications: N/A
**************************************************************/
/***********************************************************************
* Class: BSNode
*
* Purpose: This class is designed to contain the information for another class
*			and be added to a tree.
*
* Manager functions:
*	BSNode();
*		Creates a default BSNode.
*	BSNode(T data);
*		Creates a BSNode with given data.
*	BSNode(const BSNode<T>& copy);
*		Creates a copy of a BSNode.
*	T& operator = (const BSNode<T>& rhs);
*		Op = for BSNode.
*	~BSNode();
*		BSNode d'tor.
* Methods:
*	
************************************************************************/
#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

template <typename T>
class BSTree;
template <typename T>
class BSNode
{
	friend class BSTree<T>;
public:

private:
	BSNode();
	BSNode(T data, BSNode<T> * left = nullptr, BSNode<T>* right = nullptr);
	BSNode(const BSNode<T>& copy);
	T& operator = (const BSNode<T>& rhs);
	~BSNode();

	BSNode<T>* m_right;
	BSNode<T>* m_left;
	T m_data;
};

/**********************************************************************
* Purpose: This is the default constructor for the BSNode class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default BSNode.
*
***********************************************************************/

template<typename T>
inline BSNode<T>::BSNode() : m_data(), m_left(nullptr), m_right(nullptr)
{ }

/**********************************************************************
* Purpose: This is the 1arg constructor for the BSNode class
*
* Precondition:	N/A.
*
* Postcondition: Creates a BSNode with given data.
*
***********************************************************************/

template<typename T>
inline BSNode<T>::BSNode(T data, BSNode<T> * left, BSNode<T>* right) : m_data(data), m_left(left), m_right(right)
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the BSNode class
*
* Precondition: A BSNode.
*
* Postcondition: Creates a copy of a BSNode.
*
***********************************************************************/

template<typename T>
inline BSNode<T>::BSNode(const BSNode<T>& copy) : m_data(copy.data), m_left(copy.m_left), m_right(copy.m_right)
{ }

/**********************************************************************
* Purpose: This is the Op = for the BSNode class
*
* Precondition: A BSNode.
*
* Postcondition: Creates a copy of the BSNode on the rhs.
*
***********************************************************************/

template<typename T>
inline T& BSNode<T>::operator=(const BSNode<T>&rhs)
{
	if (*this != &rhs)
	{
		m_data = rhs.m_data;
		m_left = rhs.m_left;
		m_right = rhs.m_right;
	}

	return *this;
}

/**********************************************************************
* Purpose: Get rid of a BSNode that is not longer needed
*
* Precondition: A BSNode.
*
* Postcondition: Destructs the BSNode.
*
***********************************************************************/

template<typename T>
inline BSNode<T>::~BSNode()
{ 
	m_left = nullptr;
	m_right = nullptr;
	delete m_left;
	delete m_right;
}
