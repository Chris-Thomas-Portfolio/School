#pragma once
#include <string>
using std::string;
class Movies
{
public:
	Movies();
	Movies(string name, string genre, float length);
	Movies(const Movies& copy);
	Movies& operator =(const Movies& rhs);
	~Movies();
	void Display();
	string getName();
	void setName(string name);
	string getGenre();
	void setGenre(string genre);
	float getLength();
	void setLength(float length);
private:
	string m_name;
	string m_genre;
	float m_length;
};

