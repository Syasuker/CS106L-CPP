//
// Created by zhuda on 2023/9/10.
//
#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& vec);

void PrintVector(const vector<int>& vec) {
    for (size_t k = 0; k < vec.size(); ++k) {
        cout << vec[k] << endl;
    }
}

int main() {
    vector<int> myVecotr(8);

    PrintVector(myVecotr);
    myVecotr.push_back(137);

    return 0;
}