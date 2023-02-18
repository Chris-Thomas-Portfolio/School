/*************************************************************
* Author: Chris Thomas
* Filename: BSTree.h
* Date Created: 1/25/2022 6:41 PM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 9 Binary Search Tree
*
* Overview: This class creates a binary search tree.
*
*
* Input: Inputs all come from the consumer.
*
*
* Output: No specific outputs as we are creating a binary search tree for data storage.
*
*
************************************************************/
/************************************************************************
* Class: BSTree
*
* Purpose: This class is designed to create a binary search tree.
*
* Manager functions:
* 	BSTree ()
* 		The default constructor for the List.
*	BSTree (constBSTree<T>& copy)
*		Creates a copy of a List.
*	BSTree operator =(const BSTree<T>& rhs)
*	~BSTree()
*		Destructor for List
* Methods:
*	void Delete(T data);
*		Finds the node that matches given data and deletes it.
*	void Insert(T data);
*		Inserts given data in appropraite location in tree.
*	void Purge();
*		Deletes all nodes in tree
*	void InOrder(void(*visit)(T data));
*		Traverses the tree in order.
*	void PostOrder(void (*visit)(T data));
*		Traverses the tree in post order.
*	void PreOrder(void (*visit)(T data));
*		Traverses the tree in pre order.
*	int Height();
*		Calculates the height of the tree.
*	void BreadthFirst(void (*visit)(T data));
*		Traverses the tree starting at the top left to right.
*************************************************************************/
#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "BSNode.h"
#include "Exception.h"
#include "Queue.h"

template <typename T>
class BSTree
{
public:
	BSTree();
	BSTree(BSTree<T>& copy);
	BSTree<T> operator = (const BSTree<T>& rhs);
	~BSTree();
	void Delete(T data);
	void Insert(T data);
	void Purge();
	void InOrder(void(*visit)(T data));
	void PostOrder(void (*visit)(T data));
	void PreOrder(void (*visit)(T data));
	int Height();
	void BreadthFirst(void (*visit)(T data));
private:
	void Delete(BSNode<T>*& current);
	void Copy(BSNode<T>*& new_tree, BSNode<T>* copy);
	void Insert(BSNode<T>*& current, T data);
	void InOrder(BSNode<T>* current, void (*visit)(T data));
	void PostOrder(BSNode<T>*& current, void (*visit)(T data));
	void PreOrder(BSNode<T>*& current, void (*visit)(T data));
	void Purge(BSNode<T>* current);
	int Height(BSNode<T>*& current);
	void BreadthFirst(BSNode<T>*& current, void (*visit)(T data));

	BSNode<T> * m_root;
};

/**********************************************************************
* Purpose: This is the default constructor for the BSTree class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default BSTree.
*
***********************************************************************/

template<typename T>
inline BSTree<T>::BSTree() : m_root(nullptr)
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the BSTree class.
*
* Precondition:	A BSTree.
*
* Postcondition: Creates a copy of a BSTree.
*
***********************************************************************/

template<typename T>
inline BSTree<T>::BSTree(BSTree<T>& copy)
{
	Copy(m_root, copy.m_root);				//call the copy function for recursion
}

/**********************************************************************
* Purpose: This is the Op equals for the BSTree class.
*
* Precondition:	A BSTree.
*
* Postcondition: Creates a copy of a BSTree on the rhs.
*
***********************************************************************/

template<typename T>
inline BSTree<T> BSTree<T>::operator=(const BSTree<T>& rhs)
{
	return Copy(m_root, rhs.m_root);
}

/**********************************************************************
* Purpose: This is the destructor for the BSTree class.
*
* Precondition:	A BSTree.
*
* Postcondition: Removes a BSTree.
*
***********************************************************************/

template<typename T>
inline BSTree<T>::~BSTree()
{
	Purge();
}

/**********************************************************************
* Purpose: Delete a specified node in tree.
*
* Precondition:	A BSTree.
*
* Postcondition: Deletes the node in the tree that has the specified data.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Delete(T data)
{
	if (m_root == nullptr)
	{
		throw Exception("Empty Tree");						//throw exception for empty tree
	}
	BSNode<T>* current = m_root;
	BSNode<T>* previous = m_root;
	bool found = false;

	while (current != nullptr && found != true)				//traverse the tree looking for data
	{
		if (current->m_data == data)
		{
			found = true;
		}
		else
		{
			previous = current;
			if (current->m_data > data)						//go left or right depending on data
			{
				current = current->m_left;
			}
			else
			{
				current = current->m_right;
			}
		}
	}

	if (current == nullptr)
	{
		throw Exception("Not found");						//throw exception if not found
	}
	else if (found == true)									//if found delete
	{
		if (current == m_root)
		{
			Delete(m_root);
		}
		else if (previous->m_data > data)
		{
			Delete(previous->m_left);
		}
		else
		{
			Delete(previous->m_right);
		}
	}
}

/**********************************************************************
* Purpose: This is the public insert for the BSTree class.
*
* Precondition:	A BSTree.
*
* Postcondition: Inserts a node into the tree with given data.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Insert(T data)
{
	Insert(m_root, data);
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and make a copy of it.
*
* Precondition:	A BSTree.
*
* Postcondition: Creates a copy of a BSTree.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Copy(BSNode<T>*& new_tree, BSNode<T>* copy)
{
	if (copy == nullptr)							//check to see if copy is nullptr
	{
		new_tree = nullptr;							//if it is set new_tree to nullptr
	}
	else
	{
		new_tree = new BSNode<T>(copy->m_data);		//set new tree to copies data
		Copy(new_tree->m_left, copy->m_left);		//move left down the tree
		Copy(new_tree->m_right, copy->m_right);		//move right downt he tree
	}	
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and insert a new BSNode
*			in the appropriate spot.
*
* Precondition:	A BSTree.
*
* Postcondition: Inserts a BSNode with given data into tree in appropriate spot.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Insert(BSNode<T> *& current, T data)
{
	if (current == nullptr)					//if current is nullptr make a new BSNode with the data
		current = new BSNode<T>(data);
	else if (data < current->m_data)		//if data is less than currents data call Insert with currents m_left
		Insert(current->m_left, data);
	else
		Insert(current->m_right, data);		//if data is more than currents data call Insert with currents m_right
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and delete all BSNodes in it.
*
* Precondition:	A BSTree.
*
* Postcondition: Deletes all BSNodes in a tree.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Purge()
{
	Purge(m_root);
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and access the data in order.
*
* Precondition:	A BSTree.
*
* Postcondition: Access data of BSTree in order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::InOrder(void (*visit)(T data))
{
	InOrder(m_root, (*visit));
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and access the data in post order.
*
* Precondition:	A BSTree.
*
* Postcondition: Access data of BSTree in post order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::PostOrder(void(*visit)(T data))
{
	PostOrder(m_root, (*visit));
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and access the data in pre order.
*
* Precondition:	A BSTree.
*
* Postcondition: Access data of BSTree in pre order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::PreOrder(void(*visit)(T data))
{
	PreOrder(m_root, (*visit));
}

/**********************************************************************
* Purpose: This function will calculate the height of the tree.
*
* Precondition:	A BSTree.
*
* Postcondition: Returns an int for the height of the tree.
*
***********************************************************************/

template<typename T>
inline int BSTree<T>::Height()
{
	return Height(m_root);
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and access the data starting
*			at the top and moving left to right.
*
* Precondition:	A BSTree.
*
* Postcondition: Access data of BSTree from top to bottom and left to right.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::BreadthFirst(void(*visit)(T data))
{
	BreadthFirst(m_root, (*visit));
}

/**********************************************************************
* Purpose: This function will calculate the height of the tree.
*
* Precondition:	A BSTree.
*
* Postcondition: Returns an int for the height of the tree.
*
***********************************************************************/

template<typename T>
inline int BSTree<T>::Height(BSNode<T>*& current)
{
	int temp = 0;
	if (current == nullptr)
	{
		temp = -1;
	}
	else
	{
		int left = Height(current->m_left);			//set left to lefts height
		int right = Height(current->m_right);		//set right to rights height
		if (left > right)							//determine which is bigger and set temp to that value +1
		{
			temp = (left + 1);
		}
		else
		{
			temp = (right + 1);
		}
	}
	return temp;									//return temp
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and access the data starting
*			at the top and moving left to right.
*
* Precondition:	A BSTree.
*
* Postcondition: Access data of BSTree from top to bottom and left to right.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::BreadthFirst(BSNode<T>*& current, void(*visit)(T data))
{
	BSNode<T>* temp = nullptr;
	Queue<BSNode<T>*> queue;					//create a queue
	queue.Enqueue(current);						//enqueue the root node
	while (queue.isEmpty() != true)
	{
		temp = queue.Dequeue();					//traverse and visit nodes in desired order
		visit(temp->m_data);
		if (temp->m_left != nullptr)
		{
			queue.Enqueue(temp->m_left);
		}
		if (temp->m_right != nullptr)
		{
			queue.Enqueue(temp->m_right);
		}
	}
}

/**********************************************************************
* Purpose: Delete a specified node in tree.
*
* Precondition:	A BSTree.
*
* Postcondition: Deletes the node in the tree that has the specified data.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Delete(BSNode<T>*& current)
{
	BSNode<T>* cur = current;
	BSNode<T>* previous = nullptr;
	if (current == nullptr)
	{
		throw Exception("Not found");										//throw exception if not found or empty
	}
	else if (current->m_left == nullptr && current->m_right == nullptr)
	{
		current = nullptr;
	}
	else if (current->m_left == nullptr)
	{
		current = current->m_right;
	}
	else if (current->m_right == nullptr)
	{
		current = current->m_left;
	}
	else
	{
		cur = current->m_left;												
		while (cur->m_right != nullptr)										//traverse right down
		{
			previous = current;
			cur = cur->m_right;
		}
		current->m_data = cur->m_data;
		if (previous == nullptr)
		{
			current->m_left = cur->m_left;
		}
		else
		{
			previous->m_right = cur->m_left;								//treaverse left down the tree
		}
	}
	delete cur;																//delete node
}

/**********************************************************************
* Purpose: This function will traverse the BSTree using recursive functions
*			to then call the visit function on the data in order.
*
* Precondition:	A BSTree.
*
* Postcondition: Calls the visit function on the data in order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::InOrder(BSNode<T>* current, void(*visit)(T data))
{
	if (current != nullptr)
	{
		InOrder(current->m_left, (*visit));				//recursively call InOrder with currents m_left
		visit(current->m_data);							//call the visit function on currents m_data
		InOrder(current->m_right, (*visit));			//recursivley call InOrder with currents m_right
	}
}

/**********************************************************************
* Purpose: This function will traverse the BSTree using recursive functions
*			to then call the visit function on the data in post order.
*
* Precondition:	A BSTree.
*
* Postcondition: Calls the visit function on the data in post order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::PostOrder(BSNode<T>*& current, void(*visit)(T data))
{
	if (current != nullptr)
	{
		PostOrder(current->m_left, (*visit));			//call PostOrder with currents m_left
		PostOrder(current->m_right, (*visit));			//call PostOrder with currents m_right
		visit(current->m_data);							//call the visit function with currents m_data
	}
}

/**********************************************************************
* Purpose: This function will traverse the BSTree using recursive functions
*			to then call the visit function on the data in pre order.
*
* Precondition:	A BSTree.
*
* Postcondition: Calls the visit function on the data in pre order.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::PreOrder(BSNode<T>*& current, void(*visit)(T data))
{
	if (current != nullptr)
	{
		visit(current->m_data);							//call visit function on currents data
		PreOrder(current->m_left, (*visit));			//traverse down left side of tree
		PreOrder(current->m_right, (*visit));			//traverse down right side of tree
	}
}

/**********************************************************************
* Purpose: This function will traverse the BSTree and delete all BSNodes in it.
*
* Precondition:	A BSTree.
*
* Postcondition: Deletes all BSNodes in a tree.
*
***********************************************************************/

template<typename T>
inline void BSTree<T>::Purge(BSNode<T>* current)
{
	if (current != nullptr)
	{
		Purge(current->m_left);				//recursively call Purge on currents left 
		Purge(current->m_right);			//recursively call Purge on currents right
		delete current;						//delete nodes
	}

}
