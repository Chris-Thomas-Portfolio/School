/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 2/15/2022 6:57 PM
* Modifications: N/A
**************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
typedef bool(*FunctionPointer)();
#include "Graph.h"
#include "Exception.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
#include <crtdbg.h>
#include <conio.h>

const char* NAMES[] = { "Kyle", "Brit", "Seth", "Alex", "Josh", "Kian",
"Kate", "Terry", "Ann", "Elaine", "Stephanie", "Wanda", "Oscar",
"Oliver", "Tobey" };
const int NUM_NAMES = 15;
const int NUM_SIZE = 10;
const int NUM_EXTRACT = 4;
// Test function declaration
bool test_default_ctor();
bool test_copy_ctor();
bool test_op_equal();
bool test_is_empty();
bool test_insert();
bool test_insert_duplicate();
bool test_delete_vertex();
bool test_graph_size();
bool test_insert_edge_missing_vertex();
bool test_delete_edge_empty_graph();
bool test_delete_vertex_empty_graph();

FunctionPointer test_functions[] = { test_default_ctor, test_copy_ctor, test_op_equal, test_is_empty, test_insert, test_insert_duplicate,
									test_delete_vertex, test_graph_size, test_insert_edge_missing_vertex, test_delete_edge_empty_graph, 
									test_delete_vertex_empty_graph };

void Display(string data);
void Display(int data);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int failed_tests = 0;
	// Run the test functions
	for (FunctionPointer func : test_functions)
	{
		if (func())
		{
			cout << "passed\n";
		}
		else
		{
			failed_tests++;
			cout << "***** failed *****\n";
		}
	}
	if (failed_tests > 0)
		cout << "\nYou have " << failed_tests << " failed tests";
	else
		cout << "\nAll tests passed! Good job!";
	cout << "\nPress Any Key to Exit";
	cin.get();

	return 0;
}

bool test_default_ctor()
{
	bool pass = false;
	Graph<int, int> graph;
	if (graph.IsEmpty())
		pass = true;
	cout << "Default ctor test ";
	return pass;
}
bool test_copy_ctor()
{
	bool pass = true;
	Graph<int, int> test_graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		test_graph.InsertVertex(i);
	Graph<int, int> graph_test(test_graph);
	// Check data integrity
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if (graph_test.FindVertex(i) == test_graph.FindVertex(i))
			pass = false;
	}
	cout << "Copy ctor test ";
	return pass;
}
bool test_op_equal()
{
	bool pass = true;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		graph.InsertVertex(i);
	Graph<int, int> graphlhs;
	graphlhs = graph;
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if (graph.FindVertex(i) == graphlhs.FindVertex(i))
			pass = false;
	}
	cout << "Op Equals test ";
	return pass;
}
bool test_is_empty()
{
	bool pass = true;
	Graph<int, int> full_graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		full_graph.InsertVertex(i);
	Graph<int, int> empty_graph;
	if (full_graph.IsEmpty())
		pass = false;
	if (!empty_graph.IsEmpty())
		pass = false;
	cout << "isEmpty test ";
	return pass;
}
bool test_insert()
{
	bool pass = true;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		graph.InsertVertex(i);
	if (graph.IsEmpty())
		pass = false;
	cout << "Insert Vertex test ";
	return pass;
}
bool test_insert_duplicate()
{
	bool pass = false;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		graph.InsertVertex(i);
	try
	{
		graph.InsertVertex(1);
	}
	catch(Exception& exception)
	{
		exception.getMessage();
		pass = true;
	}
	cout << "Insert duplicate test ";
	return pass;
}
bool test_delete_vertex()
{
	bool pass = true;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
		graph.InsertVertex(i);
	for (int i = 0; i < NUM_SIZE; ++i)
		graph.DeleteVertex(i);
	if (!graph.IsEmpty())
		pass = false;
	cout << "Delete test ";
	return pass;
}
bool test_graph_size()
{
	bool pass = true;
	int count = 0;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		graph.InsertVertex(i);
		count++;
	}
	if (graph.GraphSize() != count)
		pass = false;
	cout << "Graph size test ";
	return pass;
}
bool test_insert_edge_missing_vertex()
{
	bool pass = false;
	int count = 0;
	Graph<int, int> graph;
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		graph.InsertVertex(i);
	}
	try
	{
		graph.InsertEdge(5, 38, 10, 10);
	}
	catch (Exception& exception)
	{
		exception.getMessage();
		pass = true;
	}
	cout << "Insert edge to missing vertex test ";
	return pass;
}
bool test_delete_edge_empty_graph()
{
	bool pass = false;
	Graph<int, int> graph;
	try
	{
		graph.DeleteEdge(10, 10, 10, 10);
	}
	catch (Exception& exception)
	{
		exception.getMessage();
		pass = true;
	}
	cout << "Delete edge from empty graph test ";
	return pass;
}
bool test_delete_vertex_empty_graph()
{
	bool pass = false;
	Graph<int, int> graph;
	try
	{
		graph.DeleteVertex(10);
	}
	catch (Exception& exception)
	{
		exception.getMessage();
		pass = true;
	}
	cout << "Delete vertex from empty graph test ";
	return pass;
}
void Display(string data)
{
	cout << data << endl;
}

void Display(int data)
{
	cout << data << endl;
}