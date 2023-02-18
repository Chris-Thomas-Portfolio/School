#include <iostream>
using std::cout;
using std::endl;
#include "Car.h"

Car::Car() : m_engine(), m_make()
{
	cout << "Car Default CTOR Called...." << endl;
}

Car::Car(Engine engine, String make) : m_engine(engine), m_make(make)
{ 
	cout << "Car Two Arg CTOR Called...." << endl;
}

Car::Car(const Car& copy) : m_engine(copy.m_engine), m_make(copy.m_make)
{ 
	cout << "Car Copy Constructor Called...." << endl;
}

Car& Car::operator=(const Car& rhs)
{
	cout << "Car Operator = Called...." << endl;

	if (this != &rhs)
	{
		m_engine = rhs.m_engine;
		m_make = rhs.m_make;
	}

	return *this;
}

Car::~Car()
{ 
	cout << "Car DTOR Called...." << endl;
}

void Car::setEngine(Engine engine)
{ 
	m_engine = engine;
}

Engine Car::getEngine()
{
	return m_engine;
}

void Car::setMake(String make)
{ 
	m_make = make;
}

String Car::getMake()
{
	return m_make;
}

void Car::Display()
{
	cout << "The cars make is " << m_make.GetString() << endl;
	cout << "The cars engine has " << m_engine.getCyl() << " cylinders" << endl;
	cout << "The cars engine is made by " << m_engine.getManf().GetString() << endl;
}
