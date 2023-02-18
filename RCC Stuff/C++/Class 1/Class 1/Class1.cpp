#include <iostream>
using std::cout;
using std::endl;
#include "Movies.h"
int main()
{
	Movies nothing;
	Movies invisibleMan("Invisible Man", "Thriller", 90);
	Movies copy = invisibleMan;
	Movies copy2;
	copy2 = copy;

	nothing.Display();
	invisibleMan.Display();
	copy.Display();
	copy2.Display();

	return 0;
}