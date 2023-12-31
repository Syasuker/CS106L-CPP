//
// Created by zhuda on 2023/9/1.
//
#include "strutils.h"
#include <cctype>   // For tolower. toupper
#include <sstream>  // For stringstream

string ConvertToUpperCase(string input) {
    for (size_t k = 0; k < input.size(); ++k) {
        input[k] = toupper(input[k]);
    }
    return input;
}

string ConvertToLowerCase(string input) {
    for (size_t k = 0; k < input.size(); ++k) {
        input[k] = tolower(input[k]);
    }
    return input;
}

string IntegerToString(int input) {
    stringstream converter;
    converter << input;
    return converter.str();
}

string DoubleToString(double input) {
    stringstream converter;
    converter << input;
    return converter.str();
}
