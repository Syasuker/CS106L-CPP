//
// Created by zhuda on 2023/9/11.
//
#include <istream>
#include <vector>

using namespace std;

class SimpleClass {
public:
    SimpleClass();

private:
    int myInt;
    string myString;
    vector<int> myVector;
};

SimpleClass::SimpleClass() : myInt(5), myString("C++"), myVector(10) {
//    myInt = 5;
//    myString = "C++!";
//    myVector.resize(10);

}


int main() {
    return 0;
}