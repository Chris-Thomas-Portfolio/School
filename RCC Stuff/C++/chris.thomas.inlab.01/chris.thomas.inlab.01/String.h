#pragma once

#include <iostream>
#include <cstring>

#ifndef STRING_H
#define STRING_H

class String
{
public:
	String();                                       //default constructor
	String(const char* str);                        //1arg constructor
	String(const String& copy); 					//cpy constructor
	String& operator = (const String& rhs);
	~String();                                      //destructor
	const char * GetString() const;
private:
	char* m_str;
};
#endif
