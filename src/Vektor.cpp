#include "../include/Vektor.h"
#include <iostream>


Vektor::Vektor() : m_arr{ nullptr }, m_size( 0 ), m_capacity( 10 ) {

}

Vektor::Vektor(unsigned size) : m_size( size ), m_capacity( size * 2 ) {
	assert(size >= 0);
	m_arr = new int[m_capacity];
}

Vektor::Vektor(unsigned size, unsigned defaultValue) : m_size(size), m_capacity(size * 2) {
	assert(size >= 0);
	m_arr = new int[m_capacity];
	memset(m_arr, defaultValue, m_size * sizeof(unsigned));
}

Vektor::~Vektor() {
	delete[] m_arr;
	m_arr = nullptr;
}

unsigned Vektor::size() {
	return m_size;
}

unsigned Vektor::capacity() {
	return m_capacity;
}

bool Vektor::empty() {
	return m_size == 0;
}

void Vektor::print(char delimitter = ' ') {
	for (unsigned i = 0; i < m_size; ++i) {
		std::cout << m_arr[i];
		if (i != m_size - 1)  std::cout << delimitter;
	}
	std::cout << std::endl;
}

unsigned Vektor::push_back(int val) {
	if (m_size == m_capacity) {
		int* newArr = new int[(m_size + 5) * 2];
		for (unsigned i = 0; i < m_capacity; ++i) 
			newArr[i] = m_arr[i];
		m_capacity *= 2;
		delete[] m_arr;
		m_arr = newArr;
	}
	
	m_arr[m_size++] = val;
	return m_size;
}

int Vektor::pop_back() {
	assert(m_size > 0);
	return m_size--;
	
}

void Vektor::clear() {
	m_size = 0;
}

void Vektor::reserve(unsigned capacity) {
	if (capacity > m_capacity) {
		int* newArr = new int[capacity];
		for (int i = 0; i < m_size; ++i)
			newArr[i] = m_arr[i];
		delete[] m_arr;
		m_arr = newArr;
	}
}

void Vektor::sort() {

}

int Vektor::operator[](unsigned index) {
	assert(index < m_size);
	assert(index >= 0);
	return m_arr[index];
}

int Vektor::front() {
	assert(m_size > 0);
	return m_arr[0];
}

int Vektor::back() {
	assert(m_size > 0);
	return m_arr[m_size - 1];
}

int* Vektor::data() {
	return m_arr;
}

// Returns first instance of largest element in the vektor.
int* Vektor::max_element() {
	assert(m_size > 0);
	int maxElement = m_arr[0];
	int maxInd = 0;
	for (unsigned i = 1; i < m_size; ++i) {
		if (m_arr[i] > maxElement) {
			maxElement = m_arr[i];
			maxInd = i;
		}
	}
	return &m_arr[maxInd];
}

int* Vektor::min_element() {
	assert(m_size > 0);
	int minElement = m_arr[0];
	int minInd = 0;
	for (unsigned i = 1; i < m_size; ++i) {
		if (m_arr[i] > minElement) {
			minElement = m_arr[i];
			minInd = i;
		}
	}
	return &m_arr[minInd];
}



















