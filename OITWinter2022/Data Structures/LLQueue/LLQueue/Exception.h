/*************************************************************
* Author: Chris Thomas
* Filename: Exception.h
* Date Created: 1/19/2022 9:35 AM
* Modifications: N/A
**************************************************************/
/************************************************************************
* Class: Exception
*
* Purpose: This class is used to handle exceptions in Array
*
* Manager functions:
* 	Exception();
*		Gives the default of m_msg(nullptr)
*	~Exception();
*	Exception(const char* msg);
*		Creates an exception with given message.
*	Exception(const Exception& copy);
*	Exception(Exception&& copy);
*	Exception& operator=(const Exception& rhs);
*	Exception& operator=(Exception&& rhs);
*
* Methods:
* const char * GetMessage();
*	void SetMessage(const char* msg);
*		Sets the message of exception.
*	friend ostream& operator << (ostream& stream, const Exception& in);
*************************************************************************/
#pragma once
#include <iostream>
using std::ostream;
using std::endl;
using std::cout;
class Exception
{
public:
	Exception();
	~Exception();
	Exception(const char* msg);
	Exception(const Exception& copy);
	Exception(Exception&& copy) noexcept;
	Exception& operator=(const Exception& rhs);
	Exception& operator=(Exception&& rhs) noexcept;
	const char* getMessage();
	void SetMessage(const char* msg);
	friend ostream& operator << (ostream& stream, const Exception& in);
private:
	char* m_msg;
};

