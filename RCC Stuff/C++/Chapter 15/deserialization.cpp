// Filename: deserialization.cpp
// Contents: Functions for performing deserialization for Example 15.4.9
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ios;
using std::ifstream;

#include "func_declarations.h"

void ReadArrayFromFile(Faculty *& ray, int & num_faculty)
{
	ifstream fin("Faculty.bin", ios::in | ios::binary);

	if (fin.is_open())
	{
		int length = 0;

		// First need to read how many elements in dynamic array and create ray
		fin.read(reinterpret_cast<char *>(&num_faculty), sizeof(num_faculty));
		ray = new Faculty[num_faculty];

		// Now we can create a for loop to fill the array
		for (int i = 0; i < num_faculty; ++i)
		{
			// Read in the length of name and create the memory
			fin.read(reinterpret_cast<char *>(&length), sizeof(length));
			ray[i].name = new char[length];

			// Now read in the name into the array
			fin.read(ray[i].name, length);

			// Read in the length of department and create the memory
			fin.read(reinterpret_cast<char *>(&length), sizeof(length));
			ray[i].department = new char[length];

			// Now read in the department into the array
			fin.read(ray[i].department, length);
		}
		fin.close();
	}
	else
	{
		cout << "Could not open file for reading!" << endl;
	}
}