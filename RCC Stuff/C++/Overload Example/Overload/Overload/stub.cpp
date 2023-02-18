#include <iostream>
using std::cout;
using std::endl;
#include "String.h"
#include <cstring>

const int INDEX_OUT_OF_BOUNDS = -1;

int main()
{
	String ctor("Ctor");
	String cctor = ctor;
	String cat = ctor + cctor;
	cout << ctor[0] << endl;
	String name("chris Thomas");
	cout << ++name << endl;

	return 0;
}