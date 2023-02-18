// Filename: serialization.cpp
// Contents: Functions for performing serialization for Example 15.4.9
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ios;
using std::ofstream;
#include "func_declarations.h"

void WriteArrayToFile(Faculty * ray, int num_faculty)
{
	ofstream fout("Faculty.bin", ios::out | ios::binary);

	if (fout.is_open())
	{
		int str_length = 0;

		// Write the size of the dynamic array first
		fout.write(reinterpret_cast<char *>(&num_faculty), sizeof(num_faculty));

		// Now we need a for loop to write out each peice of the array
		for (int i = 0; i < num_faculty; i++)
		{
			// Get length of name including '\0'
			str_length = strlen(ray[i].name) + 1;

			// Write out length of name
			fout.write(reinterpret_cast<char *>(&str_length), sizeof(str_length));

			// Write out the name string (Note: we do not need a reinterpret cast here)
			fout.write(ray[i].name, str_length);

			// Get length of department including '\0'
			str_length = strlen(ray[i].department) + 1;

			// Write out length of department
			fout.write(reinterpret_cast<char *>(&str_length), sizeof(str_length));

			// Write out the department string (Note: we do not need a reinterpret cast here)
			fout.write(ray[i].department, str_length);
		}

		fout.close();
	}
	else
	{
		cout << "Could not open file for writing!" << endl;
	}
}