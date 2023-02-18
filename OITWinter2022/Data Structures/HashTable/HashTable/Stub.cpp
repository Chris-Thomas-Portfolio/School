/*************************************************************
* Author: Chris Thomas
* Filename: HashTable.h
* Date Created: 6/2/2022 11:20 AM
* Modifications: N/A
**************************************************************/

#include<iostream>
#include "HashTable.h"
#include "Exception.h"

int HashData(string data);
void Display(Book test);

int main()
{
	Hash<string, Book> table(10);

	table.setHash(HashData);

	Book temp = { "C++: Learn by Doing", "Todd Breedlove, Troy Scevers, et. al.", 635 };
	table.Insert("0763757233", temp);

	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	table.Insert("7063757233", temp1);

	Book temp3 = { "And That n There", "Ralph Carestia", 1 };
	table.Insert("7063757234", temp3);

	cout << table["0763757233"].m_title << endl;
	cout << table["7063757233"].m_title << endl;
	cout << table["7063757234"].m_title << endl;

	return 0;
}

void Visit(int data)
{
	cout << data << ' ';
}

void StringVisit(string data)
{
	cout << data << ' ';
}

int HashData(string data)
{
	int total = 0;
	for (int i = 0; i < data.size(); i++)
	{
		int temp = (int)data[i];
		total = total + temp;
	}
	return total;
}

void Display(Book test)
{
	cout << "Title: " << test.m_title << ", Author(s): " << test.m_author << ", Pages: " << test.m_pages << endl;
}