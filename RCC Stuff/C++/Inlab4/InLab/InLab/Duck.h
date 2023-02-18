#pragma once
#include "Bird.h"
class Duck : public Bird
{
public:
	Duck();
	~Duck();
	Duck(string sp);
	Duck& operator = (const Duck& rhs);
	Duck(const Duck& copy);

	void WhatAmI();

private:
};

