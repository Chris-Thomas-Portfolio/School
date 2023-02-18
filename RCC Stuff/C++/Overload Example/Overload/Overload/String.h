#pragma once
#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class String
{
public:
	String();
	String(char str);
	String(const char* str);
	String(const String& copy);
	String(String&& copy);
	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	const char* GetStr() const;
	bool operator ==(const String& obj) const;
	bool operator ==(const char* str) const;
	bool operator !=(const String& obj) const;
	bool operator !=(const char* str) const;
	bool operator <(const String& obj) const;
	bool operator <(const char* str) const;
	bool operator <=(const String& obj) const;
	bool operator <=(const char* str) const;
	bool operator >(const String& obj) const;
	bool operator >(const char* str) const;
	bool operator >=(const String& obj) const;
	bool operator >=(const char* str) const;
	char operator [](int i);
	String operator +(const String& rhs);
	String& operator +=(const String& rhs);
	String& operator ++();
	String& operator ++(int notUsed);
	String& operator --();
	String& operator --(int notUsed);
	friend ostream& operator << (ostream& os, const String& rhs);
	friend istream& operator >> (istream& input, String& rhs);
	~String();
private:
	char* m_str;
	int m_length = 0;

};