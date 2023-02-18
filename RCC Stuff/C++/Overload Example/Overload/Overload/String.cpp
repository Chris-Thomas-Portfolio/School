#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "crtdbg.h"
#include "String.h"

using std::cout;
using std::endl;

const int INDEX_OUT_OF_BOUNDS = -1;

String::String() :m_str(nullptr)
{
	cout << "Default Ctor" << endl;
}

String::String(char m) : m_str(nullptr)
{
	char str[2];
	str[0] = m;
	str[1] = '\0';
	m_str = str;
}

String::String(const char* str) :m_str(nullptr)
{
	if (str != nullptr)
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
}

String::String(const String& copy) :m_str(nullptr)
{
	cout << "Copy Ctor" << endl;
	if (copy.m_str != nullptr)
	{
		m_str = new char[strlen(copy.m_str) + 1];
		strcpy(m_str, copy.m_str);
	}
}

String::String(String&& copy) :m_str(nullptr)
{
	if (copy.m_str != nullptr)
	{
		delete[] m_str;
		m_str = copy.m_str;
		copy.m_str = nullptr;
	}
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{

		delete[] m_str;
		if (rhs.m_str != nullptr)
		{
			m_str = new char[strlen(rhs.m_str) + 1];
			strcpy(m_str, rhs.m_str);
		}
		else
			m_str = nullptr;
	}
	return *this;
}

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

const char* String::GetStr() const
{
	return m_str;
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

bool String::operator<(const String& obj) const
{
	return strcmp(m_str, obj.m_str) < 0 ? true : false;
}

bool String::operator<(const char* str) const
{
	return strcmp(m_str, str) < 0 ? true : false;
}

bool String::operator<=(const String& obj) const
{
	return strcmp(m_str, obj.m_str) <= 0 ? true : false;
}

bool String::operator<=(const char* str) const
{
	return strcmp(m_str, str) <= 0 ? true : false;
}

bool String::operator>(const String& obj) const
{
	return strcmp(m_str, obj.m_str) > 0 ? true : false;
}

bool String::operator>(const char* str) const
{
	return strcmp(m_str, str) > 0 ? true : false;
}

bool String::operator>=(const String& obj) const
{
	return strcmp(m_str, obj.m_str) >= 0 ? true : false;
}

bool String::operator>=(const char* str) const
{
	return strcmp(m_str, str) >= 0 ? true : false;
}

char String::operator[](int i)
{
	if (i >= m_length)
	{
		throw(INDEX_OUT_OF_BOUNDS);
	}
	return m_str[i];
}

String String::operator+(const String& rhs)
{
	cout << "Concatenate" << endl;
	char* temp = new char[strlen(m_str) + strlen(rhs.m_str) + 1];
	strcpy(temp, m_str);
	strcat(temp, rhs.m_str);
	String str(temp);
	return str;
}

String& String::operator+=(const String& rhs)
{
	char* temp = new char[strlen(m_str) + strlen(rhs.m_str) + 1];
	strcpy(temp, m_str);
	strcat(temp, rhs.m_str);
	delete[] m_str;
	m_str = temp;
	m_length = strlen(m_str);
	return *this;
}

String& String::operator++()
{
	_strupr(m_str);
	return *this;
}

String& String::operator++(int notUsed)
{
	String temp(*this);
	_strupr(m_str);
	return temp;
}

String& String::operator--()
{
	_strlwr(m_str);
	return *this;
}

String& String::operator--(int notUsed)
{
	String temp(*this);
	_strlwr(m_str);
	return temp;
}

String::~String()
{
	delete[] m_str;
	m_str = nullptr;
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