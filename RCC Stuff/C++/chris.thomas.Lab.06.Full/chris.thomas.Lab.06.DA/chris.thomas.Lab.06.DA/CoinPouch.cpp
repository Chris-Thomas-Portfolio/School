#define _CRT_SECURE_NO_WARNINGS
#include "CoinPouch.h"
#include <iostream>
using std::cout;
using std::endl;
#include "String.h"
#include "Potion.h"
#include "DynamicArray.h"
#include "CoinPouch.h"
#include "BackPack.h"
#include <iostream>
using std::cout;
using std::endl;
#include "CoinPouch.h"

/**********************************************************************
* Purpose: This function is the default constructor for the CoinPouch
*			class.
*
* Precondition:	N/A.
*
* Postcondition: You create a default CoinPouch.
*
************************************************************************/

CoinPouch::CoinPouch() : m_coins(nullptr)
{ }

/**********************************************************************
* Purpose: This function is the one arg constructor for the CoinPouch
*			class.
*
* Precondition:	N/A.
*
* Postcondition: You create a CoinPouch of the value of the arg.
*
************************************************************************/

CoinPouch::CoinPouch(String coin) : m_coins(coin)
{ }

/**********************************************************************
* Purpose: This function is the copy constructor for the CoinPouch
*			class.
*
* Precondition:	Need a CoinPouch.
*
* Postcondition: You create a copy of a CoinPouch.
*
************************************************************************/

CoinPouch::CoinPouch(const CoinPouch& copy) : m_coins(copy.m_coins)
{ }

/**********************************************************************
* Purpose: This function is the operator = for the CoinPouch
*			class.
*
* Precondition:	N/A
*
* Postcondition: You create a CoinPouch that is set to the value on the rhs.
*
************************************************************************/

CoinPouch& CoinPouch::operator=(const CoinPouch& rhs)
{
	if (this != &rhs)
	{
		m_coins = rhs.m_coins;
	}

	return *this;
}

/**********************************************************************
* Purpose: This function is the dtor for the CoinPouch class.
*
* Precondition:	N/A.
*
* Postcondition: You create a delete a CoinPouch.
*
************************************************************************/
CoinPouch::~CoinPouch()
{ }

/**********************************************************************
* Purpose: This function is the display for the CoinPouch class it will
*			show the user the amount of each coin that they have.
*
* Precondition:	Need a CoinPouch.
*
* Postcondition: Displays the amount of each coin you have.
*
************************************************************************/

void CoinPouch::Display() const
{
	unsigned int values[4] = { 0 };
	int count = 0;
	char* tknPtr = nullptr;
	char buffer[50];
	strcpy(buffer, m_coins.GetString());
	tknPtr = strtok(buffer, ".");

	while (tknPtr != NULL)
	{
		values[count] = atoi(tknPtr);
		count++;
		tknPtr = strtok(NULL, ".");
	}

	cout << "Cost: " << values[0] << " Platinum, " << values[1] << " Gold, " << values[2] << " Silver, " << values[3] << " Copper. " << endl;
}

/**********************************************************************
* Purpose: This function saves the data of the CoinPouch to a binary file
*			for later loading.
*
* Precondition:	Need a CoinPouch.
*
* Postcondition: Creates a binary file that has all information stored to it.
*
************************************************************************/

void CoinPouch::Save(ofstream& fout)
{
	m_coins.Save(fout);
}

/**********************************************************************
* Purpose: This function loads the data of the CoinPouch from a binary file
*			for use.
*
* Precondition:	Need a CoinPouch.
*
* Postcondition: Creates a CoinPouch according to information from binary file.
*
************************************************************************/

void CoinPouch::Load(ifstream& fout)
{
	m_coins.Load(fout);
}

/**********************************************************************
* Purpose: This function converts the String to an int to be used in the
*			value conversion in the display function
*
* Precondition:	Need a CoinPouch.
*
* Postcondition: You convert the String to an int having converted it all
*					to copper.
*
************************************************************************/

int CoinPouch::Conversion()
{
	int tokcost[4]{ 0 };
	int index = 0;
	int copper = 0;
	int divisor = 1000000;
	const char* cost = m_coins.GetString();						// get the string to be converted
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