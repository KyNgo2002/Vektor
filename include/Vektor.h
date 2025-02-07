#pragma once
#include <cassert>

class Vektor {
private:
	int* m_arr;
	unsigned m_size;
	unsigned m_capacity;

public:
	// Constructors/Destructors
	Vektor();
	Vektor(unsigned size);
	Vektor(unsigned size, unsigned defaultValue);
	~Vektor();

	// Helper functions
	unsigned size();
	unsigned capacity();
	bool empty();
	void print(char delimitter);

	// Modifiers
	unsigned push_back(int val);
	int pop_back();
	void clear();
	void reserve(unsigned capacity);
	//void sort();

	// Operators/Accessors
	int operator[](unsigned index);
	int front();
	int back();
	int* data();

	// Searchers
	int* max_element();
	int* min_element();
	
};

