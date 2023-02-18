#ifndef MAMMAL_H
#define MAMMAL_H

#include <string>
using std::string;
#include "Animal.h"

class Mammal : public Animal
{
public:
	 Mammal();
	 Mammal(string sp);
	 virtual ~Mammal();
	 Mammal & operator = (const Mammal & rhs);
	 Mammal(const Mammal & copy);

	void WhatAmI();

protected:
};
#endif
