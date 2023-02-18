#include <iostream>
using std::cout;
using std::endl;
#include "String.h"
#include "Potion.h"
#include "DynamicArray.h"
#include "CoinPouch.h"
#include "BackPack.h"
#include "Character.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
const int NO_POTION = -1;

int main()
{
	int arraysize = 4;
	Character char1;
	Character char2;
	Character char3;
	Character char4;

	ifstream fin("TextFile1.bin", ios::in | ios::binary);			//opens the binary file to be read

	char1.Load(fin);												//load in the information for each character
	char2.Load(fin);
	char3.Load(fin);
	char4.Load(fin);

	Character* CharArray[4]{ &char1, &char2, &char3, &char4 };		//create an array of characters

	for (int i = 0; i < arraysize; ++i)
	{
		CharArray[i]->Display();									//display each characters information
	}

	ofstream fout("TextFile1.bin", ios::out | ios::binary);			//Save any changes made to the characters
	for (int i = 0; i < arraysize; ++i)
	{
		CharArray[i]->Save(fout);
	}

	fout.close();													//close the file
	return 0;
}