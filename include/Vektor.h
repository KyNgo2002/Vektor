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

	// Helper functions
	unsigned size();
	unsigned capacity();
	unsigned empty();
	void print(char delimitter);

	// Modifiers
	unsigned push_back(int val);
	int pop_back();
	void clear();

	// Operators
	int operator[](unsigned index);
	
};

