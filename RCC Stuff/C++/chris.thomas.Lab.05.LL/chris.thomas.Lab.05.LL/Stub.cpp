#include <iostream>
using std::cout;
using std::endl;
#include "Character.h"
#include "List.h"
#include "Node.h"
#include <fstream>
using std::ios;

int Node::count = 0;

int main()
{
	Potion Health("Health Potion", "Restores a large amount of health", "Strong", "1.1.1.1");
	Potion Mana("Mana Potion", "Resotre a large amount of mana", "Strong", "1.1.1.1");
	Potion health("health potion", "Restores a small amount of health", "Weak", "0.0.1.1");
	Potion mana("mana potion", "Restores a small amount of mana", "Weak", "0.0.1.1");
	List l1;

	try
	{
		l1.DeleteNode("Health Potion");
	}
	catch (const int EMPTY_LIST)
	{
		cout << "Cannot delete from empty list" << endl;
	}
	try
	{
		l1.PopFront().Display();							// attempt PopFront with empty list to test exception handling
	}
	catch (const int EMPTY_LIST)
	{
		cout << "The List is empty" << endl;
	}
	try
	{
		l1.PopBack().Display();								// attempt PopBack with empty list to test exception handling
	}
	catch (const int EMPTY_LIST)
	{
		cout << "The List is empty" << endl;
	}
	//Fill the list with potions
	l1.PushFront(Health);
	l1.PushFront(Mana);
	l1.PushBack(health);
	l1.PushBack(mana);
	//display list
	l1.Display();
	//Empty list
	l1.Purge();
	//build list using insert ordered to test it
	l1.InsertOrdered(Health);
	l1.InsertOrdered(Mana);
	l1.InsertOrdered(health);
	l1.InsertOrdered(mana);
	//display ordered list
	l1.Display();
	//display the potion at the second spot in list
	l1.GetIthElement(1).Display();
	//display the front and back node of the list
	l1.Front().Display();
	l1.Back().Display();
	//delete the Health Potion from the list and display showing it is gone
	l1.DeleteNode("Health Potion");
	l1.Display();
	//test PopBack and PopFront
	l1.PopBack().Display();
	l1.PopFront().Display();
	//display the list showing those two potions got deleted
	l1.Display();

	Character char1;
	ifstream fin("RPG.bin", ios::in | ios::binary);

	char1.Load(fin);

	char1.Display();

	ofstream fout("RPG.bin", ios::out | ios::binary);
	char1.Save(fout);
	return 0;
}