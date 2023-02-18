#include <iostream>
using std::cout;
using std::endl;
#include "Duck.h"

Duck::Duck() : Bird("Duck")
{ 
	cout << "Duck Ctor" << endl;
}

Duck::~Duck()
{
	cout << "Duck Dtor" << endl;
}

Duck::Duck(string sp) : Bird(sp)
{
	cout << "Duck One Arg Ctor" << endl;
}

Duck& Duck::operator=(const Duck& rhs)
{
	cout << "Duck op =" << endl;
	if (this != &rhs)
	{
		m_species = rhs.m_species;
	}
	return *this;
}

Duck::Duck(const Duck& copy) : Bird(copy.m_species)
{
	cout << "Bird Copy Ctor" << endl;
}

void Duck::WhatAmI()
{
	cout << "I am a Duck" << endl;
}
