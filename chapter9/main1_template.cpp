//
// Created by zhuda on 2023/9/9.
//
#include <iostream>

using namespace std;

template<typename FirstType, typename SecondType>
struct MyPair {
    FirstType first;
    SecondType second;
};


int main() {
    MyPair<int, string> one;
    one.first = 137;
    one.second = "Templates are cool!";

    return 0;
}

