#include "Exception.h"

/**********************************************************************
* Purpose: C'tor
*
* Precondition:
*     N/A
*
* Postcondition:
*      Creates a default exception with m_msg(nullptr)
*
************************************************************************/

Exception::Exception() : m_msg(nullptr)
{
}

/**********************************************************************
* Purpose: D'tor
*
* Precondition:
*     N/A
*
* Postcondition:
*      Gets rid of exception that is no longer needed.
*
************************************************************************/

Exception::~Exception()
{
	delete m_msg;
	m_msg = nullptr;
}

/**********************************************************************
* Purpose: 1 Arg C'tor
*
* Precondition:
*     N/A
*
* Postcondition:
*      Creates a exception with m_msg of given char *
*
************************************************************************/

Exception::Exception(const char* msg)
{
	int length = strlen(msg) + 1;
	m_msg = new char[length];
	strcpy_s(m_msg, length, msg);
	cout << msg << endl;
}

/**********************************************************************
* Purpose: Copy Constructor
*
* Precondition:
*     Need an exception to copy.
*
* Postcondition:
*      Copies an exception.
*
************************************************************************/

Exception::Exception(const Exception& copy)
{
	int length = strlen(copy.m_msg) + 1;
	m_msg = new char[length];
	strcpy_s(m_msg, length, copy.m_msg);
}

/**********************************************************************
* Purpose: Move Constructor
*
* Precondition:
*     Need an exception to move.
*
* Postcondition:
*      Moves an exception.
*
************************************************************************/

Exception::Exception(Exception&& copy) noexcept
{
	int length = strlen(copy.m_msg) + 1;
	m_msg = new char[length];
	strcpy_s(m_msg, length, copy.m_msg);
}

/**********************************************************************
* Purpose: Op =
*
* Precondition:
*     Need an exception to set the lhs to.
*
* Postcondition:
*      Exception on lhs has values of rhs.
*
************************************************************************/

Exception& Exception::operator=(const Exception& rhs)
{
	if (this != &rhs)
	{
		int length = strlen(rhs.m_msg) + 1;
		m_msg = new char[length];
		strcpy_s(m_msg, length, rhs.m_msg);
	}

	return *this;
}

/**********************************************************************
* Purpose: Move Op =
*
* Precondition:
*     Need an exception to set the lhs to.
*
* Postcondition:
*      Exception on lhs has values of rhs.
*
************************************************************************/

Exception& Exception::operator=(Exception&& rhs) noexcept
{
	if (this != &rhs)
	{
		int length = strlen(rhs.m_msg) + 1;
		m_msg = new char[length];
		strcpy_s(m_msg, length, rhs.m_msg);
	}

	return *this;
}

/**********************************************************************
* Purpose: Get message
*
* Precondition:
*     Need an exception.
*
* Postcondition:
*      Return m_msg.
*
************************************************************************/

const char* Exception::getMessage()
{
	return m_msg;
}

/**********************************************************************
* Purpose: Set message.
*
* Precondition:
*     Need an exception to set the message for.
*
* Postcondition:
*      Set m_msg to char* given.
*
************************************************************************/

void Exception::SetMessage(const char* msg)
{
	int length = strlen(msg) + 1;
	m_msg = new char[length];
	strcpy_s(m_msg, length, msg);
}

/**********************************************************************
* Purpose: Op <<
*
* Precondition:
*     Exception
*
* Postcondition:
*      returns stream for output to console.
*
************************************************************************/

ostream& operator<<(ostream& stream, const Exception& in)
{
	stream << in.m_msg;
	return stream;
}