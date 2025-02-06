#pragma once
class Vektor {
private:
	int* m_arr;
	unsigned m_size;
	unsigned m_capacity;

public:
	// Constructors/Destructors
	Vektor();
	Vektor(unsigned size);

	// Helper functions
	unsigned size();
	unsigned capacity();
	unsigned empty();

	// Modifiers
	unsigned push_back(int val);
	int pop_back();

};

