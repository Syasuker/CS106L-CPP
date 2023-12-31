//
// Created by zhuda on 2023/9/11.
//
#include <istream>

using namespace std;

class RationalNumber {
public:
    RationalNumber(int numerator = 0, int denominator = 1);

private:
    int numerator, denominator;
};

RationalNumber::RationalNumber(int numerator, int denominator) :
        numerator(numerator), denominator(denominator) {

}

class Counter {
public:
    Counter(int maxValue);

    void increment();

    void decrement();

    int getValue() const;

private:
    int value;
    const int maximum;
};

Counter::Counter(int maxValue) : value(0), maximum(maxValue) {

}

class SetWrapperClass {
public:
    SetWrapperClass();

private:
    Set <customT> mySet;
};


SetWrapperClass::SetWrapperClass() : mySet(MyCallback) {

}