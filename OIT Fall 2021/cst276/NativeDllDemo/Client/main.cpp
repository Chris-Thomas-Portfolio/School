#include <iostream>
using std::cout;
using std::cin;
#include "Calc.h"

int main()
{
	Calc c;
	int x = 0;
	int y = 0;
	int a = 0;
	cout << "Would you like to Add or Subtract?\n";
	cout << "1) Add\n";
	cout << "2) Subtract\n";
	cin >> a;
	if (a == 1)
	{
		cout << "Enter the first value\n";
		cin >> x;
		cout << "Enter the second value\n";
		cin >> y;
		cout << "The value is " << c.Add(x, y);
	}
	else if(a == 2)
	{
		cout << "Enter the first value\n";
		cin >> x;
		cout << "Enter the second value\n";
		cin >> y;
		cout << "The value is " << c.Sub(x, y);
	}
	else
	{
		cout << "Not a valid option\n";
	}

	return 0;
}