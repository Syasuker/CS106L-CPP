//
// Created by zhuda on 2023/9/9.
//
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    cout << "hello " << endl;

    return 0;
}

void LoadFileContents(string filename, vector<string>& out) {
    ifstream input(filename.c_str());       // Open the file.
    out.clear();

    string line;
    while (getline(input, line))
        out.push_back(line);


}