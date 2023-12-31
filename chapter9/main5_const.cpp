//
// Created by zhuda on 2023/9/10.
//
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

const int MyConstant = 137;

class Point {
public:
    Point(double x, double y);

    double getX() const;

    double getY() const;

    void setX(double newX);

    void setY(double newY);

    double distanceToOrigin() const;

private:
    double x, y;
};

double Point::distanceToOrigin() const {
    double dx = getX();
    double dy = y;
    dx *= dx;
    dy *= dy;
    return sqrt(dx + dy);
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

int main() {
    set<int> mySet;

    for (set<int>::iterator itr = mySet.lower_bound(42);
         itr != mySet.upper_bound(137); ++itr) {

    }

    const set<int>::iterator stop = mySet.upper_bound(137);
    for (set<int>::iterator itr = mySet.lower_bound(42); itr != stop; ++itr) {

    }

    const string myString = "this is a constant string!";
    for (size_t i = 0; i < myString.length(); ++i) {
        cout << myString[i] << endl;
    }
    return 0;
}

