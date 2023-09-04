//
// Created by zhuda on 2023/9/2.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int GetInteger();   // From the streams
string GetLine();

int main() {
//    cout << GetLine();

    int val1 = GetInteger();
    int val2 = GetInteger();
    int val3 = GetInteger();

    cout << val1 << ' ' << val2 << ' ' << val3 << endl;

    /* Sort, then print out. */     // selection sort.
    if (val2 <= val1 && val2 <= val3)   // val2 is smallest
        swap(val1, val2);
    else if (val3 <= val1 && val3 <= val2)      // val3 is smallest
        swap(val1, val3);
    // Otherwise val1 is smallest, and can remain at the front.

    if (val3 <= val2)       // val3 is smaller
        swap(val2, val3);
    // Otherwise, val2 is smallest and we don't need to do anything.

    cout << val1 << ' ' << val2 << ' ' << val3 << endl;

    return 0;
}

int GetInteger() {
    while (true) {
        stringstream converter;
        converter << GetLine();

        int result;
        if (converter >> result) {
            char remaining;
            if (converter >> remaining)
                cout << "Unexpected character: " << remaining << endl;
            else
                return result;
        } else
            cout << "Please enter an integer." << endl;

        cout << "Retry: ";
    }
}


string GetLine() {
    string input;

    getline(cin, input);
    return input;
}
