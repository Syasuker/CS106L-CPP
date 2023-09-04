//
// Created by zhuda on 2023/9/1.
//
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void MessageBoxAlert();
string GetLine();

int main() {
    stringstream myStream;
    myStream << "Hello!" << 137;

//    int levelNum = 12345;
//    stringstream messageText;
//    messageText << "Level " << levelNum << " is out of bounds.";
//    MessageBoxAlert(messageText.str());

    stringstream myConverter;
    int myInt;
    string myString;
    double myDouble;

    myConverter << "137 Hello 2.71828";
    myConverter >> myInt >> myString >> myDouble;
    cout << myInt << myString << myDouble;
}

int GetInteger() {
    while (true) {
        stringstream converter;
        converter << GetLine();

        int result;
        if (converter >> result) {
            //
            char remaining;
            if (converter >> remaining)
                cout << "Unexpected character: " << remaining << endl;
            else
                return result;
        } else
            cout << "Please enter an integer." << endl;

        cout << "Retry: ";
    }
}

string GetLine() {
    string result;
    getline(cin, result);
    return result;
}