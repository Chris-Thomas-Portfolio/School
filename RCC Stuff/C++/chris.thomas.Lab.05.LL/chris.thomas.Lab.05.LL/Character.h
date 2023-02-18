#pragma once
#include "String.h"
#include "CoinPouch.h"
#include "BackPack.h"
#include <fstream>
using std::fstream;

/************************************************************************
* Class: Character
*
* Purpose: This class is designed to hold the information for a character
*			this includes a String for a name, a BackPack for items the
*			character possesses and a CoinPouch for how much money the
*			character has.
*
* Manager functions:
* 	Character ( )
* 		The default of the Character is nullptr.
*	Character (String name, BackPack backpack, CoinPouch purse)
*		Creates a character with the provide information.
*	Character(const Character& copy)
*		Creates a copy of a Character.
*	Character operator =(const Character& rhs)
*	~DynamicArray()
* Methods:
*	void Display() const;
*	String GetName() const;
*		return the String that contains the name of the Character
*	void Save(ofstream& fout);
*		Saves the Character to a binary file
*	void Load(ifstream& fout);
*		Load the Character from a binary file
*************************************************************************/

class Character
{
public:
	Character();
	Character(String name, BackPack backpack, CoinPouch purse);
	Character(const Character& copy);
	Character operator =(const Character& rhs);
	~Character();
	void Display();
	String GetName() const;
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	String m_name;
	BackPack m_backpack;
	CoinPouch m_purse;
};