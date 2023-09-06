//
// Created by zhuda on 2023/9/5.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> numberMap;
    numberMap.insert(make_pair("zero", 0));
    numberMap.insert(make_pair("one", 1));
    numberMap.insert(make_pair("two", 2));

    map<string, string> one;
    one["C++"] = "sad";
    one["C++"] = "happy";

    map<string, string> two;
    two.insert(make_pair("C++", "sad"));
    two.insert(make_pair("C++", "happy"));

    pair<map<string , int>::iterator ,bool> result =
            numberMap.insert(make_pair("STL", 137));

    for (map<string, int>::iterator itr = numberMap.begin();
        itr != numberMap.end(); ++itr
    ) {
        cout << itr->first << itr->second << endl;
    }

}