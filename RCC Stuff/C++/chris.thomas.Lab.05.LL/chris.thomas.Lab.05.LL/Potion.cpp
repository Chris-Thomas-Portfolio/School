#define _CRT_SECURE_NO_WARNINGS
#include "Potion.h"
#include <cstring>
#include <fstream>
using std::ofstream;
using std::ios;

/**********************************************************************
* Purpose: This function is the default constructor for the Potion class.
*
* Precondition:	N/A
*
* Postcondition: You create a default Potion.
*
************************************************************************/

Potion::Potion() : m_name(" "), m_description(" "), m_potency(" "), m_cost(" ")
{ }

/**********************************************************************
* Purpose: This function is the 4 arg constructor setting the values for
*			the potion from the args.
*
* Precondition:	N/A
*
* Postcondition: You create a Potion with the values of the args.
*
************************************************************************/

Potion::Potion(String name, String description, String potency, String cost) : m_name(name), m_description(description), m_potency(potency), m_cost(cost)
{ }

/**********************************************************************
* Purpose: This function creates a copy of a Potion
*
* Precondition:	Need to have a Potion
*
* Postcondition: You create a Potion that is a copy of another.
*
************************************************************************/

Potion::Potion(const Potion& copy) : m_name(copy.m_name), m_description(copy.m_description), m_potency(copy.m_potency), m_cost(copy.m_cost)
{ }

/**********************************************************************
* Purpose: This function allows you to use the '=' operator to assign
*			values to a Potion.
*
* Precondition:	Need to have a Potion
*
* Postcondition: You create a Potion with the values of the potion on the
*					rhs.
*
************************************************************************/

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
/**********************************************************************
* Purpose: This function is dtor for the Potion class.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You delete a Potion.
*
************************************************************************/

Potion::~Potion()
{

}

/**********************************************************************
* Purpose: This function returns the m_name of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You return the m_name for the Potion.
*
************************************************************************/

String Potion::getName() const
{
	return m_name;
}

/**********************************************************************
* Purpose: This function sets the Potions m_name.
*
* Precondition:	Need a Potion
*
* Postcondition: You set the m_name for the Potion.
*
************************************************************************/

void Potion::setName(String name)
{
	m_name = name;
}

/**********************************************************************
* Purpose: This function returns the m_description of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You return the m_description for the Potion.
*
************************************************************************/

String Potion::getDescription() const
{
	return m_description;
}

/**********************************************************************
* Purpose: This function sets the m_description of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You set the m_description for the Potion.
*
************************************************************************/

void Potion::setDescription(String description)
{
	m_description = description;
}

/**********************************************************************
* Purpose: This function returns the m_potency of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You return the m_potency for the Potion.
*
************************************************************************/

String Potion::getPotency() const
{
	return m_potency;
}

/**********************************************************************
* Purpose: This function sets the m_potency of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You set the m_potency for the Potion.
*
************************************************************************/

void Potion::setPotency(String potency)
{
	m_potency = potency;
}

/**********************************************************************
* Purpose: This function returns the m_cost of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You return the m_cost for the Potion.
*
************************************************************************/

String Potion::getCost() const
{
	return m_cost;
}

/**********************************************************************
* Purpose: This function sets the m_cost of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You set the m_cost for the Potion.
*
************************************************************************/

void Potion::setCost(String cost)
{
	m_cost = cost;
}

/**********************************************************************
* Purpose: This function displays all the info of the Potion.
*
* Precondition:	Need to have a Potion.
*
* Postcondition: You display m_name, m_description, m_potency, and m_cost.
*
************************************************************************/

void Potion::Display() const
{
	unsigned int values[4] = { 0 };
	int count = 0;
	char* tknPtr = nullptr;
	char buffer[50];
	strcpy(buffer, m_cost.GetString());
	tknPtr = strtok(buffer, ".");

	while (tknPtr != NULL)
	{
		values[count] = atoi(tknPtr);
		count++;
		tknPtr = strtok(NULL, ".");
	}

	cout << "Name: " << m_name.GetString() << endl;
	cout << "Description: " << m_description.GetString() << endl;
	cout << "Potency: " << m_potency.GetString() << endl;
	cout << "Cost: " << values[0] << " Platinum, " << values[1] << " Gold, " << values[2] << " Silver, " << values[3] << " Copper. " <<  endl;
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
	char tempcost[100]{ '\0' };
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

/**********************************************************************
* Purpose: This function saves the information of the Potion to a binary file.
*
* Precondition: Need a Potion.
*
* Postcondition: Binary file created with the information of the Potion.
*
************************************************************************/

void Potion::Save(ofstream& fout)
{
	m_name.Save(fout);
	m_description.Save(fout);
	m_potency.Save(fout);
	m_cost.Save(fout);
}

/**********************************************************************
* Purpose: This function loads the information of the binary file to a Potion.
*
* Precondition: Need a Potion
*
* Postcondition: Potion created with the information of the binary file.
*
************************************************************************/

void Potion::Load(ifstream& fout)
{
	m_name.Load(fout);
	m_description.Load(fout);
	m_potency.Load(fout);
	m_cost.Load(fout);
}
