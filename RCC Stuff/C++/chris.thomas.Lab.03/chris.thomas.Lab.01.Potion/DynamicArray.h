#pragma once
#include "Potion.h""
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const DynamicArray& copy);
	DynamicArray& operator=(const DynamicArray& rhs);
	~DynamicArray();
	int GetElements();
	void Insert(const Potion& to_add);
	void Delete(const Potion& to_delete);
	int Find(const Potion& target) const;
	void Display();
private:
	Potion* m_array;
	int m_elements;
};