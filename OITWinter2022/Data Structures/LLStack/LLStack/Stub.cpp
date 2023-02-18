/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 1/22/202211:04 AM
* Modifications: Added further testing.
**************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Stack.h"
using std::string;
const char* NAMES[] = { "Kyle", "Brit", "seth", "Alex", "Josh", "Kian",
"Kate", "Terry", "Ann", "Elaine", "Stephanie", "Wanda", "Oscar",
"Oliver", "Tobey" };
const int NUM_NAMES = 15;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*Default Ctor test*/

	Stack<int> test;

	if (test.isEmpty() != true && test.getNumElements() != 0)
	{
		cout << "Default C'tor test failed" << endl;
	}
	else
	{
		cout << "Default C'tor test passed" << endl;
	}

	/*Copy C'tor test*/
	bool pass = true;
	for (int i = 0; i < 10; i++)
	{
		test.Push(i);
	}
	Stack<int> testcopy(test);

	for (int i = 9; i >= 0; i--)
	{
		if (testcopy.Pop() != i)
		{
			pass = false;
		}
	}

	if (pass == true)
	{
		cout << "Copy C'tor test passed" << endl;
	}
	else
	{
		cout << "Copy C'tor test failed" << endl;
	}

	/*Push test*/
	for (int i = 9; i >= 0; i--)
	{
		test.Pop();
	}
	for (int i = 0; i < 10; i++)
	{
		test.Push(i);
	}

	for (int i = 9; i >= 0; i--)
	{
		if (test.Pop() != i)
		{
			pass = false;
		}
	}

	if (pass == true)
	{
		cout << "Push test passed" << endl;
	}
	else
	{
		cout << "Push test failed" << endl;
	}

	/*Pop from empty list test*/
	try
	{
		test.Pop();
	}
	catch (Exception exception)
	{
		cout << "Pop from empty list test passed" << endl;
	}

	/*getNumElements test*/
	for (int i = 0; i < 10; i++)
	{
		test.Push(i);
	}

	if (test.getNumElements() != 10)
	{
		cout << "getNumElements test failed" << endl;
	}
	else
	{
		cout << "getNumElements test passed" << endl;
	}

	/*isEmpty test*/
	if (test.isEmpty() != false)
	{
		pass = false;
	}
	for (int i = 10; i > 0; i--)
	{
		test.Pop();
	}

	if (test.isEmpty() != true || pass == false)
	{
		cout << "isEmpty test failed" << endl;
	}
	else
	{
		cout << "isEmpty test passed" << endl;
	}

	/*Peek test*/
	for (int i = 0; i < 10; i++)
	{
		test.Push(i);
	}

	if (test.Peek() != 9)
	{
		cout << "Peek test failed" << endl;
	}
	else
	{
		cout << "Peek test passed" << endl;
	}

	/*Default C'tor complex data test*/
	Stack<string> complextest;
	if (complextest.isEmpty() != true && complextest.getNumElements() != 0)
	{
		cout << "Default C'tor complex test failed" << endl;
	}
	else
	{
		cout << "Default C'tor complex test passed" << endl;
	}

	/*Copy C'tor complex test*/
	for (int i = 0; i < NUM_NAMES; i++)
	{
		complextest.Push(NAMES[i]);
	}
	Stack<string> complextestcopy(complextest);

	for (int i = NUM_NAMES - 1; i >= 0; i--)
	{
		if (complextestcopy.Pop() != NAMES[i])
		{
			pass = false;
		}
	}

	if (pass == true)
	{
		cout << "Copy C'tor test complex passed" << endl;
	}
	else
	{
		cout << "Copy C'tor test complex failed" << endl;
	}
	/*Push test*/
	for (int i = NUM_NAMES - 1; i >= 0; i--)
	{
		complextest.Pop();
	}
	for (int i = 0; i < NUM_NAMES; i++)
	{
		complextest.Push(NAMES[i]);
	}

	for (int i = NUM_NAMES-1; i >= 0; i--)
	{
		if (complextest.Pop() != NAMES[i])
		{
			pass = false;
		}
	}

	if (pass == true)
	{
		cout << "Push test complex passed" << endl;
	}
	else
	{
		cout << "Push test complex failed" << endl;
	}
	/*Pop from empty list test*/
	try
	{
		complextest.Pop();
	}
	catch (Exception exception)
	{
		cout << "Pop from empty list complex test passed" << endl;
	}
	/*getNumElements test*/
	for (int i = 0; i < NUM_NAMES; i++)
	{
		complextest.Push(NAMES[i]);
	}

	if (complextest.getNumElements() != NUM_NAMES)
	{
		cout << "getNumElements test failed" << endl;
	}
	else
	{
		cout << "getNumElements test passed" << endl;
	}
	/*isEmpty test*/
	if (complextest.isEmpty() != false)
	{
		pass = false;
	}
	for (int i = NUM_NAMES-1; i >= 0; i--)
	{
		complextest.Pop();
	}

	if (complextest.isEmpty() != true || pass == false)
	{
		cout << "isEmpty test complex failed" << endl;
	}
	else
	{
		cout << "isEmpty test complex passed" << endl;
	}
	/*Op = test*/
	int numElements = 15;

	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	Stack<int> testop;

	for (int i(0); i < numElements; ++i)
	{
		testop.Push(test_data[i]);
	}

	Stack<int> test_copy_op = testop;

	for (int i(14); i >= 0; --i)
	{
		if (test_copy_op.Pop() != test_data[i])
		{
			pass = false;
		}
	}
	if (pass == true)
	{
		cout << "Op = test passed" << endl;
	}
	else
	{
		cout << "Op = test failed" << endl;
	}

	/*Op = complex test*/
	

	Stack<string> testcomplex;

	for (int i(0); i < numElements; ++i)
	{
		testcomplex.Push(NAMES[i]);
	}

	Stack<string> test_copy_complex = testcomplex;

	for (int i(14); i >= 0; --i)
	{
		if (test_copy_complex.Pop() != NAMES[i])
		{
			pass = false;
		}
	}
	if (pass == true)
	{
		cout << "Op = complex test passed" << endl;
	}
	else
	{
		cout << "Op = complex test failed" << endl;
	}

	return 0;
}