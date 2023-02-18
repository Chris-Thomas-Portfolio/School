/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 1/25/2022 6:41 PM
* Modifications: N/A
**************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "BSTree.h"

void Display(int data);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	BSTree<int> tree;
	tree.Insert(10);
	tree.Insert(9);
	tree.Insert(11);
	BSTree<int> tree1(tree);

	tree.Delete(9);
	tree1.Height();

	tree1.InOrder(Display);
	cout << endl;
	tree1.PostOrder(Display);
	cout << endl;
	tree1.PreOrder(Display);
	cout << endl;
	tree1.BreadthFirst(Display);
	cout << endl;

	BSTree<int> tree3 = tree1;
	tree3.InOrder(Display);


	return 0;
}

void Display(int data)
{
	cout << data << endl;
}