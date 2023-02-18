#define CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::endl;
#include "List.h"
#include "Movies.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Movies movie1("The Invisible Man", "Thriller", 90);
	Movies movie2("Evil Dead", "Classic Horror", 90);
	Movies movie3("Monty Python and the Holy Grail", "Comedy", 120);

	List mylist;
	mylist.InsertOrdered(movie1);
	mylist.InsertOrdered(movie2);             
	mylist.InsertOrdered(movie3);

	List list2;
	list2.DeleteNode("Foo");
	list2 = mylist;

	mylist.DeleteNode("Big Trouble in Little China");
	mylist.DeleteNode("Monty Python and the Holy Grail");
	cout << "\n\n";
	mylist.Display();
	cout << "\n\n";
	list2.Display();
	cout << "\n\n";

	return 0;
}