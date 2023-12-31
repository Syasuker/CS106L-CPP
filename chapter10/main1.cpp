//
// Created by zhuda on 2023/9/12.
//
#include <iostream>
#include <vector>

using namespace std;

class RationalNumber {
public:
    const RationalNumber operator+(const RationalNumber &rhs) const;
};


int main() {
    int kNumStrings = 10;
    vector<string> myVector(kNumStrings);

    for (vector<string>::iterator itr = myVector.begin();
         itr != myVector.end(); ++itr) {
        *itr += "Now longer!";
    }

    for (vector<string>::iterator itr = myVector.begin();
         operator!=(itr, myVector.end()); itr.operator++()) {
        (itr.operator*()).operator+=("Now longer!");
    }

    RationalNumber one, two;
    RationalNumber three = one + two;


}

