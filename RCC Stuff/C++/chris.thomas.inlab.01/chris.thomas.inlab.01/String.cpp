#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "String.h"
#include<cstring>

String::String() : m_str(nullptr)
{ }


String::String(const char* str) : m_str(nullptr)

{
	if (str != nullptr)
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
}

String::String(const String& copy) : m_str(nullptr)
{
	if (copy.m_str != nullptr)
	{
		m_str = new char[strlen(copy.m_str) + 1];
		strcpy(m_str, copy.m_str);
	}
}

String& String::operator = (const String& rhs)
{
	if (this != &rhs)									 //this is a pointer (1. check for self-assignment) 

		delete[] m_str;									 //2. Delete left-hand side
	if (rhs.m_str != nullptr)
	{
		m_str = new char[strlen(rhs.m_str) + 1];         //3. Perform Deep Copy
		strcpy(m_str, rhs.m_str);
	}
	else
		m_str = nullptr;

	return *this;										 //4. Return object as reference
}

String::~String()
{
	delete[] m_str;
	m_str = nullptr;
}

const char * String::GetString() const
{
	return m_str;
}