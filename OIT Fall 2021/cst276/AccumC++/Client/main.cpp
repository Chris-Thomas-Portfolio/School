#include "Accum.h";
#include <iostream>;
using namespace ::std;

int main()
{
	Accumulator acc;
	cout << "The new total is: " << acc.Accum(5) << "\n";
	cout << "The new total is: " << acc.Accum(7) << "\n";
	cout << "The new total is: " << acc.Accum(8) << "\n";

	return 0;
}