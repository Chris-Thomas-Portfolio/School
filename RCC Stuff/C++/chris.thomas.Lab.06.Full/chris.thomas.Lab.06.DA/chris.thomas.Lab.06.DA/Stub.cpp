#include <iostream>
using std::cout;
using std::endl;
#include "Character.h"
#include "DynamicArray.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

int main()
{
	Potion Health("Health Potion", "Restores a large amount of Health", "Strong", "1.0.0.0");
	Potion Mana("Mana Potion", "Resotres a large amount of Mana", "Strong", "1.0.0.0");
	DynamicArray<Potion> PotBelt;
	DynamicArray<Potion> empty;
	PotBelt.Insert(Health);
	PotBelt.Insert(Mana);
	BackPack Holding(PotBelt);
	CoinPouch Purse("1.1.1.1");
	BackPack Empty(empty);
	CoinPouch broke("0.0.0.0");

	try
	{
		empty.Delete(Health);
	}
	catch (int e)
	{
		if (e == NO_POTION)
		{
			cout << "Cannot delete from empty list" << endl;
		}
	}

	cout << "The number of elements in the array is " << PotBelt.GetElements() << endl;
	cout << "The Health Potion is located at index " << PotBelt.Find(Health) << endl;
	try
	{
		Holding.DeleteItem(Health);
	}
	catch (int e)
	{
		if (e == NO_POTION)
		{
			cout << "Cannot delete from empty list" << endl;
		}
	}

	Character char1("Liam", Holding, Purse);
	Character char2("Dave", Holding, Purse);
	Character char3("Nobody", Empty, broke);
	
	DynamicArray<Character> charlist;
	charlist.Insert(char1);
	charlist.Insert(char2);
	charlist.Insert(char3);
	try
	{
		charlist.Display();
	}
	catch (int e)
	{
		if (e == NO_POTION)
		{
			cout << "WOW such empty" << endl;
		}
	}
	cout << endl;

	ofstream fout("Character.bin", ios::out | ios::binary);
	charlist.Save(fout);
	fout.close();

	charlist.Delete(char1);
	charlist.Delete(char2);
	charlist.Delete(char3);

	DynamicArray<Character> charlist1;
	ifstream fin("Character.bin", ios::in | ios::binary);
	charlist1.Load(fin);
	fin.close();

	charlist1.Display();

	cout << endl;

	return 0;
}