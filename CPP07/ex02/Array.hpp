//
// Created by redone on 7/16/23.
//

#ifndef POOL_ARRAY_HPP
#define POOL_ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array {
private:
    T *m_elements;
    unsigned int m_size;

public:
    Array();

    Array(unsigned int size);

    Array(const Array<T> &other);

    Array &operator=(const Array<T> &other);

    ~Array() { delete[] m_elements; }

    T &operator[](unsigned int index);

    unsigned int size() const;
};

template<typename T>
Array<T>::Array() : m_elements(NULL), m_size(0) {
}

template<typename T>
Array<T>::Array(unsigned int size) : m_elements(new T[size]), m_size(size) {
    for (unsigned int i = 0; i < size; ++i) {
        m_elements[i] = T();
    }
}

template<typename T>
Array<T>::Array(const Array<T> &other) : m_elements(new T[other.m_size]), m_size(other.m_size) {
    for (unsigned int i = 0; i < m_size; ++i) {
        m_elements[i] = other.m_elements[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this == &other)
        return *this;
    delete[] this->m_elements;
    m_elements = new T[other.m_size];
    m_size = other.m_size;
    for (unsigned int i = 0; i < m_size; ++i) {
        m_elements[i] = other.m_elements[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= m_size)
        throw std::out_of_range("index out of range");
    return m_elements[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return m_size;
}

#endif //POOL_ARRAY_HPP
