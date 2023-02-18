#pragma once
#include "Exception.h"
/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be
* started at any base.
*
* Manager functions:
* Array ( )
* The default length and starting index is zero the T* is set to nullptr.
* Array (int length, int start_index = 0)
* Creates an appropriate sized array with the starting index
*              either zero or the supplied starting value.
* Array (const Array<T> & copy)
*	Array(Array<T>&& copy);
*	Array & operator=(const Array<T>& rhs);
*	Array & operator=(Array<T>&& rhs);
*	~Array();
*
* Methods:
* T& operator [ ] (int index)
* int GetStartIndex() const;
* Gets start index and returns its value.
* void SetStartIndex(int start_index) ;
* Sets start index to given value.
* int GetLength() const;
* Returns lenght.
* void SetLength(int length);
* Sets m_length to given value and recreates m_array to be that length.
*************************************************************************/

template<typename T>

class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array<T>& copy);
	Array(Array<T>&& copy);
	Array & operator=(const Array<T>& rhs);
	Array & operator=(Array<T>&& rhs);
	~Array();
	T& operator[](int index);
	int GetStartIndex() const;
	void SetStartIndex(int start_index) ;
	int GetLength() const;
	void SetLength(int length);
private:
	int m_start_index;
	int m_length;
	T * m_array;
};

/**********************************************************************
* Purpose: C'tor
*
* Precondition:
*     N/A
*
* Postcondition:
*      Creates an default array with m_array = nullptr, m_length = 0, and m_start_index = 0
*
************************************************************************/

template<typename T>
inline Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0)
{
}

/**********************************************************************
* Purpose: 1 Arg C'tor
*
* Precondition:
*     Needs to be given a length value
*
* Postcondition:
*      Creates an array with m_array = nullptr and reads in a length and start_index
* if start_index is not provided it defaults to 0.
*
************************************************************************/

template<typename T>
inline Array<T>::Array(int length, int start_index) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
	m_array = new T[m_length];
}

/**********************************************************************
* Purpose: Copy Constructor
*
* Precondition:
*     Must have an array to copy.
*
* Postcondition:
*      Copies an array.
*
************************************************************************/

template<typename T>
inline Array<T>::Array(const Array<T>& copy) : m_array(nullptr), m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	m_array = new T[m_length];			//set m_array to size of lenght
	for (int i = 0; i < m_length; ++i)
	{
		m_array[i] = copy.m_array[i];	//copy over each element in copy.m_array to m_array
	}
}

/**********************************************************************
* Purpose: Move Constructor
*
* Precondition:
*     Must have an array to move.
*
* Postcondition:
*      Moves an array.
*
************************************************************************/
template<typename T>
inline Array<T>::Array(Array<T>&& copy) : m_array(copy.m_array)
{
	copy.m_array = nullptr;
}

/**********************************************************************
* Purpose: Op =
*
* Precondition:
*     Must have an array to set array equal to.
*
* Postcondition:
*      Moves the array from the rhs to the lhs.
*
************************************************************************/

template<typename T>
inline Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)							//check to make sure they are not already equal
	{
		delete[] m_array;						//delete m_array
		m_length = rhs.m_length;				//set m_length to the length on the rhs
		m_array = new T[m_length];				//make m_array a new T the size of the new m_length


		for (int i = 0; i < m_length; ++i)
		{
			m_array[i] = rhs.m_array[i];		//copy all elements from rhs into m_array
		}
	}

	return *this;								//return m_array
}

/**********************************************************************
* Purpose: Move Op =
*
* Precondition:
*     Must have an array to move.
*
* Postcondition:
*      Moves an array.
*
************************************************************************/

template<typename T>
inline Array<T>& Array<T>::operator=(Array<T>&& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		rhs.m_array = nullptr;
	}

	return *this;
}

/**********************************************************************
* Purpose: D'tor
*
* Precondition:
*     Must have an array to destruct.
*
* Postcondition:
*      Deletes m_array and sets all vaules back to default.
*
************************************************************************/
template<typename T>
inline Array<T>::~Array()
{
	delete[]m_array;

	m_array = nullptr;
	m_start_index = 0;
	m_length = 0;
}

/**********************************************************************
* Purpose: Op []
*
* Precondition:
*     Must have an array to retrieve from.
*
* Postcondition:
*      returns value and specified index of array.
*
************************************************************************/

template<typename T>
inline T& Array<T>::operator[](int index)
{
	if (index < 0 || index > m_length + m_start_index)		//make sure user is staying in bounds of array
	{
		throw Exception("Exception!");						//throw exception if value is out of bounds
	}
	else
	{
		return m_array[index - m_start_index];				//return appropriate index value
	}
}

/**********************************************************************
* Purpose: Return start index value.
*
* Precondition:
*     N/A
*
* Postcondition:
*      Returns the value of m_start_indexx.
*
************************************************************************/

template<typename T>
inline int Array<T>::GetStartIndex() const
{
	return m_start_index;
}

/**********************************************************************
* Purpose: Set the Start Index value
*
* Precondition:
*     N/A
*
* Postcondition:
*      Sets m_start_index to given value.
*
************************************************************************/

template<typename T>
inline void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**********************************************************************
* Purpose: Get Length
*
* Precondition:
*     N/A
*
* Postcondition:
*      Returns the m_length value.
*
************************************************************************/

template<typename T>
inline int Array<T>::GetLength() const
{
	return m_length;
}

/**********************************************************************
* Purpose: Set Length
*
* Precondition:
*     N/A
*
* Postcondition:
*      Sets the value of m_length to given value.
*
************************************************************************/

template<typename T>
inline void Array<T>::SetLength(int length)
{
	if (length < 0)										//make sure length isnt negative if it is throw exception
	{
		throw Exception("Exception!");
	}
	else if (length < m_length)							//if length is less than m_length can just set m_length to given value
	{
		m_length = length;
	}
	else
	{
		T* temp = new T[length];						//create temporary storage for data in m_array
		for (int i = 0; i < m_length; i++)
		{
			temp[i] = m_array[i];						//copy data from m_array into temp
		}
		delete[]m_array;								//delete m_array
		m_array = nullptr;								//set m_array to nullptr
		m_length = length;								//set new m_length
		m_array = new T[m_length];						//set m_array to new T the length of new length
		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = temp[i];						//copy all data from temp back into new m_array
		}
		delete[] temp;									//delete temp
	}
}
