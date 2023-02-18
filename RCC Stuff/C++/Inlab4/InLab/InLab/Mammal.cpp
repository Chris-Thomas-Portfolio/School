#include <iostream>
using std::cout;
using std::endl;
#include "Mammal.h"

Mammal::Mammal() : Animal ("Mammal")
{
	cout << "Mammal Default Ctor" << endl;
}
Mammal::Mammal(string sp) : Animal(sp)
{
	cout << "Mammal One Arg Ctor" << endl;
}
Mammal::~Mammal()
{
	cout << "Mammal Dtor" << endl;
}
Mammal & Mammal::operator = (const Mammal & rhs)
{
	cout << "Mammal op =" << endl;
	if(this != &rhs)
	{
		m_species = rhs.m_species;
	}
	return *this;
}
Mammal::Mammal(const Mammal & copy) : Animal(copy.m_species)
{
	cout << "Mammal Copy Ctor" << endl;
}

void Mammal::WhatAmI()
{
	cout << "I am a Mammal" << endl;
}
