//
// Created by zhuda on 2023/9/2.
//
#include <iostream>
#include <vector>
#include "myStreams.h"
using namespace std;


//string GetLine();
//int GetInteger();
size_t GetSmallestIndex(vector<int>& v, size_t startIndex);
void SelectionSort(vector<int>& v);

const int kNumValues = 10;

int main() {
    vector<int> values;
    for (int i = 0; i < kNumValues; ++i) {
        cout << "Enter another value: ";
        int val = GetInteger();

        values.push_back(val);
    }

    SelectionSort(values);

    for (int i = 0; i < kNumValues; ++i) {
        cout << values[i] << endl;
    }

//    cout << values << endl;
    /*  ... */
    return 0;
}

size_t GetSmallestIndex(vector<int>& v, size_t startIndex) {
    size_t bestIndex = startIndex;

    for (size_t i = startIndex; i < v.size(); ++i) {
        if (v[i] < v[bestIndex])
            bestIndex = i;
    }
    return bestIndex;
}

void SelectionSort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        size_t smallestIndex = GetSmallestIndex(v, i);

        swap(v[i], v[smallestIndex]);
    }
}


struct MyStruct {
    int myInt;
    double myDouble;
    string myString;
};

vector<MyStruct> myStructVector;

