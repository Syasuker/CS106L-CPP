//
// Created by zhuda on 2023/9/9.
//
#include <iostream>

using namespace std;

template<typename FirstType, typename SecondType>
class MyPair {
public:
    FirstType getFirst() {
        return first;
    }

    void setFirst(FirstType newValue) {
        first = newValue;
    }

    SecondType getSecond() {
        return second;
    }

    void setSecond(SecondType newValue) {
        second = newValue;
    }

    void swap(MyPair &other);

private:
    FirstType first;
    SecondType second;
};

/*
template<typename FirstType, typename SecondType>
FirstType MyPair<FirstType, SecondType>::getFirst() {
    return first;
}

template<typename FirstType, typename SecondType>
void MyPair<FirstType, SecondType>::setSecond(SecondType newValue) {
    second = newValue;
}*/

int main() {
    MyPair<int, string> one;
    return 0;
}

