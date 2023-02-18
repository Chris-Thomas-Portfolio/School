// Filename: func_declarations.h
// Contents: Function declarations for Example 15.4.9
#pragma once

#include "types.h"

void FillArray(Faculty *& ray, int & num_faculty);
void PrintArray(Faculty * ray, int num_faculty);
void WriteArrayToFile(Faculty * ray, int num_faculty);
void DeleteArray(Faculty *& ray, int & num_faculty);
void ReadArrayFromFile(Faculty *& ray, int & num_faculty);