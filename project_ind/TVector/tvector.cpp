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