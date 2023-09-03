//
// Created by sya on 2023/9/3.
//

#include "myStream.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int GetInteger(){
    stringstream converter;
    converter << GetLine();

    int result;
    if (converter >> result) {
        char remaining;
        if (converter >> remaining)
            cout << "Unexpected character: " << remaining << endl;
        else
            return result;
    } else{
        cout << "Please enter an integer." << endl;
    }
    cout << "Retry: ";
}

string GetLine() {
    string input;
    getline(cin, input);
    return input;
}