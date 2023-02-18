/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 1/22/2022 1:04 PM
* Modifications: N/A
**************************************************************/
#define _CRTDBG_MAP_ALLOC
typedef bool(*FunctionPointer)();  
#include <crtdbg.h>
#include <conio.h>
#include <iostream>
using std::cin;
#include "Queue.h"
#include <string>
using std::string;
const char* NAMES[] = { "Kyle", "Brit", "seth", "Alex", "Josh", "Kian",
"Kate", "Terry", "Ann", "Elaine", "Stephanie", "Wanda", "Oscar",
"Oliver", "Tobey" };

const int NUM_NAMES = 15;

//test functions declarations
bool test_default_ctor();
bool test_copy_ctor();
bool test_underflow();
bool test_peek();
bool test_peek_on_empty_Queue();
bool test_isEmpty();
bool test_getSize();
bool test_default_ctor_complex();
bool test_copy_ctor_complex();
bool test_underflow_complex();
bool test_peek_complex();
bool test_peek_on_empty_Queue_complex();
bool test_isEmpty_complex();
bool test_getSize_complex();
bool test_op_equals();
bool test_op_equals_complex();



FunctionPointer test_functions[] = { test_default_ctor, test_copy_ctor, test_underflow, test_peek, test_peek_on_empty_Queue, test_isEmpty, test_getSize, test_default_ctor_complex, test_copy_ctor_complex, test_underflow_complex, test_peek_complex,
									test_peek_on_empty_Queue_complex, test_isEmpty_complex, test_getSize_complex, test_op_equals, test_op_equals_complex };

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	

	//run all functions to test project
	for (FunctionPointer func : test_functions)
	{
		if (func())
		{
			cout << "passed\n";
		}
		else
		{
			cout << "***** failed *****\n";
		}
	}

	cout << "\nPress Any Key to Exit";
	cin.get();

	return 0;
}

bool test_default_ctor()
{
	bool pass = true;
	int default_numElements = 0;

	Queue<int> test;

	if (test.getSize() != default_numElements)
	{
		pass = false;
	}

	cout << "Default ctor test ";

	return pass;
}

bool test_copy_ctor()
{
	bool pass = true;
	int numElements = 15;

	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	Queue<int> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(test_data[i]);
	}

	Queue<int> test_copy(test);

	for (int i(0); i < numElements; ++i)
	{
		if (test_copy.Dequeue() != test_data[i])
		{
			pass = false;
		}
	}

	cout << "Copy Ctor test ";

	return pass;
}

bool test_underflow()
{
	bool pass = false;
	Queue<int> test;

	try
	{
		test.Dequeue();
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Stack Underflow test ";

	return pass;
}

bool test_peek()
{
	bool pass = true;
	int numElements = 15;
	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	int num = 0;

	Queue<int> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(test_data[i]);
	}

	if (test.Peek() != num)
	{
		pass = false;
	}

	cout << "Peek Test ";

	return pass;
}

bool test_peek_on_empty_Queue()
{
	bool pass = false;
	Queue<int> test;

	try
	{
		test.Peek();
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Test peek on empty Queue ";
	return pass;

}

bool test_isEmpty()
{
	bool pass = true;
	Queue<int> test;

	if (test.isEmpty() != true)
	{
		pass = false;
	}

	cout << "isEmpty test ";

	return pass;
}

bool test_getSize()
{
	bool pass = true;
	int numElements = 15;
	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	Queue<int> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(test_data[i]);
	}

	if (test.getSize() != numElements)
	{
		pass = false;
	}

	cout << "Get numElements test ";

	return pass;
}

bool test_default_ctor_complex()
{
	bool pass = true;
	int default_numElements = 0;

	Queue<string> test;

	if (test.getSize() != default_numElements)
	{
		pass = false;
	}

	cout << "Default ctor test complex ";

	return pass;
}

bool test_copy_ctor_complex()
{
	bool pass = true;
	int numElements = 15;

	Queue<string> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(NAMES[i]);
	}

	Queue<string> test_copy(test);

	for (int i(0); i < numElements; ++i)
	{
		if (test_copy.Dequeue() != NAMES[i])
		{
			pass = false;
		}
	}

	cout << "Copy Ctor test complex ";

	return pass;
}

bool test_underflow_complex()
{
	bool pass = false;
	Queue<string> test;

	try
	{
		test.Dequeue();
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Stack Underflow test complex ";

	return pass;
}

bool test_peek_complex()
{
	bool pass = true;
	int numElements = 15;
	string name = "Kyle";

	Queue<string> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(NAMES[i]);
	}

	if (test.Peek() != name)
	{
		pass = false;
	}

	cout << "Peek Test complex ";

	return pass;
}

bool test_peek_on_empty_Queue_complex()
{
	bool pass = false;
	Queue<string> test;

	try
	{
		test.Peek();
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Test peek on empty Queue complex ";
	return pass;
}

bool test_isEmpty_complex()
{
	bool pass = true;
	Queue<string> test;

	if (test.isEmpty() != true)
	{
		pass = false;
	}

	cout << "isEmpty test complex ";

	return pass;
}

bool test_getSize_complex()
{
	bool pass = true;
	int numElements = 15;

	Queue<string> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(NAMES[i]);
	}

	if (test.getSize() != numElements)
	{
		pass = false;
	}

	cout << "Get numElements test complex ";

	return pass;
}

bool test_op_equals()
{
	bool pass = true;
	int numElements = 15;

	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	Queue<int> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(test_data[i]);
	}

	Queue<int> test_copy = test;

	for (int i(0); i < numElements; ++i)
	{
		if (test_copy.Dequeue() != test_data[i])
		{
			pass = false;
		}
	}

	cout << "Op = test ";

	return pass;
}

bool test_op_equals_complex()
{
	bool pass = true;
	int numElements = 15;

	Queue<string> test;

	for (int i(0); i < numElements; ++i)
	{
		test.Enqueue(NAMES[i]);
	}

	Queue<string> test_copy = test;

	for (int i(0); i < numElements; ++i)
	{
		if (test_copy.Dequeue() != NAMES[i])
		{
			pass = false;
		}
	}

	cout << "Op = test complex ";

	return pass;
}
