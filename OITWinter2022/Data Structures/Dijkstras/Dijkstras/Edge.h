/*************************************************************
* Author: Chris Thomas
* Filename: Edge.h
* Date Created: 2/15/2022 6:57 PM
* Modifications: N/A
**************************************************************/
/*************************************************************
* Manager Functions:
*	Edge();
*		Creates a default Edge object.
*	~Edge();
*		Destructs Edge object.
*	Edge(E data);
*		1 arg c'tor.
*	Edge(const Edge<V, E>& copy);
*		Copy constructor for Edge.
*	Edge<V, E> operator = (const Edge<V, E>& rhs);
*		op = for Edge.
*	Edge(Vertex<V, E>* destination, E edge, int weight);
*		3 arg constructor for Edge.
*	bool operator == (const Edge<V, E>& rhs) const;
*		Overloaded compare operator for Edge.
* Methods:
*
*
* ************************************************************/
#pragma once
#include <list>
using std::list;
template <typename V, typename E>
class Graph;
template <typename V, typename E>
class Vertex;
template <typename V, typename E>
class Edge
{
	friend class Vertex<V, E>;
	friend class Graph<V, E>;
public:
	Edge();
	~Edge();
	Edge(E data);
	Edge(const Edge<V, E>& copy);
	Edge<V, E> operator = (const Edge<V, E>& rhs);
	Edge(Vertex<V, E>* destination, E edge, int weight);
	bool operator == (const Edge<V, E>& rhs) const;
	E GetData();
	int GetWeight();
	Vertex<V, E>* GetDestination();
private:
	Vertex<V, E>* m_destination;
	int m_weight;
	E m_data;
};

/**********************************************************************
* Purpose: This is the default constructor for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a default Edge.
*
***********************************************************************/

template<typename V, typename E>
inline Edge<V, E>::Edge() : m_destination(nullptr), m_weight(0), m_data()
{ }

/**********************************************************************
* Purpose: This is the D'tor for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Destructs a Edge.
*
***********************************************************************/

template<typename V, typename E>
inline Edge<V, E>::~Edge()
{ }

/**********************************************************************
* Purpose: This is the 1 arg constructor for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates an Edge with specified data.
*
***********************************************************************/

template<typename V, typename E>
inline Edge<V, E>::Edge(E data) : m_data(data)
{ }

/**********************************************************************
* Purpose: This is the copy constructor for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a copy of an Edge.
*
***********************************************************************/

template<typename V, typename E>
inline Edge<V, E>::Edge(const Edge<V, E>& copy) : m_destination(copy.m_destination), m_weight(copy.m_weight), m_data(copy.m_data)
{ }

/**********************************************************************
* Purpose: This is the operator = for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates a copy of an Edge on the rhs.
*
***********************************************************************/

template<typename V, typename E>
inline Edge<V, E> Edge<V, E>::operator=(const Edge<V, E>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_destination = rhs.m_destination;
		m_weight = rhs.m_weight;
	}
	return *this;
}
/**********************************************************************
* Purpose: This is the 3 arg constructor for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates an Edge with specified data.
*
***********************************************************************/


template<typename V, typename E>
inline Edge<V, E>::Edge(Vertex<V, E>* destination, E edge, int weight)
{
	m_destination = destination;
	m_data = edge;
	m_weight = weight;
}

/**********************************************************************
* Purpose: This is the overloaded compare operator for the Edge class.
*
* Precondition:	N/A.
*
* Postcondition: Creates compares 2 Edges to see if they are equal.
*
***********************************************************************/

template<typename V, typename E>
inline bool Edge<V, E>::operator == (const Edge<V, E>& rhs) const
{
	if (m_data == rhs.m_data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename V, typename E>
inline E Edge<V, E>::GetData()
{
	return m_data;
}

template<typename V, typename E>
inline int Edge<V, E>::GetWeight()
{
	return m_weight;
}

template<typename V, typename E>
inline Vertex<V, E>* Edge<V, E>::GetDestination()
{
	return m_destination;
}
