/*************************************************************
* Author: Chris Thomas
* Filename: Stub.cpp
* Date Created: 6/4/2022 11:49 AM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 12 Dijkstras
*
* Overview: This algorithm finds the shortest path to a destination.
*
*
* Input: The graph is made from a text file and the start and destination Inputs
*				 come from the user.
*
*
* Output: Output is the complete path to the destination from the starting
*				  location with the estimated time of travel.
*
*
**************************************************************/
#include <iostream>
using std::cout;
using std::cin;
#include "Graph.h"
#include "Exception.h"
#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ios;
#include <sstream>
using std::stringstream;

void Dijkstras(Graph<string, string> map, string start, string end);
bool Done(Graph<string, string> map, vector<string> names, bool done);
void Time(float traveltime);

int main()
{
	Graph<string, string> map;
	ifstream newfile("assign13.txt");
	if (newfile.is_open())					//checking whether the file is open
	{
		string tp;
		string one;
		vector<string> v;
		while (getline(newfile, tp))		//read data from file object and put it into string.
		{
			stringstream s_stream(tp);

			while (s_stream.good())
			{
				getline(s_stream, one, ',');
				v.push_back(one);
			}
			for (int i = 0; i < 2; i++)
			{
				try
				{
					map.InsertVertex(v[i]);
				}
				catch (Exception& exception)				//exception handling for multiple vertices
				{

				}
			}
			int miles = stoi(v[3]);
			map.InsertEdge(v[0], v[1], v[2], miles);
			v.clear();
		}
		newfile.close();					//close the file object.
	}
	string start;
	string end;
	cout << "Enter your current location: ";		//get starting location
	getline(cin, start);
	cout << "Enter your destination: ";				//get destination
	getline(cin, end);
	Dijkstras(map, start, end);						//call Dijkstras

	return 0;
}

void Dijkstras(Graph<string, string> map, string start, string end)
{
	try
	{
		map.FindVertex(start);
	}
	catch (Exception& exception)				//exception handling for multiple vertices
	{
		exit(1);
	}
	try
	{
		map.FindVertex(end);
	}
	catch (Exception& exception)				//exception handling for multiple vertices
	{
		exit(1);
	}
	//setup all the variables used in Dijkstras
	Vertex<string, string>* temp = nullptr;
	Vertex<string, string>* next = nullptr;
	vector<int> distance(map.GraphSize());
	vector<string> names(map.GraphSize());
	vector<float> time(map.GraphSize());
	vector<Vertex<string, string>> predecessor(map.GraphSize());
	list<Vertex<string, string>> verts = map.GetVertices();
	int current_vertex = 0;
	float traveltime = 0.0;
	bool done = false;
	int i = 0;
	for (int i = 0; i < map.GraphSize(); i++)							//setup my distance array
	{
		distance[i] = -1;
	}
	for (auto iter = verts.begin(); iter != verts.end(); ++iter)		//setup my names array
	{
		names[i] = iter->GetData();
		i++;
	}
	distance[map.FindIndex(start)] = 0;									//start at the index of the start in distance array
	next = map.FindVertex(start);										//set next to the start destination index
	while(Done(map, names, done) != true)
	{
		temp = next;													//set temp to next
		current_vertex = map.FindIndex(temp->GetData());				//get the current index
		list<Edge<string, string>> tempedge = temp->GetEdges();			//make a list of edges from temps edges
		for (auto itere = tempedge.begin(); itere != tempedge.end(); ++itere)//iterate through the edges
		{
			//make sure destination is not processed already
			if (itere->GetDestination()->GetProcessed() != true)
			{	//check if the weight of current edge is less than what is stored in array
				if (itere->GetWeight() + distance[map.FindIndex(temp->GetData())] < distance[map.FindIndex(itere->GetDestination()->GetData())]
					|| distance[map.FindIndex(itere->GetDestination()->GetData())] ==  -1)
				{
					//put new value in distance array / set the predecessor array to current vertex / put current weight in time array
					distance[map.FindIndex(itere->GetDestination()->GetData())] = itere->GetWeight() + distance[map.FindIndex(temp->GetData())];
					predecessor[map.FindIndex(itere->GetDestination()->GetData())] = temp->GetData();
					time[map.FindIndex(itere->GetDestination()->GetData())] = itere->GetWeight();
				}
			}
		}
		temp->SetProcessed(true); //set current vertex as processed

		if (temp->GetData() == end)//check if we are at our destination
		{
			done = true;			//set done to true
		}

		for (int i = 0; i < map.GraphSize(); ++i)
		{
			if (map.FindVertex(names[i])->GetProcessed() != true) //check if vertex is processed already
			{
				if (distance[i] > 0)								//if not make sure it is not our start
				{
					if (distance[i] < distance[current_vertex] || map.FindVertex(names[current_vertex])->GetProcessed() == true) //if the distance is less than current or current is processed set current to i
					{
						current_vertex = i;
					}
				}
			}
		}
		next = map.FindVertex(names[current_vertex]);		//set next to the vertex with the shortest distance
	}
	stack<string> path;									//create a stack to store shortest path
	string name;										//string for holding the vertex name
	int count = map.FindIndex(end);						//count is the index of the end of the path
	path.push(temp->GetData());							//add the current vertex to the stack
	if (predecessor[count].GetData() != "I-5")
	{
		traveltime = (time[count] / 55) + traveltime;	//calculate travel speed for first road
	}
	else
	{
		traveltime = (time[count] / 65) + traveltime;
	}
	while (predecessor[count].GetData() != start)			//iterate through entire predecessor array and put into stack
	{
		path.push(predecessor[count].GetData());
		count = map.FindIndex(predecessor[count].GetData());
		if (predecessor[count].GetData() != "I-5")
		{
			traveltime = (time[count] / 55) + traveltime;
		}
		else
		{
			traveltime = (time[count] / 65) + traveltime;
		}
	}
	path.push(predecessor[count].GetData());				//push the last predecessor onto stack
	cout << start;
	cout << " to ";
	cout << end << ": " << distance[map.FindIndex(end)] << " miles" << endl;
	while (path.empty() != true)
	{
		name = path.top();
		count = map.FindIndex(name);				//print out entire path
		path.pop();
		cout << name << endl;
	}
	Time(traveltime);
}

/**********************************************************************
* Purpose: Decide if the shortest path has been found.
*
* Precondition:	N/A.
*
* Postcondition: Returns true if shortest path is found else returns false.
*
***********************************************************************/

bool Done(Graph<string, string> map, vector<string> names, bool done)
{
	if(done == true)
	{
		return done;
	}
	else
	{
		done = true;
		for (int i = 0; i < map.GraphSize(); i++)
		{
			if (map.FindVertex(names[i])->GetProcessed() == false)
			{
				done = false;
				return done;
			}
		}
	}
	return done;
}

/**********************************************************************
* Purpose: Calculate travel time of the shortest path.
*
* Precondition:	N/A.
*
* Postcondition: Print out travel time for path.
*
***********************************************************************/

void Time(float traveltime)
{
	int hours = 0;
	int minutes = 0;
	int temp = 0;

	hours = traveltime;
	temp = (traveltime * 100) - (hours * 100);
	minutes = temp * 0.6;
	cout << "Time: " << hours << " hours " << minutes << " minutes" << endl;
}
