#include "../include/Vektor.h"
#include <iostream>

Vektor::Vektor() : m_arr( nullptr ), m_size( 0 ), m_capacity( 10 ) {
	
}

Vektor::Vektor(int size) {
	assert(size >= 0);
	m_size = size;
	if (size <= 0) {
		m_size = 0;
		m_capacity = 10;
	}
	else
		m_capacity = m_size * 2;

	m_arr = new int[m_capacity];
	memset(m_arr, 0, m_capacity * sizeof(int));
}

Vektor::Vektor(int size, int defaultValue) : m_size(size), m_capacity(size * 2) {
	assert(size >= 0);
	m_arr = new int[m_capacity];
	for (unsigned i = 0; i < m_size; ++i)
		m_arr[i] = defaultValue;
}

Vektor::Vektor(const Vektor& other) : m_size (other.m_size), m_capacity (other.m_capacity), m_arr(new int[other.m_capacity]){
	assert(m_capacity >= m_size);
	for (unsigned i = 0; i < m_size; ++i) 
		this->m_arr[i] = other.m_arr[i];
}

Vektor::~Vektor() {
	if (m_arr)
		delete[] m_arr;
	m_arr = nullptr;
}

unsigned Vektor::size() const {
	return m_size;
}

unsigned Vektor::capacity() const {
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
		for (unsigned i = 0; i < m_size; ++i)
			newArr[i] = m_arr[i];
		delete[] m_arr;
		m_arr = newArr;
	}
}

int Vektor::operator[](unsigned index) {
	assert(index < m_size);
	assert(index >= 0);
	return m_arr[index];
}

bool Vektor::operator==(Vektor& vektor) {
	if (m_size != vektor.size()) return false;
	for (unsigned i = 0; i < m_size; ++i) 
		if (m_arr[i] != vektor[i]) 
			return false;
	return true;
}

Vektor& Vektor::operator=(Vektor& other) {
	// Self Assignment check
	if (this != &other) {
		delete[] m_arr;

		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_arr = new int[m_capacity];
		
		assert(m_capacity >= m_size);

		for (unsigned i = 0; i < m_size; ++i)
			m_arr[i] = other.m_arr[i];
	}
	return *this;
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



















