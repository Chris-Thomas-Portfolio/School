#pragma once
#include "CharCreation.h"
class Troll :
	public CharCreation
{
public:
	Troll();
	Troll(String name);
	Troll(const Troll& copy);
	Troll& operator = (const Troll& rhs);
	~Troll();
	void WhatAmI();
	void Special();
	void Display() const;
private:
	String m_name;
};

