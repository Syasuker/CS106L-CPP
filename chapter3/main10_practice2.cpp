//
// Created by zhuda on 2023/9/1.
//
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Write a function OpenFile,   If the file can be found, OpenFile should return with the ifstream opened
    // to read that file. Otherwise, OpenFile should print an error message and reprompt the user.

    string filename;
    string strValue;

    getline(cin, filename);

    ifstream fileStream(filename);
    while (fileStream.fail()) {
        cout << "file stream fail. try again." << endl;
        fileStream.clear();
        getline(cin, filename);
    }

    if (fileStream.is_open()) {
        while(fileStream >> strValue)
            cout << strValue << " " ;
    }

    return 0;
}
