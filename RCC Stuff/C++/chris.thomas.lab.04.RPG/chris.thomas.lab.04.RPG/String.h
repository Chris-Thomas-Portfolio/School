#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
using std::ofstream;
using std::ifstream;

#ifndef STRING_H
#define STRING_H

/************************************************************************
* Class: String
*
* Purpose: This class is designed to replace the standard string class.
*
* Manager functions:
* 	String ( )
* 		The default of the String is nullptr
*	String (const char * str)
*		Creates a char array the appropriate size for the string entered
*	operator = (const String & copy)
*	~String()
*	const char* GetString() const;
*
*************************************************************************/

class String
{
public:
	String();
	String(const char* str);
	String(const String& copy);
	String(String&& copy);
	String& operator = (const String& rhs);
	String& operator = (String&& rhs);
	~String();
	const char* GetString() const;
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	char* m_str;
	int m_length = 0;
};
#endif