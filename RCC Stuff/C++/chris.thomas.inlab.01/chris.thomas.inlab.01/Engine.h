#pragma once
#include "String.h"

class Engine {
public:
	Engine();
	Engine(int cyl, const char * manf);
	Engine(const Engine& copy);
	Engine& operator =(const Engine& rhs);
	~Engine();
	void setCyl(int cyl);
	int getCyl();
	void setManf(String *manf);
	String getManf();
	void Display() const;
private:
	int m_cyl;
	String m_manf;
};