#pragma once

#include <iostream>
#include <cstring>

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
*		Creates a char array the appropriate size for the string entered.
*	String (const Array & copy)
*	operator = (const String & copy)
*	~Array()
*	const char* GetString() const;
*
*************************************************************************/

class String
{
public:
	String();                                      
	String(const char* str);                        
	String(const String& copy); 					
	String& operator = (const String& rhs);
	~String();                                      
	const char* GetString() const;
private:
	char* m_str;
};
#endif
