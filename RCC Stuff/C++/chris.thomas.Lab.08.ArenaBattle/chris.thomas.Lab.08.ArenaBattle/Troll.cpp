#include "Troll.h"
#include <iostream>
using std::cout;
using std::endl;
#include <ctime>

Troll::Troll() : m_name("Gublok")
{ 
	m_armor = (int)(1 + rand() % 10);
	m_hitpoints = (int)(1 + rand() % 10);
	m_damage = (int)(1 + rand() % 10);
}

Troll::Troll(String name) : m_name(name)
{ 
	m_armor = (int)(1 + rand() % 10);
	m_hitpoints = (int)(1 + rand() % 10);
	m_damage = (int)(1 + rand() % 10);
}

Troll::Troll(const Troll& copy) : m_name(copy.m_name)
{ }

Troll& Troll::operator=(const Troll& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
	}

	return *this;
}

Troll::~Troll()
{ }

void Troll::WhatAmI()
{
	cout << "Troll" << endl;
}

void Troll::Special()
{
	cout << "Troll Regeneration" << endl;
	m_hitpoints = m_hitpoints + 3;
}

void Troll::Display() const
{
	cout << "Hitpoints: " << m_hitpoints << endl;
	cout << "Armor: " << m_armor << endl;
	cout << endl;	
}
