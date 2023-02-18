#include <iostream>
using std::cout;
using std::endl;
#include "Engine.h"
#include "String.h"

Engine::Engine() : m_cyl(), m_manf()
{ 
	cout << "Engine Default CTOR Called...." << endl;
}

Engine::Engine(int cyl, const char *  manf) : m_cyl(cyl), m_manf(manf)
{
	cout << "Engine Two Arg CTOR Called...." << endl;
}

Engine::Engine(const Engine& copy) : m_cyl(copy.m_cyl), m_manf(copy.m_manf)
{
	cout << "Engine Copy Constructor Called...." << endl;
}

Engine& Engine::operator=(const Engine& rhs)
{
	cout << "Engine Operator = Called...." << endl;

	if (this != &rhs)
	{
		m_cyl = rhs.m_cyl;
		m_manf = rhs.m_manf;
	}

	return *this;
}

Engine::~Engine()
{
	cout << "Engine DTOR Called...." << endl;
}

void Engine::setCyl(int cyl)
{
	m_cyl = cyl;
}

int Engine::getCyl()
{
	return m_cyl;
}

void Engine::setManf(String * manf)
{
	if (manf == nullptr)
	{
		m_manf = *manf;
	}
}

String Engine::getManf()
{
	return m_manf;
}

void Engine::Display() const
{
	cout << "Number of Cylinders in Engine " << m_cyl << endl;
	cout << "Engine Manufacturer " << m_manf.GetString() << endl;
}
