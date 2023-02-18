// Filename: array_manipulation.cpp
// Contents: Functions for performing various array manipulation for Example 15.4.9
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "types.h"
#include "func_declarations.h"

void FillArray(Faculty *& ray, int & num_faculty)
{
	char buffer[256] = "";

	cout << "How many faculty do you want to enter: ";
	cin >> num_faculty;

	ray = new Faculty[num_faculty];

	for (int i = 0; i < num_faculty; ++i)
	{
		cout << "Please enter the Faculty's name: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(buffer, 255);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		ray[i].name = new char[strlen(buffer) + 1];
		strcpy(ray[i].name, buffer);

		cout << "Please enter the Faculty's department: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(buffer, 255);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		ray[i].department = new char[strlen(buffer) + 1];
		strcpy(ray[i].department, buffer);
	}
}

void PrintArray(Faculty * ray, int num_faculty)
{
	for (int i = 0; i < num_faculty; ++i)
	{
		cout << "Faculty " << ray[i].name << " is in department " << ray[i].department << endl;
	}
}

void DeleteArray(Faculty *& ray, int & num_faculty)
{
	for (int i = 0; i < num_faculty; ++i)
	{
		delete[] ray[i].name;
		delete[] ray[i].department;
	}

	delete[] ray;
	ray = nullptr;
	num_faculty = 0;
}
