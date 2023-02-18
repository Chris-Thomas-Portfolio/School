/************************************************************************
* Class: Array2D
*
*Purpose : This class is will create a 2D array.
*
* Manager functions :
*	Array2D();
*		Default C'tor
*	Array2D(int rows, int columns);
*		2 arg constructor
*	Array2D(const Array2D<T>& copy);
*		Copy constructor
*	Array2D& operator = (const Array2D<T>& rhs);
*		operator equals
*	~Array2D();
*		D'tor
* Methods:
* 	int getColumns() const;
*		Returns the value of m_columns.
*	int getRows() const;
*		Returns the value of m_rows.
*	void setColumns(int columns);
*		Sets the value of m_columns.
*	void setRows(int rows);
*		Sets the value of m_rows.
* 	Row<T> operator[](int row);
*		Subscript operator
*	Row<T> operator[](int row) const;
*		Const subscript operator
*	T& Select(int desired_row, int desired_column);
*		Select function that chooses desired row and column of Array2D.
*	T& Select(int desired_row, int desired_column)	const;
*		Const select function that chooses desired row and column of Array2D.
*************************************************************************/
#pragma once
#include "Array.h"
#include "Row.h"
template <typename T>

class Array2D
{
public:
	Array2D();
	Array2D(int rows, int columns);
	Array2D(const Array2D<T>& copy);
	Array2D& operator = (const Array2D<T>& rhs);
	~Array2D();
	int getColumns() const;
	int getRow() const;
	void setColumns(int columns);
	void setRows(int rows);
	Row<T> operator[](int row);
	Row<T> operator[](int row) const;
	T& Select(int desired_row, int desired_column);
	T& Select(int desired_row, int desired_column)	const;
private:
	Array<T> m_array;
	int m_rows;
	int m_columns;
};

/**********************************************************************
* Purpose: This is the default constructor for the Array2D class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Array2D.
*
************************************************************************/

template<typename T>
inline Array2D<T>::Array2D() : m_rows(0), m_columns(0)
{ }

/**********************************************************************
* Purpose: This is the 2 arg constructor for the Array2D class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a Array2D with given parameters.
*
************************************************************************/

template<typename T>
inline Array2D<T>::Array2D(int rows, int columns) : m_rows(rows), m_columns(columns)
{ 
	if (rows < 0)
		throw Exception("Cannot have negative rows");
	if (columns < 0)
		throw Exception("Cannot have negative columns");
	m_array.SetLength(rows * columns);
}

/**********************************************************************
* Purpose: This is the copy constructor for the Array2D class.
*
* Precondition:	An Array2D
*
* Postcondition: Creates a copy of Array2D.
*
************************************************************************/

template<typename T>
inline Array2D<T>::Array2D(const Array2D& copy) : m_array(copy.m_array), m_rows(copy.m_rows), m_columns(copy.m_columns)
{ }

/**********************************************************************
* Purpose: This is the op equals for the Array2D class.
*
* Precondition:	An Array2D.
*
* Postcondition: Creates a copy of Array2D on rhs.
*
************************************************************************/

template<typename T>
inline Array2D<T>& Array2D<T>::operator=(const Array2D& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_rows = rhs.m_rows;
		m_columns = rhs.m_columns;
	}
	return *this;
}

/**********************************************************************
* Purpose: This is the D'tor for the Array2D class.
*
* Precondition:	An Array2D.
*
* Postcondition: Destructs an Array2d object.
*
************************************************************************/

template<typename T>
inline Array2D<T>::~Array2D()
{
	m_rows = 0;
	m_columns = 0;
}

/**********************************************************************
* Purpose: This is returns the value of m_columns.
*
* Precondition : An Array2D.
*
* Postcondition : Returns m_columns.
*
************************************************************************/

template<typename T>
inline int Array2D<T>::getColumns() const
{
	return m_columns;
}

/**********************************************************************
* Purpose: This is returns the value of m_rows.
*
* Precondition : An Array2D.
*
* Postcondition : Returns m_rows.
*
************************************************************************/

template<typename T>
inline int Array2D<T>::getRow() const
{
	return m_rows;
}

/**********************************************************************
* Purpose: This is sets the value of m_columns.
*
* Precondition : An Array2D.
*
* Postcondition : Sets m_columns.
*
************************************************************************/

template<typename T>
inline void Array2D<T>::setColumns(int columns)
{
	if (columns < 0)										//make sure a valid value was entered
		throw Exception("Can not have negative columns");
	if (columns > m_columns)
	{
		Array2D temp = *this;								//create a temp Array2D

		m_array.SetLength(m_rows * columns);				//set m_array to larger length

		m_columns = columns;								//set m_columns to new value

		for (int i = 0; i < temp.m_rows; ++i)				//iterate through rows and columns and copy data over
		{
			for (int j = 0; j < temp.m_columns; ++j)
			{
				(*this)[i][j] = temp[i][j];
			}
		}
	}
	else
	{
		Array2D temp = *this;								//create a temp Array2D

		m_array.SetLength(m_rows * columns);				//set m_array to larger length

		m_columns = columns;								//set m_columns to new value

		for (int i = 0; i < m_rows; ++i)					//iterate through rows and columns and copy data over
		{
			for (int j = 0; j < m_columns; ++j)
			{
				(*this)[i][j] = temp[i][j];
			}
		}
	}
}

/**********************************************************************
* Purpose: This is sets the value of m_rows.
*
* Precondition : An Array2D.
*
* Postcondition : Returns m_rows.
*
************************************************************************/

template<typename T>
inline void Array2D<T>::setRows(int rows)
{
	if (rows < 0)
		throw Exception("Cannot set rows to a negative value");
	m_rows = rows;
	m_array.SetLength(m_rows * m_columns);
}

/**********************************************************************
* Purpose: This allows the consumer to use the subscript operator.
*
* Precondition : An Array2D.
*
* Postcondition : Returns a Row for specified operator.
*
************************************************************************/

template<typename T>
inline Row<T> Array2D<T>::operator[](int row)
{
	if (this < 0)
		throw Exception("Cannot find a negative row");
	return Row<T>(*this, row);
	
}

/**********************************************************************
* Purpose: This allows the consumer to use the subscript operator.
*
* Precondition : An Array2D.
*
* Postcondition : Returns a const Row for specified operator.
*
************************************************************************/

template<typename T>
inline Row<T> Array2D<T>::operator[](int row) const
{
	if (this < 0)
		throw Exception("Cannot find a negative row");
	return Row<T>(*this, row);
}

/**********************************************************************
* Purpose: This function finds the appropriate element based off of the
*			row and column.
*
* Precondition : An Array2D.
*
* Postcondition : Returns m_array at desired location.
*
************************************************************************/

template<typename T>
inline T& Array2D<T>::Select(int desired_row, int desired_column) 
{
	if (desired_row < 0 || desired_row > m_rows || desired_column < 0 || desired_column > m_columns)
		throw Exception("Invalid row or column value");
	return m_array[desired_row * m_columns + desired_column];
}

/**********************************************************************
* Purpose: This function finds the appropriate element based off of the
*			row and column.
*
* Precondition : An Array2D.
*
* Postcondition : Returns a const m_array at desired location.
*
************************************************************************/

template<typename T>
inline T& Array2D<T>::Select(int desired_row, int desired_column) const
{
	if (desired_row < 0 || desired_row > m_rows || desired_column < 0 || desired_column > m_columns)
		throw Exception("Invalid row or column value");
	return m_array[desired_row * m_columns + desired_column];
}
