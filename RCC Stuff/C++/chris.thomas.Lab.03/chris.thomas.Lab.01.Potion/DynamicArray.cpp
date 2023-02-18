#define _CRT_SECURE_NO_WARNINGS
#include "DynamicArray.h"
const int NO_POTION = -1;
/**********************************************************************
* Purpose: This function is the default constructor for the DynamicArray
*			class
*
* Precondition:	N/A.
*
* Postcondition: You create a default DynamicArray.
*
************************************************************************/

DynamicArray::DynamicArray() : m_array(nullptr), m_elements()
{ 
	m_array = new Potion[m_elements];
}

/**********************************************************************
* Purpose: This function is the 2 arg constructor for the DynamicArray
*			class
*
* Precondition:	N/A.
*
* Postcondition: You create a DynamicArray with the values of the args.
*
************************************************************************/

DynamicArray::DynamicArray(const DynamicArray& copy) : m_array(nullptr), m_elements(copy.m_elements)
{ }

/**********************************************************************
* Purpose: This function allows you to use the '=' operator with the
*			DynamicArray class.
*
* Precondition:	Need to a have a DynamicArray.
*
* Postcondition: Sets a DynamicArray to the values of the DynamicArray
*					on the rhs of the '=' operator.
*
************************************************************************/

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_elements = rhs.m_elements;
	}

	return *this;
}

/**********************************************************************
* Purpose: This function is the dtor for the DynamicArray class.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You delete the DynamicArray.
*
************************************************************************/

DynamicArray::~DynamicArray()
{ 
	delete[] m_array;
	m_array = nullptr;
}

/**********************************************************************
* Purpose: This function returns the m_elements of the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You return the m_elements for the DynamicArray.
*
************************************************************************/

int DynamicArray::GetElements()
{
	return m_elements;
}

/**********************************************************************
* Purpose: This function dynamically adds a Potion to the DynamicArray.
*	
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You have a new DynamicArray with the new Potion.
*
************************************************************************/

void DynamicArray::Insert(const Potion& to_add)
{ 
	Potion* temp = new Potion[m_elements + 1];

	for (int i = 0; i < m_elements; ++i)
	{
		temp[i] = m_array[i];
	}
	temp[m_elements] = to_add;
	delete[] m_array;
	m_array = temp;
	++m_elements;
}

/**********************************************************************
* Purpose: This function dynamically deletes a Potion from the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You have a new DynamicArray without the delete Potion.
*
************************************************************************/

void DynamicArray::Delete(const Potion& to_delete)
{ 
	int index = Find(to_delete);

	Potion* temp = new Potion[m_elements - 1];

	for (int i = 0; i < index; ++i)
	{
		temp[i] = m_array[i];
	}
	
	for (int i = index; i < m_elements - 1; ++i)
	{
		temp[i] = m_array[i + 1];
	}

	delete [] m_array;
	m_array = temp;
	--m_elements;
}

/**********************************************************************
* Purpose: This function displays all Potions in the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: Display all the information of the Potions in the DynamicArray.
*
************************************************************************/

void DynamicArray::Display()
{
	for (int i = 0; i < m_elements; ++i)
	{
		m_array[i].Display();
	}
}

/**********************************************************************
* Purpose: This function finds a particular Potion in the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You return an int of the index location of the Potion
*					in the DynamicArray
*
************************************************************************/

int DynamicArray::Find(const Potion& target) const 
{
	int index = 0;
	if (m_elements < 1)
	{
		throw NO_POTION;
	}
	while (strcmp(target.getName().GetString(), m_array[index].getName().GetString())!= 0 && index < m_elements - 1)
	{
		++index;
	}
	if (strcmp(target.getName().GetString(), m_array[index].getName().GetString()) != 0)
	{
		cout << "Potion not found" << endl;
	}
	return index;
}