//
// Created by zhuda on 2023/9/11.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

class GroceryList {
public:
    GroceryList(const string &filename);    // load from a file.

    string getItemAt(int index) const;

private:
    mutable vector<string> data;
    mutable ifstream sourceStream;
};

GroceryList::GroceryList(const string &filename) {
    sourceStream.open(filename.c_str());

//    fstream input(filename.c_str());
//    data.insert(data.begin(), istream_iterator<string>(input),
//                istream_iterator<string>());
}

string GroceryList::getItemAt(int index) const {
    while (index >= data.length()) {
        string line;
        getline(sourceStream, line);
        data.push_back(line);
    }
    return data[index];
}


int main() {
    return 0;
}