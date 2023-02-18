#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
	Bird();
	~Bird();
	Bird(string sp);
	Bird& operator = (const Bird& rhs);
	Bird(const Bird& copy);

	void WhatAmI();

private:
};