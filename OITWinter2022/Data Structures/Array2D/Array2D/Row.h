/************************************************************************
* Class: Row
*
* Purpose: This class is used to create a Row object for the Array2D class
*
* Manager functions:
*	Row();
* 	Row(Array2D<T>& array2D, int row);
*	Row(const Row<T>& copy)
*	~Row();
* Methods:
*	T& operator[](int column);
*		Subscript operator for Row.
*	T& operator[](int column) const;
*		Const subscript operator for Row.
*	Row<T>& operator=(const Row<T>& rhs);
*		Operator = for Row.
*************************************************************************/
#pragma once
template <typename T>
class Array2D;
template <typename T>
class Row
{
	friend class Array2D<T>;
public:
	Row();
	Row(const Row<T>& copy);
	~Row();
	Row(Array2D<T>& array2D, int row);
	T& operator[](int column);
	T& operator[](int column) const;
	Row<T>& operator=(const Row<T>& rhs);
private:
	Array2D<T>& m_array;
	int m_row;
};

/**********************************************************************
* Purpose: The Row default C'tor.
*
* Precondition : N/A.
*
* Postcondition : Creates a Row object.
*
************************************************************************/

template <typename T>
inline Row<T>::Row() : m_row(0)
{ }

/**********************************************************************
* Purpose: The Row 2 arg C'tor.
*
* Precondition : N/A.
*
* Postcondition : Creates a Row object of specified values.
*
************************************************************************/

template <typename T>
inline Row<T>::Row(Array2D<T>& array2D, int row) : m_array(array2D), m_row(row)
{ }

/**********************************************************************
* Purpose: The Row copy C'tor.
*
* Precondition : N/A.
*
* Postcondition : Creates a copy of a Row object.
*
************************************************************************/

template <typename T>
inline Row<T>::Row(const Row<T>& copy) : m_array(copy.m_array), m_row(copy.m_row)
{ }

/**********************************************************************
* Purpose: The Row D'tor.
*
* Precondition : A Row object.
*
* Postcondition : Destructs a Row.
*
************************************************************************/

template<typename T>
inline Row<T>::~Row()
{ 
	m_row = 0;
}

/**********************************************************************
* Purpose: The Row subscript operator.
*
* Precondition : A Row object.
*
* Postcondition : Creates a Row object.
*
************************************************************************/

template <typename T>
inline T& Row<T>::operator[](int column)
{
	return m_array.Select(m_row, column);
}

/**********************************************************************
* Purpose: The const Row subscript operator.
*
* Precondition : A Row object.
*
* Postcondition : Creates a const Row object.
*
************************************************************************/

template<typename T>
inline Row<T>& Row<T>::operator=(const Row<T>& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
	}
}