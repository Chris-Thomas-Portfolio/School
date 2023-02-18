/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 1/19/2022 9:35 AM
* Modifications: Added more testing of Stack class.
**************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Stack.h"
#include <string>
using std::string;
const char* NAMES[] = { "Kyle", "Brit", "seth", "Alex", "Josh", "Kian",
"Kate", "Terry", "Ann", "Elaine", "Stephanie", "Wanda", "Oscar",
"Oliver", "Tobey" };
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*Negative Stack size test*/
	try
	{
		Stack<int> test(-1);
	}
	catch (Exception& exception)
	{
		cout << "Negative stack size value test passed" << endl;
	}

	Stack<int> test;
	/*Underflow test*/
	try
	{
		test.Pop();
	}
	catch (Exception& exception)
	{
		cout << "Underflow test passed" << endl;
	}
	/*Overflow test*/
	try
	{
		test.Push(1);
	}
	catch (Exception& exception)
	{
		cout << "Overflow test passed" << endl;
	}
	/*1 arg ctor test*/
	int stacksize = 5;
	Stack<int> test1arg(stacksize);
	if (test1arg.getSize() != stacksize)
	{
		cout << "1 arg test failed" << endl;
	}
	else
	{
		cout << "1 arg test passed" << endl;
	}
	/*setSize test*/
	int setsize = 10;
	test.setSize(setsize);
	if (test.getSize() != setsize)
	{
		cout << "setSize test failed" << endl;
	}
	else
	{
		cout << "setSize test passed" << endl;
	}
	/*Push test*/
	int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool pass = true;
	for (int i = 0; i < setsize; i++)
	{
		test.Push(test_data[i]);
	}

	for (int i = 0; i < setsize; i++)
	{
		if (test.Pop() != test_data[(setsize-1)-i])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Push test failed" << endl;
	}
	else
	{
		cout << "Push test passed" << endl;
	}
	/*Copy ctor test*/
	for (int i = 0; i < setsize; i++)
	{
		test.Push(test_data[i]);
	}

	Stack<int> testcopy(test);

	for (int i = 0; i < setsize; i++)
	{
		if (testcopy.Pop() != test_data[(setsize-1) - i])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Copy Ctor test failed" << endl;
	}
	else
	{
		cout << "Copy Ctor test passed" << endl;
	}
	/*Op = test*/
	testcopy = test;

	for (int i = 0; i < setsize; i++)
	{
		if (testcopy.Pop() != test_data[(setsize-1) - i])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Op = test failed" << endl;
	}
	else
	{
		cout << "Op = test passed" << endl;
	}
	/*setSize increase with data test*/
	testcopy = test;
	int newsetsize = 15;
	testcopy.setSize(newsetsize);
	for (int i = 0; i < setsize; i++)
	{
		if (testcopy.Pop() != test_data[(setsize-1)-i] && testcopy.getSize() != setsize)
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "setSize increase with data test failed" << endl;
	}
	else
	{
		cout << "setSize increase with data test passed" << endl;
	}
	/*setSize with data decrease test*/
	testcopy = test;
	newsetsize = 5;
	testcopy.setSize(newsetsize);
	for (int i = 0; i < newsetsize; i++)
	{
		if (testcopy.Pop() != test_data[(newsetsize - 1) - i] && testcopy.getSize() != newsetsize)
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "setSize decrease with data test failed" << endl;
	}
	else
	{
		cout << "setSize decrease with data test passed" << endl;
	}
	/*Negative stack size complex data type test*/
	try
	{
		Stack<string> test(-1);
	}
	catch (Exception& exception)
	{
		cout << "Negative stack size value complex test passed" << endl;
	}

	Stack<string> testcomplex;
	/*Underflow complex data type test*/
	try
	{
		testcomplex.Pop();
	}
	catch (Exception& exception)
	{
		cout << "Underflow complex test passed" << endl;
	}
	/*Overflow complex data test*/
	try
	{
		testcomplex.Push("David");
	}
	catch (Exception& exception)
	{
		cout << "Overflow complex test passed" << endl;
	}
	/*1 arg ctor complex data test*/
	stacksize = 5;
	Stack<string> test1argcomplex(stacksize);
	if (test1argcomplex.getSize() != stacksize)
	{
		cout << "1 arg complex test failed" << endl;
	}
	else
	{
		cout << "1 arg complex test passed" << endl;
	}
	/*setSize complex data test*/
	setsize = 10;
	testcomplex.setSize(setsize);
	if (testcomplex.getSize() != setsize)
	{
		cout << "setSize complex test failed" << endl;
	}
	else
	{
		cout << "setSize complex test passed" << endl;
	}
	/*Push complex data test*/
	int num = 0;
	for (int i = 0; i < setsize; i++)
	{
		testcomplex.Push(NAMES[num++]);
	}
	--num;
	for (int i = 0; i < setsize; i++)
	{
		if (testcomplex.Pop() != NAMES[num--])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Push test failed" << endl;
	}
	else
	{
		cout << "Push test passed" << endl;
	}

	/*Copy ctor complex data test*/
	num = 0;
	for (int i = 0; i < setsize; i++)
	{
		testcomplex.Push(NAMES[num++]);
	}
	--num;
	Stack<string> testcomplexcopy(testcomplex);
	for (int i = 0; i < setsize; i++)
	{
		if (testcomplexcopy.Pop() != NAMES[num--])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Copy ctor complex test failed" << endl;
	}
	else
	{
		cout << "Copy ctor complex passed" << endl;
	}
	/*Op = complex data test*/
	num = 9;
	testcomplexcopy = testcomplex;
	for (int i = 0; i < setsize; i++)
	{
		if (testcomplexcopy.Pop() != NAMES[num--])
		{
			pass = false;
		}
	}

	if (pass == false)
	{
		cout << "Op = complex test failed" << endl;
	}
	else
	{
		cout << "Op = complex passed" << endl;
	}

	/*setSize increase with data complex test*/
	setsize = 15;
	num = 9;
	testcomplex.setSize(setsize);
	for (int i = 0; i < 9; i++)
	{
		if (testcomplex.Pop() != NAMES[num--] && testcomplex.getSize() != setsize)
		{
			pass = false;
		}
	}


	if (pass == false)
	{
		cout << "setSize increase with data complex test failed" << endl;
	}
	else
	{
		cout << "setSize increase with data complex passed" << endl;
	}
	/*setSize decrease with complex data test*/

	setsize = 5;
	num = 5;
	testcomplex.setSize(setsize);
	for (int i = 0; i < setsize; i++)
	{
		if (testcomplex.Pop() != NAMES[num--] && testcomplex.getSize() != setsize)
		{
			pass = false;
		}
	}


	if (pass == false)
	{
		cout << "setSize decrease with data complex test failed" << endl;
	}
	else
	{
		cout << "setSize decrease with data complex passed" << endl;
	}

	if (pass == false)
	{
		cout << "FAILURE!!" << endl;
	}
	else
	{
		cout << "All tests passed!" << endl;
	}

	return 0;
}