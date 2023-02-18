#include "String.h"
#include <iostream>
#include <string>

String::String() : m_str(nullptr), m_length()
{ }

String::String(char a) : m_str(nullptr)
{ 
	m_length = strlen(m_str);
}

String::String(const char* b) : m_str(nullptr)
{
	if (b != nullptr)
	{
		m_str = new char[strlen(b) + 1];
		strcpy(m_str, b);
		m_length = strlen(m_str);
	}
}

String::String(const String& copy)
{ 
	if (copy.m_str != nullptr)
	{
		m_str = new char[strlen(copy.m_str) + 1];
		strcpy(m_str, copy.m_str);
		m_length = strlen(copy.m_str);
	}
}

String::String(String&& copy)
{
	m_str = copy.m_str;
	copy.m_str = nullptr;
	m_length = strlen(m_str);
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] m_str;
	}
	if (rhs.m_str != nullptr)
	{
		m_str = new char[strlen(rhs.m_str) + 1];
		strcpy(m_str, rhs.m_str);
		m_length = strlen(m_str);
	}
	else
		m_str = nullptr;

	return *this;
}

String& String::operator=(const String&& rhs)
{
	if (this != &rhs)
	{
		delete[] m_str;
		m_str = rhs.m_str;
	}
	return *this;
}

String& String::operator<(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator>(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator<=(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator>=(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator==(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator!=(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator<<(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator+(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator+=(const String& rhs)
{
	// TODO: insert return statement here
}

String& String::operator++(int a)
{
	// TODO: insert return statement here
}

String& String::operator--(int a)
{
	// TODO: insert return statement here
}

int String::GetLength(String str) 
{
	return m_length = strlen(str.m_str);
}

const char* String::GetStr() const
{
	return m_str;
}
