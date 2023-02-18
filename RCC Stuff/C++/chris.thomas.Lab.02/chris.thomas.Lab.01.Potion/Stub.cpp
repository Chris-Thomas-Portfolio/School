/*************************************************************
* Author:		Chris Thomas
* Filename:		chris.thomas.Lab.02.cpp
* Date Created:	4/120/2020
* Modifications:	N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 1 – Grade Program
*
* Overview:
*	This program will create an array of potions to test the 
*	potions class and show the total cost of all the potions
*   made.
*
* Input:
*	The input will consist of a name, description, potency and
*	cost of each potion.
*
* Output:
*	The output of this program will be the accumulative cost of
*	all the potions created in the array.
* 	
************************************************************/

#include <iostream>
using std::cout;
using std::endl;
#include "Potion.h"
#include "Stub.h"

int main()
{
	Potion Health("Health Potion", "Restores a large amount of Health", "Strong", "1.1.1.50");						// create a Health Potion
	Potion Mana("Mana Potion", "Restores a small amount of Mana", "Weak", "0.0.1.0");								// create a Mana Potion
	Potion Stamina("Stamina Potion", "Restores a moderate amount of Stamina", "Medium", "0.1.0.50");				// create a Stamina Potion

	Potion PotionBelt[3]{ Health, Mana, Stamina };																	// create an array of potions
	
	TotalCost(PotionBelt);

	return 0;
}

/**********************************************************************
* Purpose: This function converts the strings to an int that is then 
		   converts the ints into the different types of currency.
*
* Precondition:	Need to have an array of Potions made.
*     
* Postcondition: Displays the total cost of all the Potions combined.
*     
************************************************************************/

void TotalCost(Potion total[])
{
	int platinum = 0;
	int gold = 0;
	int silver = 0;
	int copper = 0;

	for (int i = 0; i < 3; ++i)											// converts the strings to usable integers
	{
		platinum += total[i].Conversion() / 1000000;
		gold += (total[i].Conversion() % 1000000) / 10000;
		silver += ((total[i].Conversion() % 1000000) % 10000) / 100;
		copper += ((total[i].Conversion() % 1000000) % 10000) % 100;
	}
	if (gold >= 100)													// check to see if there is enough gold to become a platinum
	{
		gold -= 100;
		platinum += 1;
	}
	else if (silver >= 100)												// check to see if there is enough silver to become a gold
	{
		silver -= 100;
		gold += 1;
	}
	else if (copper >= 100)												// check to see if there is enough copper to become a silver
	{
		copper -= 100;
		silver += 1;
	}
	cout << platinum << " Platinum, " << gold << " Gold, " << silver << " Silver, " << copper << " Copper" << endl;	// display total cost
}