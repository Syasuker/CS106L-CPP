//
// Created by zhuda on 2023/9/1.
//
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    string myBool;
    getline(cin, myBool);
    cout << boolalpha << myBool << endl;



    // How do you write data to a file in C++?
    cout << setfill('_') << setw(20) << "hello world!" << endl;

    ofstream myStream("myfile.txt");
    myStream << setfill('0') << setw(20) << "hello ";
    if (myStream.fail()) {  // stream failure.

    }
    // write a function that converts an int into a string.
    stringstream myStringStream;
    int intValue = 1000;
    string strValue;
    myStringStream << intValue;
    myStringStream >> strValue;
    cout << strValue;

    // What does the setw manipulator do? What does the setfill manipulator do? How do you use them?
//    cout << setw() << endl;

    return 0;
}