//
// Created by zhuda on 2023/9/13.
//
#include <iostream>
#include <sstream>

using namespace std;


int StringToInteger(const string &input) {
    stringstream converter(input);
    int result;

    converter >> result;
    if (converter.fail()){
        throw invalid_argument("Cannot parse" + input + " as an integer.");
    }
    char leftover;
    converter >> leftover;

    if(!converter.fail()){
        return result;
    } else{
        throw invalid_argument(string("Unexpected character: ") + leftover);
    }
}

int main() {
    string myString;
    try {
        int result = StringToInteger(myString);
        cout << " The result was: " << result;
    }
    catch (const invalid_argument& problem) {
        cout << problem.what() << endl;
    }
    cout << "Yay! We're done. " << endl;
}