#include <iostream>
using std::cout;
using std::endl;
#include "Character.h"
#include "Node.h"
#include "List.h"
#include "DynamicArray.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

int Node<Character>::count = 0;
int Node<Potion>::count = 0;

int main()
{
	Potion Health("Health Potion", "Restores a large amount of Health", "Strong", "1.0.0.0");
	Potion Mana("Mana Potion", "Resotres a large amount of Mana", "Strong", "1.0.0.0");
	List<Potion> PotBelt;
	List<Potion> empty;
	PotBelt.InsertOrdered(Health);
	PotBelt.InsertOrdered(Mana);
	BackPack Holding(PotBelt);
	CoinPouch Purse("1.1.1.1");
	BackPack Empty(empty);
	CoinPouch broke("0.0.0.0");

	try
	{
		empty.DeleteNode("Health Potion");
	}
	catch (int e)
	{
		if (e == EMPTY_LIST)
		{
			cout << "Cannot delete from empty list" << endl;
		}
	}

	try
	{
		Holding.DeleteItem("Health Potion");
	}
	catch (int e)
	{
		if (e == EMPTY_LIST)
		{
			cout << "Cannot delete from empty list" << endl;
		}
	}

	Character char1("Liam", Holding, Purse);
	Character char2("Dave", Holding, Purse);
	Character char3("Nobody", Holding, Purse);
	
	List<Character> charlist;
	charlist.PushBack(char2);
	charlist.PushBack(char1);
	charlist.PushFront(char3);
	try
	{
		charlist.Display();
	}
	catch (int e)
	{
		if (e == EMPTY_LIST)
		{
			cout << "WOW such empty" << endl;
		}
	}
	cout << endl;

	ofstream fout("Character.bin", ios::out | ios::binary);
	charlist.Save(fout);
	fout.close();
	ifstream fin("Character.bin", ios::in | ios::binary);
	charlist.Load(fin);
	fin.close();

	charlist.Display();

	cout << endl;

	return 0;
}