//
// Created by zhuda on 2023/9/13.
//
#include <iostream>

using namespace std;

template<typename T>
class Vector {
public:
    Vector();

    Vector(const Vector &other);                // Copy constructor
    Vector &operator=(const Vector &other);   // Assignment operator
    ~Vector();

    typedef T *iterator;
    typedef const T *const_iterator;

    iterator begin();

    iterator end();

    const_iterator begin() const;

    const_iterator end() const;

private:
    T *array;
    size_t allocatedLength;
    size_t logicalLength;
    static const size kStartSize = 16;
};

template<typename T>
Vector<T>::Vector() {
    allocatedLength = kStartSize;
    logicalLength = 0;
    array = new T[allocatedLength];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] array;
}

template<typename T>
Vector<T>::Vector(const Vector &other) {

}

template<typename T>
Vector<T>::Vector(const DebugVector &other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.allocatedLength;
}

template<typename T>
Vector<T>::Vector(const Vector &other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.logicalLength;

    array = new T[allocatedLength];
    for (size_t i = 0; i < logicalLength; ++i) {
        array[i] = other.array[i];
    }
}

template<typename T>
Vector<T>::Vector(const Vector &other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.allocatedLength;

    array = new T[allocatedLength];
    copy(other.begin(), other.end(), array);
}

template<typename T>
void Vector<T>::operator=(const Vector<T> &other) {
    delete[] array;
    logicalLength = other.allocatedLength;
    allocatedLength = other.allocatedLength;

    array = new T[allocatedLength];
    copy(other.begin(), other.end(), array);
}

template<typename T>
void Vector<T>::clear() {
    delete[] array;
}

template<typename T>
Vector<T>::~Vector() {
    clear();
}

template<typename T>
void Vector<T>::copyOther(const Vector &other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.logicalLength;

    array = new T[allocatedLength];
    copy(other.begin(), other.end(), array);
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other) {
    copyOther(other);
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}







int main() {

}