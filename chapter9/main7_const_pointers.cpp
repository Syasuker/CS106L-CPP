//
// Created by zhuda on 2023/9/10.
//
#include <iostream>
#include <vector>

using namespace std;

const string kGlobalCppString = "This is a string!";


const char *const KGlobalString = "This is a string!";


int main() {
//    kGlobalCppString = "Reassinged!";
    cout << " - " << endl;
    return 0;
}

void PrintVector(const vector<string>& myVector) {
    for (vector<string>::const_iterator itr = myVector.begin();
        itr != myVector.end(); ++itr) {
        cout << *itr << endl;
    }
}