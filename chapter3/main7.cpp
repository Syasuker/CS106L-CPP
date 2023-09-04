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
}