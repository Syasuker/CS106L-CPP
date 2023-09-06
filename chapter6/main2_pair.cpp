//
// Created by zhuda on 2023/9/4.
//
#include <iostream>
#include <map>

using namespace std;

int main() {

    map<string, int> numberMap ;
    numberMap["zero"] = 0;
    numberMap["one"] = 1;
    numberMap["two"] = 2;
    cout << numberMap["zero"] << endl;
    cout << numberMap["two"] * numberMap["two"] << endl;

    cout;
    pair<int, string> myPair;
    myPair.first = 137;
    myPair.second = "C++ is awesome!";

    myPair = make_pair(136, "C++");

    cout << "Print : " << myPair.first << myPair.second << endl;
    return 0;
}