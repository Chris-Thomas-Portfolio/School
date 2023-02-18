#include <iostream>
using std::cout;
using std::endl;
#include "Animal.h"

Animal::Animal(string species) : m_species("")
{
	cout << "Animal One Arg Ctor" << endl;
}

Animal::~Animal()
{
	cout << "Animal Dtor" << endl;
}

void Animal::WhatAmI()
{
	cout << "I am an Animal" << endl;
}
