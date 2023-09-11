//
// Created by zhuda on 2023/9/11.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    Point(int xLoc, int yLoc);

    int getX() const;

    int getY() const;

    static bool compareTwoPoints(const Point &one, const Point &two);

private:
    int x, y;
};

bool Point::compareTwoPoints(const Point &one, const Point &two) const {
    if (one.x != two.x) {
        return one.x < two.x;
    }
    return one.y < two.y;
}

Point::Point(int xLoc, int yLoc) {
    x = xLoc;
    y = yLoc;
}

int main() {
    vector<Point> myVector;
    sort(myVector.begin(), myVector.end(), &Point::compareTwoPoints);


    Point pt = Point(1, 1);
    int x = pt.getX();
//    Point::getX(&pt);

    return 0;
}