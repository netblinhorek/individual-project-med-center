#include "tvector.h"
#include <algorithm>
#include <cstring>

template<class T>
TVector<T>::TVector() : data(nullptr), size(0), capacity(0) {}

template<class T>
TVector<T>::TVector(size_t initial_size) : size(initial_size), capacity(initial_size) {
    if (initial_size > 0) {
        data = new T[initial_size];
    }
    else {
        data = nullptr;
    }
}

template<class T>
TVector<T>::TVector(const TVector& other) : size(other.size), capacity(other.capacity) {
    if (other.capacity > 0) {
        data = new T[other.capacity];
        std::copy(other.data, other.data + other.size, data);
    }
    else {
        data = nullptr;
    }
}

template<class T>
TVector<T>::~TVector() {
    delete[] data;
}
template<class T>
void TVector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    size_t new_size = std::min(size, new_capacity);
    if (data != nullptr) {
        std::copy(data, data + new_size, new_data);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
    size = new_size;
}

template<class T>
void TVector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<class T>
void TVector<T>::pop_back() {
    if (size > 0) {
        --size;
    }
}

template<class T>
void TVector<T>::clear() {
    size = 0;
}

template<class T>
bool TVector<T>::empty() const {
    return size == 0;
}

template<class T>
size_t TVector<T>::get_size() const {
    return size;
}

template<class T>
size_t TVector<T>::get_capacity() const {
    return capacity;
}

template<class T>
T& TVector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<class T>
const T& TVector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<class T>
void TVector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity) {
        resize(new_capacity);
    }
}
template<class T>
T& TVector<T>::operator[](size_t index) {
    return data[index];
}

template<class T>
const T& TVector<T>::operator[](size_t index) const {
    return data[index];
}
template<class T>
TVector<T>& TVector<T>::operator=(const TVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        if (other.capacity > 0) {
            data = new T[other.capacity];
            std::copy(other.data, other.data + other.size, data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}