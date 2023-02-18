#include <iostream>
using std::cout;
using std::endl;
#include "Otter.h"

Otter::Otter() : Mammal("Otter"), m_sea()
{ 
	cout << "Otter Default Ctor" << endl;
}

Otter::Otter(bool m_sea) : Mammal("Otter"), m_sea(m_sea)
{ 
	cout << "Otter One Arg Ctor" << endl;
}

Otter::~Otter()
{ 
	cout << "Otter Dtor" << endl;
}

Otter& Otter::operator=(const Otter& rhs)
{
	cout << "Otter op =" << endl;
	if (this != &rhs)
	{
		m_species = rhs.m_species;
		m_sea = rhs.m_sea;
	}
	return *this;
}

Otter::Otter(const Otter& copy) : Mammal(copy.m_species)
{ 
	cout << "Otter Copy Ctor" << endl;
}

void Otter::WhatAmI()
{
	cout << "I am an Otter" << endl;
}
