#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "String.h"
#include<cstring>
#include <ostream>
#include <fstream>
using std::fstream;
using std::ios;

/**********************************************************************
* Purpose: This function is the default constructor for the String class
*			it is called whenever a new instance of a String is created
*			and sets m_str to nullptr.
*
* Precondition:	N/A
*
* Postcondition: Creates an empty String.
*
************************************************************************/

String::String() : m_str(nullptr), m_length(0)
{ }

/**********************************************************************
* Purpose: This function is the one arg constructor for the String class
*			it sets the new String to what the argument was.
*
* Precondition:	N/A
*
* Postcondition: Creates a String that has the arg.
*
************************************************************************/

String::String(const char* str) : m_str(nullptr), m_length(0)

{
	if (str != nullptr)
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
		m_length = strlen(m_str);
	}
}

/**********************************************************************
* Purpose: This function makes a copy of a String.
*
* Precondition:	Need to have an existing String.
*
* Postcondition: You have a copy of specified String.
*
************************************************************************/

String::String(const String& copy) : m_str(nullptr), m_length(0)
{
	if (copy.m_str != nullptr)
	{
		m_str = new char[strlen(copy.m_str) + 1];
		strcpy(m_str, copy.m_str);
		m_length = strlen(m_str);
	}
}

/**********************************************************************
* Purpose: This function makes a moves the resources from one String to
*			another
*
* Precondition:	Need to have an existing String.
*
* Postcondition: You dont need to call the copy constructor for everything.
*
************************************************************************/

String::String(String&& copy) :m_str(nullptr), m_length(0)
{
	if (copy.m_str != nullptr)
	{
		delete[] m_str;
		m_str = copy.m_str;
		copy.m_str = nullptr;
		m_length = strlen(m_str);
	}
}

/**********************************************************************
* Purpose: This function lets you use the '=' operator to assign a String.
*
* Precondition:	N/A
*
* Postcondition: You create/set a String to what is on the rhs of the '='
*					operator.
*
************************************************************************/

String& String::operator = (const String& rhs)
{
	if (this != &rhs)									 //this is a pointer (1. check for self-assignment) 

		delete[] m_str;									 //2. Delete left-hand side
	if (rhs.m_str != nullptr)
	{
		m_str = new char[strlen(rhs.m_str) + 1];         //3. Perform Deep Copy
		strcpy(m_str, rhs.m_str);
		m_length = strlen(m_str);
	}
	else
		m_str = nullptr;

	return *this;										 //4. Return object as reference
}

/**********************************************************************
* Purpose: This function has the same functionality as the op = but without
*			so many function calls
*
* Precondition:	N/A
*
* Postcondition: You create/set a String to what is on the rhs of the '='
*					operator.
*
************************************************************************/

String& String::operator=(String&& rhs)
{
	if (this != &rhs)
	{
		delete[] m_str;
		m_str = rhs.m_str;
		rhs.m_str = nullptr;
	}

	return *this;
}

/**********************************************************************
* Purpose: This function deletes the String ones it goes out of scope or
*			is deleted.
*
* Precondition:	Need a String.
*
* Postcondition: You delete the String and set m_str back to nullptr.
*
************************************************************************/

String::~String()
{
	delete[] m_str;
	m_str = nullptr;
}

/**********************************************************************
* Purpose: This function returns the String.
*
* Precondition: Need a String
*
* Postcondition: The value of m_str gets returned.
*
************************************************************************/

const char* String::GetString() const
{
	return m_str;
}

/**********************************************************************
* Purpose: This function saves the information of the String to a binary file.
*
* Precondition: Need a String
*
* Postcondition: Binary file created with the information of the String.
*
************************************************************************/

void String::Save(ofstream& fout)
{
	fout.write(reinterpret_cast<char*>(&m_length), sizeof(m_length));
	fout.write(m_str, m_length + 1);
}

/**********************************************************************
* Purpose: This function loads the information of the binary file to a String.
*
* Precondition: Need a String
*
* Postcondition: String is created with the information of the Binary file.
*
************************************************************************/

void String::Load(ifstream& fout)
{
	fout.read(reinterpret_cast<char*>(&m_length), sizeof(m_length));
	m_str = new char[m_length + 1];
	fout.read(m_str, m_length + 1);
}

bool String::operator==(const String& obj) const
{
	return strcmp(m_str, obj.m_str) == 0 ? true : false;
}

bool String::operator==(const char* str) const
{
	return strcmp(m_str, str) == 0 ? true : false;
}

bool String::operator!=(const String& obj) const
{
	return strcmp(m_str, obj.m_str) != 0 ? true : false;
}

bool String::operator!=(const char* str) const
{
	return strcmp(m_str, str) != 0 ? true : false;
}

bool String::operator<=(const String& obj) const
{
	return strcmp(m_str, obj.m_str) <= 0 ? true : false;
}

bool String::operator<=(const char* str) const
{
	return strcmp(m_str, str) <= 0 ? true : false;
}

ostream& operator<<(ostream& os, const String& rhs)
{
	os << rhs.m_str;

	return os;
}

istream& operator>>(istream& input, String& rhs)
{
	char* temp;
	temp = new char[400];
	input.getline(temp, 400);

	rhs = String(temp);

	return input;
}