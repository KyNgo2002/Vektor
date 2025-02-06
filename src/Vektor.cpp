#include "../include/Vektor.h"

Vektor::Vektor() : m_arr{ nullptr }, m_size( 0 ), m_capacity( 10 ) {

}

Vektor::Vektor(unsigned size) : m_size( size ), m_capacity( size * 2 ) {
	assert(size >= 0);
	m_arr = new int[m_capacity];
}

unsigned Vektor::size() {
	return m_size;
}

unsigned Vektor::capacity() {
	return m_capacity;
}

unsigned Vektor::empty() {
	return m_size == 0;
}

unsigned Vektor::push_back(int val) {
	if (m_size == m_capacity) {
		int* newArr = new int[(m_size + 5) * 2];
		for (int i = 0; i < m_capacity; ++i) 
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
	m_size--;
}

void Vektor::clear() {
	m_size = 0;
}

int Vektor::operator[](int index) {
	assert(index < m_size);
	assert(index >= 0);
	return m_arr[index];
}











