#include "CharCreation.h"
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

CharCreation::CharCreation() : m_armor(), m_hitpoints(), m_damage()
{ }

CharCreation::CharCreation(int armor, int hitpoints, int damage) : m_armor(armor), m_hitpoints(hitpoints), m_damage(damage)
{ }

CharCreation::CharCreation(const CharCreation& copy) : m_armor(copy.m_armor), m_hitpoints(copy.m_hitpoints), m_damage(copy.m_damage)
{ }

CharCreation& CharCreation::operator=(const CharCreation& rhs)
{
	if (this != &rhs)
	{
		m_armor = rhs.m_armor;
		m_hitpoints = rhs.m_hitpoints;
		m_damage = rhs.m_damage;
	}

	return *this;
}

CharCreation::~CharCreation()
{ }

int CharCreation::GetArmor()
{
	return m_armor;
}

int CharCreation::GetHitPoints()
{
	return m_hitpoints;
}

int CharCreation::GetDamage()
{
	return m_damage;
}

void CharCreation::WhatAmI()
{
	cout << "I am nothing" << endl;
}

void CharCreation::Special()
{
	cout << "I am not special" << endl;
}

void CharCreation::SetArmor(int armor)
{
	m_armor = armor;
}

void CharCreation::SetHitPoints(int hp)
{
	m_hitpoints = hp;
}

void CharCreation::SetDamage(int damage)
{
	m_damage = damage;
}

void CharCreation::Display() const
{
	cout << " Hitpoints: " << m_hitpoints << endl;
	cout << " Armor: " << m_armor << endl;
	cout << " Attack: " << m_damage << endl;
	cout << endl;
}
