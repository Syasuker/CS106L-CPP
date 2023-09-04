//
// Created by zhuda on 2023/8/31.
//
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;    //

void PrintTableHeader();

void PrintTableBody();

int main() {
    PrintTableHeader();
    PrintTableBody();

    return 0;
}

void PrintTableBody() {
    ifstream input("table-data.txt");

    int rowNumber = 0;

    int intValue;
    double doubleValue;
//    input >> intValue >> doubleValue;

    while(input >> intValue >> doubleValue) {       //
//    for (int k = 0; k < NUM_LINES; ++k) {

//        if (input.fail()) break;
//        if (input >> intValue >> doubleValue)

        cout << setw(COLUMN_WIDTH) << (rowNumber + 1) << " | ";
        cout << setw(COLUMN_WIDTH) << intValue << " | ";
        cout << setw(COLUMN_WIDTH) << doubleValue << endl;

        rowNumber++;
    }
}

void PrintTableHeader() {
    for (int column = 0; column < NUM_COLUMNS -1; ++column) {
        for (int k = 0; k < COLUMN_WIDTH; ++k) {
            cout << '-';
        }
        cout << "-+-";
    }
    for (int k = 0; k < COLUMN_WIDTH; ++k) {
        cout << '-';
    }
    cout << endl;
}

void PrintTableHeader1() {
    for (int column = 0; column < NUM_COLUMNS - 1; ++column) {
        cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";

        cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
    }
}
