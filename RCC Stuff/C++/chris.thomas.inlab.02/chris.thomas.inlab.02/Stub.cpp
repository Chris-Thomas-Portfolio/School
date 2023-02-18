#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Engine.h"
#include "Car.h"
#include "Stub.h"

int main()
{
	Engine eng1;
	Engine eng2(4, "Toyota");
	Engine* ptr;
	Engine Ray[3]{ eng2, eng2, eng2 };
	Engine copy = eng2;
	Engine* ptr2 = new Engine;
	DisplayEngineVal(eng2);
	DisplayEngineRef(eng2);
	DisplayEnginePTR(&eng2);
	DisplayArray(Ray);
	DisplayEngineCRef(eng2);
	Engine create = EngineCreate();
	DisplayEngineRef(create);
	delete ptr2;
	Car car1;
	Car car2(eng2, "Carola");
	DisplayCar(car2);
	Car car3 = CarCreate();
	DisplayCar(car3);
	return 0;
}

void DisplayEngineVal(Engine engine)
{
	engine.Display();
}

void DisplayEngineRef(Engine& engine)
{
	engine.Display();
}

void DisplayEnginePTR(Engine* engine)
{
	engine->Display();
}

void DisplayEngineCRef(const Engine& engine)
{
	engine.Display();
}

Engine EngineCreate()
{
	int cyl = 0;
	char manf[40] = "\0";
	cout << "What is the manufacturer of the engine? ";
	cin >> manf;
	cout << "How many cylinders does the engine have? ";
	cin >> cyl;
	Engine newEngine(cyl, manf);
	return newEngine;
}

void DisplayCar(Car car)
{
	car.Display();
}

Car CarCreate()
{
	char make[40] = "\0";
	Engine carEngine = EngineCreate();
	cout << "What is the make of the car? ";
	cin >> make;
	Car carCreate(carEngine, make);

	return carCreate;
}

void DisplayArray(Engine ar[])
{
	for (int i = 0; i < 3; i++)
	{
		ar[i].Display();
	}
}