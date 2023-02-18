#pragma once
#include "String.h"
class CharCreation
{
public:
	CharCreation();
	CharCreation(int armor, int hitpoints, int damage);
	CharCreation(const CharCreation& copy);
	CharCreation& operator = (const CharCreation& rhs);
	~CharCreation();
	int GetArmor();
	int GetHitPoints();
	int GetDamage();
	virtual void WhatAmI() = 0;
	virtual void Special();
	void SetArmor(int armor);
	void SetHitPoints(int hp);
	void SetDamage(int damage);
	virtual void Display() const;
protected:
	int m_armor;
	int m_hitpoints;
	int m_damage;
};

