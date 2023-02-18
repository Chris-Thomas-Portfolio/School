#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
using std::fstream;
using std::ios;
#include "Potion.h"
const int NO_POTION = -1;
/************************************************************************
* Class: DynamicArray
*
* Purpose: This class is designed to hold the DynamicArray of Potions.
*
* Manager functions:
* 	DynamicArray()
* 		The default of the DynamicArray is nullptr.
*	DynamicArray (const DynamicArray& copy)
*		Creates a copy of DynamicArray.
*	DynamicArray& operator = (const BackPack & rhs)
*	~DynamicArray()
*	void Display() const
*	int Find(const Potion& target) const;
*		returns the index location of target.
*	void Save(ofstream& fout)
*		Saves the DynamicArray to a binary file.
*	void Load(ofstream& fout)
*		Loads the DynamicArray from the binary file.
*************************************************************************/

template<class T> 
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const T& copy);
	T& operator=(const T& rhs);
	~DynamicArray();
	int GetElements() const;
	void Insert(const T& to_add);
	void Delete(const T& to_delete);
	int Find(const T& target) const;
	void Display() const;
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	T* m_array;
	int m_elements;
};

/**********************************************************************
* Purpose: This function is the default constructor for the DynamicArray
*			class
*
* Precondition:	N/A.
*
* Postcondition: You create a default DynamicArray.
*
************************************************************************/

template<class T>
inline DynamicArray<T>::DynamicArray() : m_array(nullptr), m_elements()
{ }

/**********************************************************************
* Purpose: This function is the 2 arg constructor for the DynamicArray
*			class
*
* Precondition:	N/A.
*
* Postcondition: You create a DynamicArray with the values of the args.
*
************************************************************************/

template <class T>
inline DynamicArray<T>::DynamicArray(const T& copy) : m_array(nullptr), m_elements(0)
{
	for (int i = 0; i < copy.m_elements; ++i)
	{
		Insert(copy.m_array[i]);
	}
}

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

template <class T>
inline T& DynamicArray<T>::operator=(const T& rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_elements = 0;
		for (int i = 0; i < rhs.m_elements; ++i)
		{
			Insert(rhs.m_array[i]);
		}
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

template <class T>
inline DynamicArray<T>::~DynamicArray()
{
	m_array = nullptr;
	m_elements = 0;
}

/**********************************************************************
* Purpose: This function returns the m_elements of the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: You return the m_elements for the DynamicArray.
*
************************************************************************/

template <class T>
inline int DynamicArray<T>::GetElements() const
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

template <class T>
inline void DynamicArray<T>::Insert(const T& to_add)
{
	T* temp = new T[m_elements + 1];

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

template <class T>
inline void DynamicArray<T>::Delete(const T& to_delete)
{
	int index = Find(to_delete);
	if (index != -1)
	{
		T* temp = new T[m_elements - 1];

		for (int i = 0; i < index; ++i)
		{
			temp[i] = m_array[i];
		}

		for (int i = index; i < m_elements - 1; ++i)
		{
			temp[i] = m_array[i + 1];
		}

		delete[] m_array;
		m_array = temp;
		--m_elements;
	}
}

/**********************************************************************
* Purpose: This function displays all the data in the DynamicArray.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: Display the DynamicArray to the user.
*
************************************************************************/

template <class T>
inline void DynamicArray<T>::Display() const
{
	try
	{
		if (m_elements < 1)
		{
			throw(NO_POTION);
		}
		for (int i = 0; i < m_elements; ++i)
		{
			m_array[i].Display();
		}
	}
	catch (const int NO_POTION)
	{
		cout << "WOW SUCH EMPTY" << endl;
	}
}

/**********************************************************************
* Purpose: This function saves the DynamicArray to a binary file.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: Creates a binary file with the information of the DynamicArray.
*
************************************************************************/

template <class T>
inline void DynamicArray<T>::Save(ofstream& fout)
{
	fout.write(reinterpret_cast<char*>(&m_elements), sizeof(m_elements));
	for (int i = 0; i < m_elements; ++i)
	{
		m_array[i].Save(fout);
	}
}

/**********************************************************************
* Purpose: This function loads the DynamicArray from a binary file.
*
* Precondition:	Need to have a DynamicArray.
*
* Postcondition: Creates a DynamicArray with the information of the binary file.
*
************************************************************************/

template <class T>
inline void DynamicArray<T>::Load(ifstream& fout)
{
	fout.read(reinterpret_cast<char*>(&m_elements), sizeof(m_elements));
	m_array = new T[m_elements];
	for (int i = 0; i < m_elements; ++i)
	{
		m_array[i].Load(fout);
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

template <class T>
inline int DynamicArray<T>::Find(const T& target) const
{
	int index = 0;
	if (m_elements < 1)
	{
		throw NO_POTION;
	}
	while (strcmp(target.getName().GetString(), m_array[index].getName().GetString()) != 0 && index < m_elements - 1)
	{
		++index;
	}
	if (strcmp(target.getName().GetString(), m_array[index].getName().GetString()) != 0)
	{
		cout << "Potion not found" << endl;
	}
	return index;
}
