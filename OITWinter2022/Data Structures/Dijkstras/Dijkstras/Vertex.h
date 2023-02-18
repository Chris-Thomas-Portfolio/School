/*************************************************************
* Author: Chris Thomas
* Filename: Vertex.h
* Date Created: 2/15/2022 6:57 PM
* Modifications: N/A
**************************************************************/
/*************************************************************
* Manager Functions:
*	Vertex();
*		Creates a default Vertex object.
*	~Vertex();
*		Destructs Vertex object.
*	Vertex(V data);
*		1 arg c'tor.
*	Vertex(const Vertex<V, E>& copy);
*		Copy constructor for Vertex.
*	Vertex<V, E> operator = (const Vertex<V, E>& rhs);
*		op = for Vertex.
*	bool operator == (const Vertex<V, E>& rhs) const;
*		Overloaded compare operator for Vertex.
* Methods:
*
*
* ************************************************************/
#pragma once
#include <iostream>
#include <list>
using std::list;

template <typename V, typename E>
class Graph;
template <typename V, typename E>
class Edge;
template <typename V, typename E>
class Vertex
{
	friend class Edge<V, E>;
	friend class Graph<V, E>;
public:
	Vertex();
	Vertex(V data);
	~Vertex();
	Vertex(const Vertex<V, E>& copy);
	Vertex<V, E> operator = (const Vertex<V, E>& rhs);
	bool operator == (const Vertex<V, E>& rhs) const;
	void SetProcessed(bool processed);
	bool GetProcessed();
	V GetData();
	list<Edge<V, E>> GetEdges();
private:
	V m_data;
	bool m_processed;
	list<Edge<V, E>> m_edges;
};

/**********************************************************************
* Purpose: This is the default constructor for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Vertex.
*
***********************************************************************/

template<typename V, typename E>
inline Vertex<V, E>::Vertex() : m_data(), m_processed(false), m_edges()
{ }

/**********************************************************************
* Purpose: This is the 1 arg constructor for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Creates an Vertex with specified data.
*
***********************************************************************/

template<typename V, typename E>
inline Vertex<V, E>::Vertex(V data) : m_data(data), m_processed(false), m_edges()
{ }

/**********************************************************************
* Purpose: This is the D'tor for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Destructs a Vertex.
*
***********************************************************************/

template<typename V, typename E>
inline Vertex<V, E>::~Vertex()
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a copy of an Vertex.
*
***********************************************************************/

template<typename V, typename E>
inline Vertex<V, E>::Vertex(const Vertex<V, E>& copy) : m_data(copy.m_data), m_processed(copy.m_processed), m_edges(copy.m_edges)
{ }

/**********************************************************************
* Purpose: This is the operator = for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a copy of an Vertex on the rhs.
*
***********************************************************************/

template<typename V, typename E>
inline Vertex<V, E> Vertex<V, E>::operator=(const Vertex<V, E>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_processed = rhs.m_processed;
		m_edges = rhs.m_edges;
	}
	return *this;
}

/**********************************************************************
* Purpose: This is the overloaded compare operator for the Vertex class.
*
* Precondition:	N/A.
*
* Postcondition: Creates compares 2 Vertices to see if they are equal.
*
***********************************************************************/

template<typename V, typename E>
bool Vertex<V, E>::operator == (const Vertex<V, E>& rhs) const
{
	if (m_data == rhs.m_data)
		return true;
	else
		return false;
}

template<typename V, typename E>
inline void Vertex<V, E>::SetProcessed(bool processed)
{
	m_processed = processed;
}

template<typename V, typename E>
inline bool Vertex<V, E>::GetProcessed()
{
	return m_processed;
}

template<typename V, typename E>
inline V Vertex<V, E>::GetData()
{
	return m_data;
}

template<typename V, typename E>
inline list<Edge<V, E>> Vertex<V, E>::GetEdges()
{
	return m_edges;
}
