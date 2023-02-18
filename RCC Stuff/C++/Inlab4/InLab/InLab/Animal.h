#pragma once
#include <string>
using std::string;

class Animal
{
public:
	Animal(string species);
	~Animal();

	virtual void WhatAmI() = 0;
protected:
	string m_species;
};