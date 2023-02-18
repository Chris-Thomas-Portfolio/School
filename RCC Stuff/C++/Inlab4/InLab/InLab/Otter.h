#pragma once
#include "Elk.h"
class Otter : public Mammal
{
public:
	Otter();
	Otter(bool m_sea);
	~Otter();
	Otter& operator = (const Otter& rhs);
	Otter(const Otter& copy);

	void WhatAmI();

private:
	bool m_sea;
};

