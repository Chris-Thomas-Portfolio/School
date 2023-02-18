// Filename: Example 15.4.9.cpp
// Contents: Example 15.4.9 application
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include "types.h"
#include "func_declarations.h"

#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Faculty * cse = nullptr;
	int num_faculty = 0;

	FillArray(cse, num_faculty);
	PrintArray(cse, num_faculty);
	WriteArrayToFile(cse, num_faculty);
	DeleteArray(cse, num_faculty);
	ReadArrayFromFile(cse, num_faculty);
	PrintArray(cse, num_faculty);
	DeleteArray(cse, num_faculty);

	return 0;
}