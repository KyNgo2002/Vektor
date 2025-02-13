#pragma once
#include <cassert>
#include <iostream>


template <typename T>
class Vektor {
private:
	T* m_arr;
	unsigned m_size;
	unsigned m_capacity;

public:
	// Constructors/Destructors
	Vektor();
	Vektor(int size);
	Vektor(int size, T defaultValue);
	Vektor(const Vektor& other);
	Vektor(Vektor&& other) noexcept;

	~Vektor() noexcept;

	// Helper functions
	unsigned size() const;
	unsigned capacity() const;
	bool empty();
	void print(char delimitter = ' ');

	// Modifiers
	unsigned push_back(T val);
	T pop_back();
	void clear();
	void reserve(unsigned capacity);

	// Operators
	T operator[](unsigned index);
	bool operator==(Vektor& vektor);
	Vektor& operator=(Vektor& vektor);
	Vektor& operator=(Vektor&& vektor) noexcept;

	// Accessors
	T front();
	T back();
	T* data();

	// Searchers
	T* max_element();
	T* min_element();
};


template <typename T>
Vektor<T>::Vektor() : m_arr(nullptr), m_size(0), m_capacity(10) {
}

template <typename T>
Vektor<T>::Vektor(int size) {
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

template <typename T>
Vektor<T>::Vektor(int size, T defaultValue) : m_size(size), m_capacity(size * 2) {
	assert(size >= 0);
	m_arr = new int[m_capacity];
	for (unsigned i = 0; i < m_size; ++i)
		m_arr[i] = defaultValue;
}

template <typename T>
Vektor<T>::Vektor(const Vektor& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_arr(new int[other.m_capacity]) {
	assert(m_capacity >= m_size);
	for (unsigned i = 0; i < m_size; ++i)
		this->m_arr[i] = other.m_arr[i];
}

template <typename T>
Vektor<T>::Vektor(Vektor&& other) noexcept
	: m_size(other.m_size), m_capacity(other.m_capacity), m_arr(other.m_arr) {
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_arr = nullptr;
}

template <typename T>
Vektor<T>::~Vektor() noexcept {
	if (m_arr)
		delete[] m_arr;
	m_arr = nullptr;
}

template <typename T>
unsigned Vektor<T>::size() const {
	return m_size;
}

template <typename T>
unsigned Vektor<T>::capacity() const {
	return m_capacity;
}

template <typename T>
bool Vektor<T>::empty() {
	return m_size == 0;
}

template <typename T>
void Vektor<T>::print(char delimitter) {
	for (unsigned i = 0; i < m_size; ++i) {
		std::cout << m_arr[i];
		if (i != m_size - 1)  std::cout << delimitter;
	}
	std::cout << std::endl;
}

template <typename T>
unsigned Vektor<T>::push_back(T val) {
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

template <typename T>
T Vektor<T>::pop_back() {
	assert(m_size > 0);
	return m_size--;
}

template <typename T>
void Vektor<T>::clear() {
	m_size = 0;
}

template <typename T>
void Vektor<T>::reserve(unsigned capacity) {
	if (capacity > m_capacity) {
		int* newArr = new int[capacity];
		for (unsigned i = 0; i < m_size; ++i)
			newArr[i] = m_arr[i];
		delete[] m_arr;
		m_arr = newArr;
	}
}

template <typename T>
T Vektor<T>::operator[](unsigned index) {
	assert(index < m_size);
	assert(index >= 0);
	return m_arr[index];
}

template <typename T>
bool Vektor<T>::operator==(Vektor& vektor) {
	if (m_size != vektor.size()) return false;
	for (unsigned i = 0; i < m_size; ++i)
		if (m_arr[i] != vektor[i])
			return false;
	return true;
}

template <typename T>
Vektor<T>& Vektor<T>::operator=(Vektor& other) {
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

template <typename T>
Vektor<T>& Vektor<T>::operator=(Vektor&& other) noexcept {
	if (this != &other) {
		delete[] m_arr;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_arr = other.m_arr;

		other.m_arr = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	return *this;
}

template <typename T>
T Vektor<T>::front() {
	assert(m_size > 0);
	return m_arr[0];
}

template <typename T>
T Vektor<T>::back() {
	assert(m_size > 0);
	return m_arr[m_size - 1];
}

template <typename T>
T* Vektor<T>::data() {
	return m_arr;
}

// Returns first instance of largest element in the vektor.
template <typename T>
T* Vektor<T>::max_element() {
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

template <typename T>
T* Vektor<T>::min_element() {
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
 