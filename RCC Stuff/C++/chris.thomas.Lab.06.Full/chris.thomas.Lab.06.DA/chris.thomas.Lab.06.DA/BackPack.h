#pragma once
#include "DynamicArray.h"
#include "Potion.h"

/************************************************************************
* Class: BackPack
*
* Purpose: This class is designed to hold the DynamicArray of Potions.
*
* Manager functions:
* 	BackPack ()
* 		The default of the BackPack is Empty.
*	BackPack (DynamicArray& pots)
*		Creates a DynamicArray set to the adress of the variable.
*	BackPack (const BackPack& copy)
*	operator = (const BackPack & copy)
*	~BackPack()
*	void Display() const;
*	void Save(ofstream& fout)
*		Saves the BackPack to a binary file
*	void Load(ifstream& fout)
*		Loads the BackPack from the binary file.
*
*************************************************************************/

class BackPack
{
public:
	BackPack();
	BackPack(DynamicArray<Potion> pots);
	BackPack(const BackPack& copy);
	BackPack operator=(const BackPack& rhs);
	~BackPack();
	void Display() const;
	void Save(ofstream& fout);
	void Load(ifstream& fout);
	void DeleteItem(Potion name);
private:
	DynamicArray<Potion> m_potions;
};