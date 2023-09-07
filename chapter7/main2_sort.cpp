//
// Created by zhuda on 2023/9/6.
//
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
//  http://en.cppreference.com/w/cpp/io/basic_istringstream

using namespace std;

struct placeT {
    int x;
    int y;
};


bool ComparePlaces(placeT one, placeT two);

bool ComparePlaces(placeT one, placeT two) {
    if (one.x != two.x)
        return one.x < two.x;
    return one.x < two.y;
}

bool CompareStringLength(string one, string two) {
    return one.length() < two.length();
}

int main() {
    vector<int> myVector;
    myVector.insert(myVector.begin(), 1);


//    sort(myVector.begin(), myVector.end(), ComparePlaces);
//    sort(myVector.begin(), myVector.end(), CompareStringLength);
//    if (find(myVector.begin(), myVector.end(), 137) != myVector.end())

    ostream_iterator<int> myItr(cout, " ");

    back_insert_iterator<vector<int>> itr(myVector);
    for (int i = 0; i < 10; ++i) {
        *itr = i;
        ++itr;
    }
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));

    vector<int> destination;
    reverse_copy(myVector.begin(), myVector.end(), back_inserter(destination));

    sort(myVector.begin(), myVector.end());
    random_shuffle(myVector.begin(), myVector.end());

    set<int> result;
    set<int> setOne;
    set<int> setTwo;
    set_union(setOne.begin(), setOne.end(),
            setTwo.begin(), setTwo.end(),
              inserter(result, result.begin())
    );

    int input;
    vector<int> values;
    int currValue;
    while (input >> currValue) {
        values.insert(values.begin(), currValue);
    }

//    copy(istream_iterator<int>(input),
//            istream_iterator<int>(), inserter(values, values.begin()));

    myVector.erase(remove(myVector.begin(), myVector.end(), 137), myVector.end());

    return 0;

}