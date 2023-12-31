//
// Created by zhuda on 2023/9/12.
//
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

template<typename KeyType, typename ValueType>
class map {
public:
    class iterator {

    };

    friend class iterator;

};

struct pointT {
    int x, y;

    bool operator<(const pointT &other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

int main() {
    map<pointT, int> myMap;     // Now works using the default < operator.

}