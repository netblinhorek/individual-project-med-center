#pragma once
#include <iostream>
#include <stdexcept>

template<class T>
class TVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity);

public:
    // Конструкторы
    TVector();
    TVector(size_t initial_size);
    TVector(const TVector& other);
    ~TVector();

    // Операторы
    TVector& operator=(const TVector& other);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Методы
    void push_back(const T& value);
    void pop_back();
    void clear();
    bool empty() const;
    size_t get_size() const;
    size_t get_capacity() const;
    T& at(size_t index);
    const T& at(size_t index) const;
    void reserve(size_t new_capacity);
};


