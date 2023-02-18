#include <iostream>
using std::cout;
using std::endl;
#include "Elk.h"

Elk::Elk() :  Mammal("Elk"), m_points(0)
{
	cout << "Elk Default Ctor" << endl;
}
Elk::Elk(int points) :  Mammal("Elk"), m_points(points)
{
	cout << "Elk One Arg Ctor" << endl;
}
Elk::~Elk()
{
	cout << "Elk Dtor" << endl;
}
Elk & Elk::operator = (const Elk & rhs)
{
	cout << "Elk op =" << endl;
	if(this != &rhs)
	{
		m_species = rhs.m_species;
		m_points = rhs.m_points;
	}
	return *this;
}
Elk::Elk(const Elk & copy) : Mammal(copy.m_species)
{
	cout << "Elk Copy Ctor" << endl;
}

void Elk::WhatAmI()
{
	cout << "I am an Elk" << endl;
}
