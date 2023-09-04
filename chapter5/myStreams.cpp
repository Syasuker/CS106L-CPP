//
// Created by zhuda on 2023/9/2.
//

#include "myStreams.h"
#include <iostream>
#include <sstream>

using namespace std;


int GetInteger() {
    while (true) {
        stringstream converter;
        converter << GetLine();

        int result;
        if (converter >> result) {
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
    string input;

    getline(cin, input);
    return input;
}