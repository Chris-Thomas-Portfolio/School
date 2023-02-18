/*************************************************************
* Author: Chris Thomas
* Filename: HashTable.h
* Date Created: 6/2/2022 11:20 AM
* Modifications: N/A
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 11 HashTable
*
* Overview: Create a templated Hash Table for storing data.
*
*
* Input: The input comes from the consumer for what data they want to be stored.
*
*
* Output: No specific outputs were created.
*
*
**************************************************************/
#pragma once
#include<vector>
using std::vector;
#include<list>
using std::list;
#include<utility>
using std::pair;
#include <string>
using std::string;
using std::begin;
#include "Exception.h"

struct Book
{
	string m_title;
	string m_author;
	int m_pages;
};
template <typename K, typename V>
class Hash
{
public:
	Hash();
	Hash(int buckets);
	Hash(const Hash<K, V>& copy);
	Hash(Hash<K, V>&& copy);
	Hash<K, V> operator = (const Hash<K, V>& rhs);
	Hash<K, V> operator = (Hash<K, V>&& rhs);
	~Hash();

	void Insert(K key, V value);
	void Delete(K key);
	void Traverse(void (*visit)(V value));
	void setHash(int (*hash)(K key));
	void setBucket(int bucket);
	int getBucket();

	V operator [] (K key);
private:
	vector<list<pair<K, V>>> m_table;
	int (*m_hash)(K key);
	int m_buckets;

	void reHash(int buckets);
};

/**********************************************************************
* Purpose: C'tor
*
* Precondition: None
*
* Postcondition: Creates a Hash with default values
*
************************************************************************/

template<typename K, typename V>
Hash<K, V>::Hash() : m_table(), m_hash(nullptr), m_buckets(0)
{ }

/**********************************************************************
* Purpose: 1-arg Constructor
*
* Precondition: None
*
* Postcondition: Creates Hash with size of argument
*
************************************************************************/

template<typename K, typename V>
Hash<K, V>::Hash(int buckets) : m_hash(nullptr), m_buckets(buckets)
{
	m_table.resize(buckets);
}

/**********************************************************************
* Purpose: Copy Constructor
*
* Precondition: None
*
* Postcondition: Performs a deep copy on Hash
*
************************************************************************/

template<typename K, typename V>
Hash<K, V>::Hash(const Hash<K, V>& copy) : m_table(copy.m_table), m_hash(copy.m_hash), m_buckets(copy.m_buckets)
{ }

/**********************************************************************
* Purpose: Move Constructor
*
* Precondition: None
*
* Postcondition: Performs a shallow copy on the Hash
*
************************************************************************/

template<typename K, typename V>
Hash<K, V>::Hash(Hash<K, V>&& copy) : m_table(copy.m_table), m_hash(copy.m_hash), m_buckets(copy.m_buckets)
{
	copy.m_hash = nullptr;
	copy.m_buckets = 0;
}

/**********************************************************************
* Purpose: Copy Assignment Operator
*
* Precondition: None
*
* Postcondition: Overloaded = operator 
*
************************************************************************/

template<typename K, typename V>
Hash<K, V> Hash<K, V>::operator=(const Hash<K, V>& rhs)
{
	if (this != &rhs)		//check for self assignment
	{
		m_hash = rhs.m_hash;
		m_buckets = rhs.m_buckets;

		m_table.resize(m_buckets);

		for (int i = 0; i < rhs.m_buckets; ++i)		//copy over all the information
			if (rhs.m_table[i].size() != 0)
				for (auto iter = rhs.m_table[i].begin(); iter != rhs.m_table[i].end(); iter++)
					m_table[i].emplace_back(iter->first, iter->second);
	}
	return *this;		//return hash
}

/**********************************************************************
* Purpose: Move Assignment Operator
*
* Precondition: None
*
* Postcondition: Overloaded = operator for shallow copies
*
************************************************************************/

template<typename K, typename V>
Hash<K, V> Hash<K, V>::operator=(Hash<K, V>&& rhs)
{
	if (this != &rhs)				//check for self assignment
	{
		m_hash = rhs.m_hash;
		m_buckets = rhs.m_buckets;

		m_table.swap(rhs.m_table);	//copy data over

		rhs.m_hash = nullptr;
		rhs.m_buckets = 0;
		rhs.m_table.clear();
	}
	return *this;					//return hash
}

/**********************************************************************
* Purpose: D'tor
*
* Precondition: None
*
* Postcondition: Gets rid of Hash
*
************************************************************************/

template<typename K, typename V>
Hash<K, V>::~Hash()
{
	m_hash = nullptr;
	m_buckets = 0;
}

/**********************************************************************
* Purpose: Inserts data into the hash table
*
* Precondition: Buckets must exist and so should a hash
*
* Postcondition: Iterates through the beginning of the Hash Table
*				 Replace the back of the table
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::Insert(K key, V value)
{
	//check for possible errors and throw exceptions
	if (m_hash == nullptr)
		throw Exception("No function");
	else if (m_buckets == 0)
		throw Exception("No buckets exist");

	int index;
	index = m_hash(key) % m_buckets;			//find proper index
	list<pair<K, V>>& bin = m_table[index];		//set bin to that index

	bool done = false;

	for (auto iter = begin(bin); iter != end(bin); ++iter)	//iterate through looking for proper key
	{
		if (iter->first == key)
		{
			done = true;
			iter->second = value;							//if first is the key then set second to the value
		}
	}
	if (!done)
	{
		bin.emplace_back(key, value);						//if not found add to back of list
	}
}

/**********************************************************************
* Purpose: Removes a particular element from the Hash table
*
* Precondition: Data must be in Hash Table
*
* Postcondition: Deletes specific key that matches given variable
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::Delete(K key)
{
	if (m_hash == nullptr)						//exception handling for no hash or no buckets
		throw Exception("No function");
	else if (m_buckets == 0)
		throw Exception("No buckets exist");

	int index;
	index = m_hash(key) % m_buckets;					//find proper index
	list<pair<K, V>>& bin = m_table[index];				//set bin to that index

	for (auto iter = begin(bin); iter != end(bin); ++iter)
	{
		if (iter->first == key)
		{
			iter = bin.erase(iter);						//when found erase
			return;
		}
	}
	throw Exception("Key not in list");
}

/**********************************************************************
* Purpose: Traverse the entire table of information.
*
* Precondition: Must have a Hash Table.
*	
*
* Postcondition: Prints all data in table.
*		
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::Traverse(void(*visit)(V value))
{
	for (int i = 0; i < m_buckets; i++)
	{
		if (m_table[i].size() != 0)			//check for empty table
		{
			for (auto iter = m_table[i].begin(); iter != m_table[i].end(); iter++)	//iterate through all datat
				visit(iter->second);												//call visit
		}
	}
}

/**********************************************************************
* Purpose: Sets member hash function to passed in function.
*
* Precondition: Must have a Hash Table.
*	
*
* Postcondition: Rehashes table information to refresh the table and its contents.
*		
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::setHash(int(*hash)(K key))
{
	
	m_hash = hash;				//set m_hash to variable passed in
	reHash(m_buckets);			//rehash
}

/**********************************************************************
* Purpose: Sets member buckets to passed in value.
*
* Precondition: Passed in value cann not be 0.
*	
*
* Postcondition: Rehashes table information to refresh the table and its contents.
*		
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::setBucket(int bucket)
{
	if (bucket == 0)
		throw Exception("Can't set buckets to 0");			//error checking
	m_buckets = bucket;										//set m_buckets value to given value
	reHash(m_buckets);										//rehash
}

/**********************************************************************
* Purpose: Returns member variable of buckets.
*
* Precondition: Must have a Hash Table
*
* Postcondition: Returns value of m_buckets
*
************************************************************************/

template<typename K, typename V>
int Hash<K, V>::getBucket()
{
	return m_buckets;
}

/**********************************************************************
* Purpose: Subcript Operator.
*
* Precondition: Key Value must exist and Table must be established.
*	
*
* Postcondition: Returns the second iteration of the Hash Table.
*	
*
************************************************************************/

template<typename K, typename V>
V Hash<K, V>::operator[](K key)
{
	if (m_buckets == 0)											//check for 0 buckets
		throw Exception("No buckets inserted");

	int index;
	index = m_hash(key) % m_buckets;							//find index
	list<pair<K, V>> block = m_table[index];					//set block to index
		
	for (int i = 0; i < m_buckets; i++)
		for (auto iter = block.begin(); iter != block.end(); iter++)		//iterate through to find key and return second
			if (iter->first == key)
				return iter->second;
	throw Exception("Key not in list");
}

/**********************************************************************
* Purpose: ReHashes Table for a reset Table.
*
* Precondition: Table must exist.
*	
*
* Postcondition: Table will be reset and reusable.
*	
*
************************************************************************/

template<typename K, typename V>
void Hash<K, V>::reHash(int buckets)
{
	if (m_hash == nullptr)							//error checking
		throw Exception("No function");

	vector<list<pair<K, V>>> temp;
	temp.resize(buckets);						//resize to value given

	for (int i = 0; i < m_buckets; ++i)
	{
		if (m_table[i].size() != 0)
		{
			for (auto iter = m_table[i].begin(); iter != m_table[i].end(); iter++)
			{
				int val = m_hash(iter->first) % buckets;			//iterate through setting val to iter->first
				temp[val].emplace_back(iter->first, iter->second);	//add to end of list
			}
		}
	}
	m_table = temp;												//set the table to our newly made table
}