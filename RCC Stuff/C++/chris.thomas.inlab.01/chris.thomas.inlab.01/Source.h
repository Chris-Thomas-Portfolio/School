#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "Car.h"
#include "Engine.h"
#include "String.h"

void DisplayEngineVal(Engine engine);
void DisplayEngineRef(Engine& engine);
void DisplayEnginePTR(Engine* engine);
void DisplayEngineCRef(const Engine& engine);
Engine EngineCreate();
void DisplayCar(Car car);
Car CarCreate();
void DisplayArray(Engine ar[]);