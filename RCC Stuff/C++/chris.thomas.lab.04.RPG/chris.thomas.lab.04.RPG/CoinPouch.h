#pragma once
#include "String.h"

/************************************************************************
* Class: CoinPouch
*
* Purpose: This class is designed to hold a value of currency.
*
* Manager functions:
* 	CoinPouch ( )
* 		The default of the CoinPouch is nothing.
*	CoinPouch (String coin)
*		Creates a CoinPouch set to the value of the variable.
*	CoinPouch (const CoinPouch& copy)
*	operator = (const String & copy)
*	~CoinPouch()
*	void Display() const;
*	int Conversion();
*		Converts from the m_coin String to an int value of copper.
*
*************************************************************************/

class CoinPouch
{
public:
	CoinPouch();
	CoinPouch(String coin);
	CoinPouch(const CoinPouch& copy);
	CoinPouch& operator = (const CoinPouch& rhs);
	~CoinPouch();
	void Display();
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	String m_coins;
	int Conversion();
};

