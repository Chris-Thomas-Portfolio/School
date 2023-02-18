#define _CRT_SECURE_NO_WARNINGS
#include "Potion.h"
#include <cstring>

Potion::Potion() : m_name(), m_description(), m_potency(), m_cost()
{ }

Potion::Potion(String name, String description, String potency, String cost) : m_name(name), m_description(description), m_potency(potency), m_cost(cost)
{ }

Potion::Potion(const Potion& copy) : m_name(copy.m_name), m_description(copy.m_description), m_potency(copy.m_potency), m_cost(copy.m_cost)
{ }

Potion& Potion::operator=(const Potion& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_description = rhs.m_description;
		m_potency = rhs.m_potency;
		m_cost = rhs.m_cost;
	}

	return *this;
}

Potion::~Potion()
{ }

String Potion::getName()
{
	return m_name;
}

void Potion::setName(String name)
{
	m_name = name;
}

String Potion::getDescription()
{
	return m_description;
}

void Potion::setDescription(String description)
{
	m_description = description;
}

String Potion::getPotency()
{
	return m_potency;
}

void Potion::setPotency(String potency)
{
	m_potency = potency;
}

String Potion::getCost()
{
	return m_cost;
}

void Potion::setCost(String cost)
{
	m_cost = cost;
}

void Potion::Display()
{
	cout << "Name: " << m_name.GetString() << endl;
	cout << "Description: " << m_description.GetString() << endl;
	cout << "Potency: " << m_potency.GetString() << endl;
	cout << "Cost: " << Conversion();
}

/**********************************************************************
* Purpose: This function is to convert the String into an integer and then
*			return an integer that is the cost of the potion in copper.
*
* Precondition: M/A
*
* Postcondition: Returns the value of the Potion in copper.
*
************************************************************************/

int Potion::Conversion()
{
	int tokcost[4]{ 0 };
	int index = 0;
	int copper = 0;
	int divisor = 1000000;
	const char* cost = m_cost.GetString();						// get the string to be converted
	char tempcost[100]{'\0'};
	strcpy(tempcost, cost);										// copy string into temporary char array
	char* tokenptr = strtok(tempcost, ".");						// tokenize string deliminated by "."
	while (tokenptr != NULL)
	{
		tokcost[index] = atoi(tokenptr);						// put each tokenized int value into an int array
		
		tokenptr = strtok(NULL, ".");

		index++;
	}
	for (int i = 0; i < 4; i++)									// convert the values for plat, gold, and silver into copper and sum them all.
	{
		copper += tokcost[i] * divisor;
		
		divisor = divisor / 100;
	}

	return copper;												// return the cost in the value of copper only.
}
