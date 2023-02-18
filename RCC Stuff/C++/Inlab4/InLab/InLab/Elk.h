#ifndef ELK_H
#define ELK_H
#include "Mammal.h"

class Elk : public Mammal
{
public:
	 Elk();
	 Elk(int points);
	 ~Elk();
	 Elk & operator = (const Elk & rhs);
	 Elk(const Elk & copy);

	 void WhatAmI();

protected:
	int m_points;
};
#endif
