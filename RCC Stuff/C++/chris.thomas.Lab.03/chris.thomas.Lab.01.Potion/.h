#pragma once
#include <iostream>
#include "Potion.h"

/************************************************************************
* Class: DynamicArray
*
* Purpose: This class is designed to dynamically create an array of Potions.
*
* Manager functions:
* 	DynamicArray ( )
* 		The default of the DynamicArray is one nullptr Potion
*	DynamicArray (const DynamicArray& copy)
*		Creates a DynamicArray that is a copy of one on the rhs.
*	operator = (const DynamicArray & rhs)
*	~DynamicArray()
*	Insert(const Potion& to_add)
*		Dynamically adds a Potion to the DynamicArray.
*	Delete(const Potion& to_delete)
*		Dynamically deletes a Potion from the DynamicArray.
*
*************************************************************************/

class DynamicArray {
public:
	DynamicArray();
	DynamicArray(const DynamicArray& copy);
	DynamicArray& operator =(const DynamicArray& rhs);
	~DynamicArray();
	int GetElements();
	void Insert(const Potion& to_add);
	void Delete(const Potion& to_delete);
	void Display();
private:
	Potion * m_array;
	int m_elements = 0;
	int Find(const Potion& target) const;
};