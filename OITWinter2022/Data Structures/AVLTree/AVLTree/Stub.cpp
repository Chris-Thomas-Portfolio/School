#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "AVLTree.h"
using std::string;

void Display(int data);
void DisplayComplex(string data);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	AVLTree<int> tree;

	tree.Insert(8);
	tree.Insert(5);
	tree.Insert(9);
	tree.Insert(10);
	tree.Insert(6);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(4);
	tree.Insert(7);
	tree.Insert(1);

	tree.Delete(5);
	
	AVLTree<int> treecopy = tree;
	
	tree.InOrder(Display);
	treecopy.InOrder(Display);

	AVLTree<int> opequals;
	opequals = tree;
	opequals.InOrder(Display);
	cout << "Breadth First" << endl;
	opequals.BreadthFirst(Display);

	opequals.PostOrder(Display);

	opequals.PreOrder(Display);

	AVLTree<string> treecomplex;

	treecomplex.Insert("a");
	treecomplex.Insert("b");
	treecomplex.Insert("c");
	treecomplex.Insert("d");
	treecomplex.Insert("e");
	treecomplex.Insert("f");
	treecomplex.Insert("g");
	treecomplex.Insert("h");
	treecomplex.Insert("i");
	treecomplex.Insert("j");

	treecomplex.Delete("b");

	AVLTree<string> treecopycomplex = treecomplex;

	treecomplex.InOrder(DisplayComplex);
	treecopycomplex.InOrder(DisplayComplex);

	AVLTree<string> opequalscomplex;
	opequalscomplex = treecomplex;
	opequalscomplex.InOrder(DisplayComplex);

	opequalscomplex.BreadthFirst(DisplayComplex);

	opequalscomplex.PostOrder(DisplayComplex);

	opequalscomplex.PreOrder(DisplayComplex);

	return 0;
}

void Display(int data)
{
	cout << data << endl;
}

void DisplayComplex(string data)
{
	cout << data << endl;
}