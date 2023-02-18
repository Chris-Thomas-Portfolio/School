#pragma once
#include "Engine.h"
#include "String.h"

class Car {
public:
	Car();
	Car(Engine engine, String make);
	Car(const Car& copy);
	Car& operator =(const Car& rhs);
	~Car();
	void setEngine(Engine engine);
	Engine getEngine();
	void setMake(String make);
	String getMake();
	void Display();
private:
	Engine m_engine;
	String m_make;
};
