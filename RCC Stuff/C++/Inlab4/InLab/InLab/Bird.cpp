#include <iostream>
using std::cout;
using std::endl;
#include "Bird.h"

Bird::Bird() : Animal("Bird")
{ 
	cout << "Bird Ctor" << endl;
}

Bird::~Bird()
{ 
	cout << "Bird Dtor" << endl;
}

Bird::Bird(string sp) : Animal(sp)
{ 
	cout << "Bird One Arg Ctor" << endl;
}

Bird& Bird::operator=(const Bird& rhs)
{
	cout << "Bird op =" << endl;
	if (this != &rhs)
	{
		m_species = rhs.m_species;
	}
	return *this;
}

Bird::Bird(const Bird& copy) : Animal(copy.m_species)
{ 
	cout << "Bird Copy Ctor" << endl;
}

void Bird::WhatAmI()
{
	cout << "I am a Bird" << endl;
}
