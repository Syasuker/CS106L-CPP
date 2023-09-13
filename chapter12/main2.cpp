//
// Created by zhuda on 2023/9/13.
//
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    auto_ptr<vector<int>> managedVector(new vector<int>);
    managedVector->push_back(137);
    (*managedVector)[0] = 42;

}