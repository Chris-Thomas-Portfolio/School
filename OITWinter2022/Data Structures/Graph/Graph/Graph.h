/*************************************************************
* Author: Chris Thomas
* Filename: Graph.h
* Date Created: 2/15/2022 6:57 PM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 11 Graph
*
* Overview: This class creates a graph.
*
*
* Input: Inputs all come from the consumer.
*
*
* Output: No specific outputs as we are creating a binary search tree for data storage.
*
*
**************************************************************/
/*************************************************************
* Manager Functions:
*	Graph();
*		Creates a default graph object.
*	Graph(V data);
*		Creates a graph object with V data.
*	~Graph();
*		Graph d'tor
*	Graph(const Graph<V, E>& copy);
*		Copy constructor for graph.
* 
* Methods:
*	void InsertVertex(V data);
*		Inserts a Vertex into the graph.
*	void DeleteVertex(V data);
*		Delete a Vertex from the graph.
* 	Vertex<V, E>* FindVertex(V data);
*		Finds vertex of given data and returns a pointer to it.
*	void DeleteEdge(V from, V to, E edge, int weight);
*		Deletes the specified edge from the Graph.
*	bool IsEmpty();
*		Returns a bool of true if Graph is empty.
*	void DepthFirst(void(*visit)(V data));
*		Does a depth first traversal calling the visit function at each vertex.
*	void BreadthFirst(void(*visit)(V data));
*		Does a breadth first traversal calling the visit function at each vertex.
*	void ProcessedSetFalse();
*		Sets all m_processed to false.
*	void ProcessedSetTrue();
*		Sets all m_processed to true.
*	int	FindIndex(V data);
*		Find specified vertex and return an int value to be used in an array.
*	int GraphSize();
*		Returns the size of Graph.
* ************************************************************/
#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "Exception.h"
#include <list>
#include <stack>
#include <queue>
using std::list;
using std::stack;
using std::queue;

template <typename V, typename E>
class Graph
{
public:
	Graph();
	Graph(V data);
	~Graph();
	Graph(const Graph<V, E>& copy);
	Graph<V, E> operator = (const Graph<V, E>& rhs);
	void InsertVertex(V data);
	void DeleteVertex(V data);
	void InsertEdge(V to, V from, E edge, int weight);
	Vertex<V, E>* FindVertex(V data);
	void DeleteEdge(V from, V to, E edge, int weight);
	bool IsEmpty();
	void DepthFirst(void(*visit)(V data));
	void BreadthFirst(void(*visit)(V data));
	void ProcessedSetFalse();
	void ProcessedSetTrue();
	int	FindIndex(V data);
	int GraphSize();
private:
	list<Vertex<V, E>> m_vertices;
};

/**********************************************************************
* Purpose: This is the default constructor for the Graph class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Graph.
*
***********************************************************************/

template<typename V, typename E>
inline Graph<V, E>::Graph() 
{ }

/**********************************************************************
* Purpose: Creates a Graph with the given argument.
*
* Precondition:	N/A.
*
* Postcondition: Creates a Graph. 
*
***********************************************************************/

template<typename V, typename E>
inline Graph<V, E>::Graph(V data) : m_vertices(data)
{
}

/**********************************************************************
* Purpose: Deletes the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Deletes Graph.
*
***********************************************************************/

template<typename V, typename E>
inline Graph<V, E>::~Graph()
{ }

/**********************************************************************
* Purpose: To create a copy of the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Creates a copy of the a Graph.
*
***********************************************************************/

template<typename V, typename E>
inline Graph<V, E>::Graph(const Graph<V, E>& copy) : m_vertices(copy.m_vertices)
{ 
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		for (auto itere = iter->m_edges.begin(); itere != iter->m_edges.end(); ++itere)
		{
			itere->m_destination = FindVertex(itere->m_destination->m_data);
		}
	}
}

/**********************************************************************
* Purpose: Op equals for Graph.
*
* Precondition: A Graph.
*
* Postcondition: If the lhs is not already equal to the rhs copy it.
*
***********************************************************************/

template<typename V, typename E>
inline Graph<V, E> Graph<V, E>::operator=(const Graph<V, E>& rhs)
{
	if (this != &rhs)
	{
		m_vertices = rhs.m_vertices;
	}
	return *this;
}

/**********************************************************************
* Purpose: To add a Vertex to the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Adds the Vertex to the Graph.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::InsertVertex(V data)
{
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		if (*iter == data)
		{
			throw Exception("Already in Graph");
		}
	}
	m_vertices.push_back(data);							//add Vertex to list	
}

/**********************************************************************
* Purpose: Delete a Vertex from the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Deletes a Vertex from the Graph.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::DeleteVertex(V data)
{
	Vertex<V, E>* target = nullptr;
	target = FindVertex(data);																	//find the vertex and set a pointer to it
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		for (auto itere = iter->m_edges.begin(); itere != iter->m_edges.end(); ++itere)			//iterate through m_vertices and its edges
		{
			if (itere->m_destination == target)													//if we find an edge pointing to the vertex that is to be deleted set it to nullptr
			{
				itere->m_destination = nullptr;
			}
		}
	}
	m_vertices.remove(data);																	//remove vertex from list
}

/**********************************************************************
* Purpose: Add an Edge to the Graph.
*
* Precondition: A Graph.
*
* Postcondition: An Edge will be added to the Graph.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::InsertEdge(V to, V from, E edge, int weight)
{
	Vertex<V, E>* tov = nullptr;
	Vertex<V, E>* fromv = nullptr;

	fromv = FindVertex(from);													//find the from vertex and set a pointer to it
	tov = FindVertex(to);														//find the to vertex and set a point to it

	if (tov != nullptr && fromv != nullptr)
	{
		Edge<V, E> to(tov, edge, weight);										//create a new edge for to
		Edge<V, E> from(fromv, edge, weight);									//create a new edge for from
		
		fromv->m_edges.push_back(to);											//add them to the m_edges list
		tov->m_edges.push_back(from);
	}
	else
	{
		throw Exception("Vertex not found");
	}
}

/**********************************************************************
* Purpose: Find a specific Vertex in the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Returns a pointer to the specified Vertex.
*
***********************************************************************/

template<typename V, typename E>
Vertex<V, E>* Graph<V, E>::FindVertex(V data)
{
	Vertex<V, E>* target = nullptr;
	bool found = false;

	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)				//search the Graph for the data
	{
		if (*iter == data)			
		{
			found = true;																//if found set found to true
			target = &(*iter);															//set pointer to the Vertex address
		}
	}

	if (found == false)
	{
		throw Exception("Not found");
	}
	else
	{
		return target;																	//return the pointer
	}
}

/**********************************************************************
* Purpose: Delete a specific Edge from the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Finds and removes specified Edge.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::DeleteEdge(V from, V to, E edge, int weight)
{
	Edge<V, E>* target = nullptr;
	bool found = false;
	Vertex<V, E>* tov = FindVertex(to);
	Vertex<V, E>* fromv = FindVertex(from);


	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)																//iterate through m_vertices
	{
		for (auto itere = iter->m_edges.begin(); itere != iter->m_edges.end(); ++itere)													//iterate through each vertices m_edges
		{
			if (itere->m_destination == tov || itere->m_destination == fromv && itere->m_data == edge && itere->m_weight == weight)		//if the to or from is found and matches the edge and weight set found to true and point to it
			{
				found = true;
				target = &(*itere);
			}
		}
		if (found == true)
		{
			iter->m_edges.remove(*target);																								//remove the edge from the list
		}
	}
	if (found == false)
	{
		throw Exception("Edge not found");
	}
}

/**********************************************************************
* Purpose: To check if Graph is empty.
*
* Precondition: A Graph.
*
* Postcondition: Returns true if graph is empty false if it is not empty.
*
***********************************************************************/

template<typename V, typename E>
inline bool Graph<V, E>::IsEmpty()
{
	return m_vertices.empty();
}

/**********************************************************************
* Purpose: To traverse the Graph fromt he bottom up.
*
* Precondition: A Graph.
*
* Postcondition: Traverses the Graph from the bottom up.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::DepthFirst(void(*visit)(V data))
{
	stack<Vertex<V, E>*> stck;
	Vertex<V, E>* temp = nullptr;

	stck.push(&m_vertices.front());																//push first node
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		temp = stck.top();																		//pop front of stack
		temp->m_processed = true;
		stck.pop();
		for (auto itere = temp->m_edges.begin(); itere != temp->m_edges.end(); ++itere)
		{
			if (itere->m_destination->m_processed != true)
			{
				stck.push(itere->m_destination);
				itere->m_destination->m_processed = true;
			}
		}
		visit(temp->m_data);																	//visit
	}
	ProcessedSetFalse();
}

/**********************************************************************
* Purpose: To traverse the Graph fromt he top down.
*
* Precondition: A Graph.
*
* Postcondition: Traverses the Graph from the top down.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::BreadthFirst(void(*visit)(V data))
{
	queue<Vertex<V, E>*> que;
	Vertex<V, E> *temp = nullptr;

	que.push(&m_vertices.front());																//enque first node
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		temp = que.front();																		//pop front of queue
		temp->m_processed = true;
		que.pop();
		for (auto itere = temp->m_edges.begin(); itere != temp->m_edges.end(); ++itere)
		{
			if (itere->m_destination->m_processed != true)
			{
				que.push(itere->m_destination);
				itere->m_destination->m_processed = true;
			}
		}
		visit(temp->m_data);																	//visit
	}
	ProcessedSetFalse();
}

/**********************************************************************
* Purpose: Sets all m_processed to false.
*
* Precondition: A Graph.
*
* Postcondition: Traverses m_vertices and sets each to m_processed to false.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::ProcessedSetFalse()
{
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		iter->m_processed = false;
	}
}

/**********************************************************************
* Purpose: Sets all m_processed to true.
*
* Precondition: A Graph.
*
* Postcondition: Traverses m_vertices and sets each to m_processed to true.
*
***********************************************************************/

template<typename V, typename E>
inline void Graph<V, E>::ProcessedSetTrue()
{
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
	{
		iter->m_processed = false;
	}
}

/**********************************************************************
* Purpose: Return an index position for data.
*
* Precondition: A Graph.
*
* Postcondition: Traverses the Graph while keeping a count until it finds
*				specified data and returns the count.
*
***********************************************************************/

template<typename V, typename E>
inline int Graph<V, E>::FindIndex(V data)
{
	int count = 0;
	bool found = false;
	for (auto iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)				//search the Graph for the data
	{
		if (*iter == data)
		{
			found = true;
			return count;
		}
		++count;
	}
	throw Exception("Vertex not found");
}

/**********************************************************************
* Purpose: Give the size of the Graph.
*
* Precondition: A Graph.
*
* Postcondition: Returns the size of the Graph.
*
***********************************************************************/

template<typename V, typename E>
inline int Graph<V, E>::GraphSize()
{
	return m_vertices.size();
}
