//
// Created by zhuda on 2023/9/1.
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream capitals("world-capitals.txt");
    if (!capitals.is_open()) {
        cerr << "Cannot find the file world-captials.txt" << endl;
        return -1;
    }
/*
    while (true) {
        string capital, country;
        getline(capitals, capital);
        getline(capitals, country);

        if (capitals.fail()) break;

        cout << capital << " is the capital of " << country << endl;
    }*/

    string capital, country;
    while (getline(capitals, capital) && getline(capitals, country))
        cout << capital << " is the capital of " << country << endl;
}
