#pragma once
class String
{
public:
	String();
	String(char a);
	String(const char* b);
	String(const String& copy);
	String(String&& copy);
	String& operator=(const String& rhs);
	String& operator = (const String&& rhs);
	String& operator < (const String& rhs);
	String& operator > (const String& rhs);
	String& operator <= (const String& rhs);
	String& operator >= (const String& rhs);
	String& operator == (const String& rhs);
	String& operator != (const String& rhs);
	String& operator << (const String& rhs);
	String& operator + (const String& rhs);
	String& operator += (const String& rhs);
	String& operator ++ (int a);
	String& operator -- (int a);
	int GetLength(String str);
	const char* GetStr() const;
private:
	char* m_str;
	int m_length = 0;
};

