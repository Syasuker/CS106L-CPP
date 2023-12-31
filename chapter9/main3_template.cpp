//
// Created by zhuda on 2023/9/9.
//
#include <iostream>
#include <deque>

using namespace std;

template<typename T>
class Stack {
public:
    void push(T value);

    T pop();

    size_t size();

    bool empty();

    typename deque<T>::iterator begin();

    typename deque<T>::iterator end();

private:
    deque<T> elems;
};

template<typename T>
void Stack<T>::push(T value) {
    elems.push_front(value);
}

template<typename T>
T Stack<T>::pop() {
    T result = elems.front();
    elems.pop_front();
    return result;
}

template<typename T>
size_t Stack<T>::size() {
    return elems.size();
}

template<typename T>
bool Stack<T>::empty() {
    return elems.empty();
}