//
// Created by zhuda on 2023/9/5.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> numberMap ;
    numberMap["zero"] = 0;
    numberMap["one"] = 1;
    numberMap["two"] = 2;
    cout << numberMap["zero"] << endl;
    cout << numberMap["two"] * numberMap["two"] << endl;
    numberMap.erase("zero");

    for (map<string, int>::iterator itr = numberMap.begin(); itr != numberMap.end(); ++itr)
        cout << itr->first << " : " << itr->second << endl;


    map<string, int>::iterator itr = numberMap.find("xyzzy");
    if (itr == numberMap.end())
        cout << "Key does not exist." << endl;
    else {
        cout << "Key " << itr->first << " has value " << itr->second << endl;
//        cout << *itr << endl;
    }
    return 0;

}