//
// Created by zhuda on 2023/9/11.
//
#include <iostream>

using namespace std;

class ClassConstantExample {
public:

private:
    static const int MyConstant = 137;
};

//const int ClassConstantExample::MyConstant = 137;

class RationalNumber {
public:
    RationalNumber(int numerator = 0, int denominator = 1);

private:
    int numerator, denominator;
};

int main() {
//    RationalNumber myNumber = 137;
    RationalNumber myNumber(137, 1);


    return 0;
}