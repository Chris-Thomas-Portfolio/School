#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "String.h"

/************************************************************************
* Class: Array
*
* Purpose: This class creates a potion to be used in an RPG setting.
*
* Manager functions:
* 	Potion ( )
*		The default is an empty string.
*	Potion (string name, string description, string potency, string cost)
*		Creates a potion with the inputed strings.
*	Potion (const Potion & copy)
*	operator = (const Potion & copy)
*	~Potion ( )
*
* Methods:
*	string getName()
*		Gets the name of the potion.
*	setName(string name)
*		Sets the name of the potion.
*	string getDescription()
*		Gets the description of the potion.
*	setDescription(string description)
*		Sets the description of the potion.
*	string getPotency()
*		Gets the potency of the potion.
*	setPotency(string potency)
*		Sets the potency of the potion.
*	string getCost()
*		Gets the cost of the potion.
*	setCost(string cost)
*		Sets the cost of the potion.
*	Display()
*		Displays the name, description, potency, and cost of the potion
*	int Conversion()
*		Converts the String to an int and converts the plat, gold, and silver
*		to copper and sums them and returns that value.
*************************************************************************/

class Potion {
public:
	Potion();
	Potion(String name, String description, String potency, String cost);
	Potion(const Potion& copy);
	Potion& operator =(const Potion& rhs);
	~Potion();
	String getName() const;
	void setName(String name);
	String getDescription() const;
	void setDescription(String description);
	String getPotency() const;
	void setPotency(String potency);
	String getCost() const;
	void setCost(String cost);
	void Display();
	int Conversion();
	void Save(ofstream& fout);
	void Load(ifstream& fout);
private:
	String m_name;
	String m_description;
	String m_potency;
	String m_cost;
};