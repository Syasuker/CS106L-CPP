//
// Created by zhuda on 2023/9/7.
//
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "strutils.h"

using namespace std;

int main() {
    vector<int> myVector;

    back_insert_iterator<vector<int>> itr(myVector);
    for (int i = 0; i < 10; ++i) {
        *itr = i;
        ++itr;
    }
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));

    myVector.erase(remove(myVector.begin(), myVector.end(), 137), myVector.end());

    return 0;
}

string StripPuntuation(string input) {
//    input.erase(remove_if(input.begin(), input.end(), ispunct), input.end());

    return input;
}

string ConvertToLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}