#include "Character.h"
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
using std::ios;
#include <ctime>

/**********************************************************************
* Purpose: This is the default constructor for the Character class
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Character.
*
************************************************************************/

Character::Character() : m_name(), m_backpack(), m_purse()
{ 
	m_armor = (int)(1 + rand() % 10);
	m_hitpoints = (int)(1 + rand() % 10);
	m_damage = (int)(1 + rand() % 10);
}

Character::Character(String name) : m_name(name), m_backpack(), m_purse()
{ 
	m_armor = (int)(1 + rand() % 10);
	m_hitpoints = (int)(1 + rand() % 10);
	m_damage = (int)(1 + rand() % 10);
}

/**********************************************************************
* Purpose: This is the three arg constructor for the Character class
*
* Precondition:	N/A.
*
* Postcondition: Creates a Character set to the values of the three args.
*
************************************************************************/

Character::Character(const String name, BackPack backpack, CoinPouch purse) : m_name(name), m_backpack(backpack), m_purse(purse)
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the Character class.
*
* Precondition:	Need a Character.
*
* Postcondition: Creates a copy of a Character.
*
************************************************************************/

Character::Character(const Character& copy) : m_name(copy.m_name), m_backpack(copy.m_backpack), m_purse(copy.m_purse)
{ }

/**********************************************************************
* Purpose: This is the op equals for the Character class
*
* Precondition: A Character.
*
* Postcondition: Creates a Character set to the values of the Character on the rhs.
*
************************************************************************/

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_backpack = rhs.m_backpack;
		m_purse = rhs.m_purse;
	}
	return *this;
}

/**********************************************************************
* Purpose: This is the dtor for the Character class.
*
* Precondition: A Character.
*
* Postcondition: Gets rid of a Character that is not longer needed
*
************************************************************************/

Character::~Character()
{ }

/**********************************************************************
* Purpose: This is the Display function for the Character class.
*
* Precondition: A Character.
*
* Postcondition: Shows the information of the Character to the user.
*
************************************************************************/

void Character::Display() const
{
	cout << "Character Name: " << m_name.GetString() << endl;;
	cout << endl;
	cout << "--Inventory-- " << endl;
	cout << endl;
	try
	{
		m_backpack.Display();
	}
	catch (int e)
	{
		if (e == EMPTY_LIST)
		{
			cout << "The Backpack is empty" << endl;
		}
	}
	cout << endl;
	cout << "--Currency-- " << endl;
	m_purse.Display();
	cout << endl;
	cout << "Hitpoints: " << m_hitpoints << endl;
	cout << "Armor: " << m_armor << endl;
	cout << "Attack: " << m_damage << endl;
	cout << endl;
}

/**********************************************************************
* Purpose: This function returns the m_name data member of the Character
*
* Precondition: A Character.
*
* Postcondition: Returns m_name.
*
************************************************************************/

String Character::getName() const
{
	return m_name;
}

/**********************************************************************
* Purpose: This function saves the Character to binary file
*
* Precondition: A Character.
*
* Postcondition: Creates a binary file with the information of the Character.
*
************************************************************************/

void Character::Save(ofstream& fout)
{
	m_name.Save(fout);
	m_backpack.Save(fout);
	m_purse.Save(fout);
}

/**********************************************************************
* Purpose: This function loads a Character from the information of a binary file.
*
* Precondition: A Character.
*
* Postcondition: Creates a Character from the information of the binary file.
*
************************************************************************/

void Character::Load(ifstream& fout)
{
	m_name.Load(fout);
	m_backpack.Load(fout);
	m_purse.Load(fout);
}

void Character::WhatAmI()
{
	cout << "I am a Player Character" << endl;
}

void Character::Special()
{
	cout << "Will To Survive" << endl;
	++m_armor;
	++m_hitpoints;
}

void Character::Rroll()
{
	srand(time(0));
	m_armor = (int)(1 + rand() % 10);
	m_hitpoints = (int)(1 + rand() % 10);
	m_damage = (int)(1 + rand() % 10);
}

void Character::DisplayAttributes()
{
	cout << "Hitpoints: " << m_hitpoints << endl;
	cout << "Armor: " << m_armor << endl;
	cout << "Attack: " << m_damage << endl;
	cout << endl;
}

void Character::SetName(String name)
{
	m_name = name;
}