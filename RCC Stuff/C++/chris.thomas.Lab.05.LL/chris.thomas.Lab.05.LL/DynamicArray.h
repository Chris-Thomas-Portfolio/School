#pragma once
#include "Potion.h"
const int NO_POTION = -1;
/************************************************************************
* Class: DynamicArray
*
* Purpose: This class is designed to hold the DynamicArray of Potions.
*
* Manager functions:
* 	DynamicArray ( )
* 		The default of the DynamicArray is nullptr.
*	DynamicArray (const DynamicArray& copy)
*		Creates a copy of DynamicArray.
*	DynamicArray& operator = (const BackPack & rhs)
*	~DynamicArray()
*	void Display() const;
*	int Find(const Potion& target) const;
*		returns the index location of target.
*	void Save(ofstream& fout);
*		Saves the DynamicArray to a binary file.
*	void Load(ofstream& fout);
*		Loads the DynamicArray from the binary file.
*************************************************************************/

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const DynamicArray& copy);
	DynamicArray& operator=(const DynamicArray& rhs);
	~DynamicArray();
	int GetElements() const;
	void Insert(const Potion& to_add);
	void Delete(const Potion& to_delete);
	int Find(const Potion& target) const;
	void Display() const;
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	Potion* m_array;
	int m_elements;
};