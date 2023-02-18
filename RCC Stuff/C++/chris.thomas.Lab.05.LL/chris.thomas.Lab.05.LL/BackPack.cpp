#include "BackPack.h"

/**********************************************************************
* Purpose: This function is the default constructor for the BackPack
*			class.
*
* Precondition:	N/A.
*
* Postcondition: You create a default BackPack.
*
************************************************************************/

BackPack::BackPack() : m_potions()
{ }

/**********************************************************************
* Purpose: This function is the one arg constructor for the BackPack
*			class.
*
* Precondition:	N/A.
*
* Postcondition: You create a BackPack with a pointer to the DynamicArray
*					of Potions.
*
************************************************************************/

BackPack::BackPack(List& pots) : m_potions(pots)
{ }

/**********************************************************************
* Purpose: This function is the copy constructor for the BackPack class
*			makes a copy of a BackPack
*
* Precondition:	Need a Backpack.
*
* Postcondition: You create a copy of a BackPack.
*
************************************************************************/

BackPack::BackPack(const BackPack& copy) : m_potions(copy.m_potions)
{ }

/**********************************************************************
* Purpose: This function is the operator = for the BackPack class
*
* Precondition:	Need a BackPack
*
* Postcondition: You set a BackPack to the value of the BackPack on the
*					rhs.
*
************************************************************************/

BackPack BackPack::operator=(const BackPack& rhs)
{
	if (this != &rhs)
	{
		m_potions = rhs.m_potions;
	}

	return *this;
}

/**********************************************************************
* Purpose: This function is the dtor for the BackPack class.
*
* Precondition:	Need a BackPack.
*
* Postcondition: You delete a BackPack.
*
************************************************************************/

BackPack::~BackPack()
{ }

/**********************************************************************
* Purpose: This function displays the information of what is being
*			contained in the BackPack
*
* Precondition:	Need a BackPack.
*
* Postcondition: You display the information to the user.
*
************************************************************************/

void BackPack::Display() const
{
	m_potions.Display();
}

/**********************************************************************
* Purpose: This function saves the information of the BackPack to a
*			binary file
*
* Precondition:	Need a BackPack.
*
* Postcondition: Creates a binary file with the information of the BackPack
*
************************************************************************/

void BackPack::Save(ofstream& fout)
{
	m_potions.Save(fout);
}

/**********************************************************************
* Purpose: This function loads the information of the binary file to a
*			BackPack
*
* Precondition:	Need a BackPack.
*
* Postcondition: Creates a BackPack with the information of the binary file.
*
************************************************************************/

void BackPack::Load(ifstream& fout)
{
	m_potions.Load(fout);
}

