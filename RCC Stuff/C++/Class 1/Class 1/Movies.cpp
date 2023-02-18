#include <iostream>
using std::cout;
using std::endl;
#include "Movies.h"

Movies::Movies() : m_name(), m_genre(), m_length()
{
	cout << "Movies default CTOR called...." << endl;
}

Movies::Movies(string name, string genre, float length) : m_name(name), m_genre(genre), m_length(length)
{ 
	cout << "Movies Three Arg CTOR Called...." << endl;
}

Movies::Movies(const Movies& copy) : m_name(copy.m_name), m_genre(copy.m_genre), m_length(copy.m_length)
{ 
	cout << "Movies Copy Constructor Called...." << endl;
}

Movies::Movies(Movies&& copy) : m_name(copy.m_name), m_genre(copy.m_genre), m_length(copy.m_length)
{
	cout << "Movies Move Copy Constructor Called..." << endl;
}

Movies& Movies::operator=(const Movies& rhs)
{
	cout << "Movies Operator = Called...." << endl;
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Delete the lhs
		// No dynamic memory so don't need to delete

		// 3. Perform deep copy
		m_name = rhs.m_name;
		m_genre = rhs.m_genre;
		m_length = rhs.m_length;
	}

	// 4. Return a reference to the class
	return *this;
}

Movies&& Movies::operator=(Movies&& rhs)
{
	return Movies && ();
}

Movies::~Movies()
{ 
	cout << "Movies DTOR Called...." << endl;
}

void Movies::Display()
{
	cout << "Movie Name: " << m_name
		<< "\nMovie Genre: " << m_genre
		<< "\nMovie Length: " << m_length << " minutes" << endl;
}

string Movies::getName()
{
	return m_name;
}

void Movies::setName(string name)
{
	m_name = name;
}

string Movies::getGenre()
{
	return m_genre;
}

void Movies::setGenre(string genre)
{
	m_genre = genre;
}

float Movies::getLength()
{
	return m_length;
}

void Movies::setLength(float length)
{
	m_length = length;
}
