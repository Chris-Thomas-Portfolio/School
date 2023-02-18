/*************************************************************
* Author: Chris Thomas
* Filename: Array2D.h
* Date Created: 1/12/2022 6:41 PM
* Modifications: N/A
**************************************************************/

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
* 	Array2D(Array2D<T>&& copy);
*		Move copy constructor
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
* 	Array2D& operator = (const Array2D<T>& rhs);
*		Copy constructor
	Array2D& operator = (Array2D<T>&& rhs);
		Move copy constructor
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
#include "Exception.h"
#include "Row.h"

template<typename T>

class Array2D
{
public:
	Array2D();
	Array2D(int rows, int columns);
	Array2D(const Array2D<T>& copy);
	Array2D(Array2D<T>&& copy);
	~Array2D();
	Array2D& operator = (const Array2D<T>& rhs);
	Array2D& operator = (Array2D<T>&& rhs);
	int getRow() const;
	int getColumns() const;
	void setColumns(int columns);
	void setRows(int rows);
	Row<T> operator[](int row);
	Row<T> operator[](int row) const;
	T& Select(int desired_row, int desired_column);
	T& Select(int desired_row, int desired_column)	const;
private:
	T** m_array;
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
inline Array2D<T>::Array2D() : m_array(nullptr), m_rows(0), m_columns(0)
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
inline Array2D<T>::Array2D(int rows, int columns)
{
	if (rows < 0)												//throw exception if negative value was entered for rows/columns
		throw Exception("Can't have a negative row size");
	if (columns < 0)
		throw Exception("Can't have a negative column size");

	m_array = new T * [rows];									//create a new set of rows in m_array

	for (int i = 0; i < rows; ++i)
	{
		m_array[i] = new T[columns];							//add new columns for each row

		for (int j = 0; j < columns; ++j)						//fill the columns with T() data type.
		{
			m_array[i][j] = T();
		}
	}
	m_rows = rows;												//set m_rows and m_columns to appropriate values
	m_columns = columns;
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
inline Array2D<T>::Array2D(const Array2D<T>& copy)
{
	m_array = new T * [copy.m_rows];							//create new rows the size of copy

	for (int i = 0; i < copy.m_rows; ++i)
	{
		m_array[i] = new T[copy.m_columns];						//create new columns the size of copy and plug into rows

		for (int j = 0; j < copy.m_columns; ++j)
		{
			m_array[i][j] = copy.m_array[i][j];					//copy all data from rows and columns into m_array
		}
	}
	m_rows = copy.m_rows;										//set m_rows and m_columns to appropriate values.
	m_columns = copy.m_columns;
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
inline Array2D<T>::Array2D(Array2D<T>&& copy) : m_array(copy.m_array), m_rows(copy.m_rows), m_columns(copy.m_columns)
{ }

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
	if (m_array != nullptr)
	{
		for (int i = 0; i < m_rows; ++i)			//iterate through each row and delete
		{
			delete[] m_array[i];
		}

		delete[] m_array;							//delete entire m_array and set to nullptr
		m_array = nullptr;
	}
}

/**********************************************************************
* Purpose: This is the op equals for the Array2D class.
*
* Precondition:	An Array2D.
*
* Postcondition: Creates a copy of Array2D on rhs.
*
************************************************************************/

template<typename T>
inline Array2D<T>& Array2D<T>::operator=(const Array2D<T>& rhs)
{
	if (this != &rhs)								//check for self assignment
	{
		for (int i = 0; i < m_rows; ++i)			//iterate through each row and delete
		{
			delete[] m_array[i];
		}
			
		delete[] m_array;							//delete entire m_array

		m_array = new T * [rhs.m_rows];

		for (int i = 0; i < rhs.m_rows; ++i)
		{
			m_array[i] = new T[rhs.m_columns];		//fill each row with columns
		}

		for (int i = 0; i < rhs.m_rows; ++i)
		{
			for (int j = 0; j < rhs.m_columns; ++j)
			{
				m_array[i][j] = rhs.m_array[i][j];		//copy the data from rhs into m_array
			}
		}

		m_rows = rhs.m_rows;							//set m_rows and m_columns to appropriate values
		m_columns = rhs.m_columns;
	}

	return *this;
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
inline Array2D<T>& Array2D<T>::operator=(Array2D<T>&& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
	}

	return *this;
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
	if (columns < 0)
		throw Exception("Can't have a negative column size");
	
	int tempcolumns = m_columns;					//set temp int for deletion of temp later.
	T** temp = new T * [m_rows];					//create temp for holding of data
	if (m_columns < columns)						//check if we are increasing or decreasing size
	{
		for (int i = 0; i < m_rows; ++i)
		{
			temp[i] = new T[m_columns];				//create columns for temp

			for (int j = 0; j < m_columns; ++j)
			{
				temp[i][j] = m_array[i][j];			//copy data from m_array into temp for storage
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] m_array[i];					//iterate through each row and delete
		}

		delete[] m_array;							//delete entire m_array
		m_columns = columns;						//set m_columns to new value
		m_array = new T * [m_rows];					//create new rows for m_array

		for (int i = 0; i < m_rows; ++i)
		{
			m_array[i] = new T[m_columns];			//fill rows with new columns
		}

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < tempcolumns; ++j)
			{
				m_array[i][j] = temp[i][j];			//copy the data from temp into m_array
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] temp[i];						//iterate through and delete temp rows
		}
		delete[] temp;								//delete entire temp
	}
	else
	{
		for (int i = 0; i < m_rows; ++i)			
		{
			temp[i] = new T[m_columns];				//create columns for temp

			for (int j = 0; j < m_columns; ++j)
			{
				temp[i][j] = m_array[i][j];			//copy data from m_array into temp for storage
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] m_array[i];					//iterate through each row and delete
		}

		delete[] m_array;							//delete entire m_array
		m_columns = columns;						//set m_columns to new value
		m_array = new T * [m_rows];					//create new rows for m_array

		for (int i = 0; i < m_rows; ++i)
		{
			m_array[i] = new T[m_columns];			//fill rows with new columns
		}

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_array[i][j] = temp[i][j];			//copy data from temp into m_array
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] temp[i];						//iterate through and delete temp rows
		}
		delete[] temp;								//delete entire temp
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
		throw Exception("Can't have a negative row size");

	int temprows = m_rows;							//create temp int for later deletion of temp
	T** temp = new T * [m_rows];					//create a temp to hold m_array data
	if (m_rows < rows)								//check to see if we are increasing or decreasing size
	{
		for (int i = 0; i < m_rows; ++i)
		{
			temp[i] = new T[m_columns];				//fill temp rows with new columns

			for (int j = 0; j < m_columns; ++j)
			{
				temp[i][j] = m_array[i][j];			//copy data over from m_array into temp
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] m_array[i];					//iterate through and delete m_array rows
		}

		delete[] m_array;							//delete entire m_array
		m_rows = rows;								//set m_rows to new value
		m_array = new T * [m_rows];					//make new rows to new size

		for (int i = 0; i < m_rows; ++i)
		{
			m_array[i] = new T[m_columns];			//fill m_array rows with new columns
		}

		for (int i = 0; i < temprows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_array[i][j] = temp[i][j];			//copy over data from tempm to m_array
			}
		}

		for (int i = 0; i < temprows; ++i)
		{
			delete[] temp[i];						//iterate through and delete temp rows
		}
		delete[] temp;								//delete entire temp
	}
	else
	{
		for (int i = 0; i < m_rows; ++i)
		{
			temp[i] = new T[m_columns];				//fill temp with new columns

			for (int j = 0; j < m_columns; ++j)
			{
				temp[i][j] = m_array[i][j];			//copy data from m_array into temp
			}
		}

		for (int i = 0; i < m_rows; ++i)
		{
			delete[] m_array[i];					//iterate through and delete m_array rows
		}

		delete[] m_array;							//delete entire m_array
		m_rows = rows;								//set m_rows to new value
		m_array = new T * [m_rows];					//create number of new value rows in m_array 

		for (int i = 0; i < m_rows; ++i)
		{
			m_array[i] = new T[m_columns];			//fill rows with new columns
		}

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_array[i][j] = temp[i][j];			//copy data from temp into m_array
			}
		}

		for (int i = 0; i < temprows; ++i)
		{
			delete[] temp[i];						//iterate through and delete temp rows
		}	
		delete[] temp;								//delete temp
	}
}

template<typename T>
inline Row<T> Array2D<T>::operator[](int row)
{
	if (this < 0)
		throw Exception("Cannot find a negative row");
	return Row<T>(*this, row);
}

template<typename T>
inline Row<T> Array2D<T>::operator[](int row) const
{
	if (this < 0)
		throw Exception("Cannot find a negative row");
	return Row<T>(*this, row);
}

template<typename T>
inline T& Array2D<T>::Select(int desired_row, int desired_column)
{
	if (desired_row < 0 || desired_row > m_rows || desired_column < 0 || desired_column > m_columns)
		throw Exception("Invalid row or column value");
	return m_array[desired_row][desired_column];
}

template<typename T>
inline T& Array2D<T>::Select(int desired_row, int desired_column) const
{
	if (desired_row < 0 || desired_row > m_rows || desired_column < 0 || desired_column > m_columns)
		throw Exception("Invalid row or column value");
	return m_array[desired_row][desired_column];
}
