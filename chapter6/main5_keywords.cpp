//
// Created by zhuda on 2023/9/5.
//
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

void OpenUserFile(ifstream& fileStream);

string GetFileContents(ifstream& file);

string GetLine();
set<string> LoadKeywords();

void PreprocessString(string& text);
map<string , size_t> GenerateKeywordReport(string fileContents);


map<string, size_t> GenerateKeywordReport(string contents);

int main() {
    ifstream input;
    OpenUserFile(input);

    map<string, size_t> report = GenerateKeywordReport(GetFileContents(input));

    for (map<string, size_t>::iterator itr = report.begin();
        itr != report.end(); ++itr
    ) {
        cout << "Keyword " << itr->first << " occurred"
            << itr->second << " times." << endl;
    }
}

void OpenUserFile(ifstream& input) {
    while(true) {
        cout << "Enter filename: ";
        string filename = GetLine();

        input.open(filename.c_str());
        if (input.is_open()) return;

        cout << "Sorry, I can't find the file " << filename << endl;
        input.clear();
    }
}

string GetLine() {
    string line;
    getline(cin, line);
    return line;
}

string GetFileContents(ifstream& input) {
    string result;

    string line;
    while (getline(input, line)){
        result += line + "\n";  //
    }
    return result;
}

set<string> LoadKeywords() {
    ifstream input("keywords.txt");
    set<string> result;

    string keyword;
    while (input >> keyword)
        result.insert(keyword);

    return result;
}

void PreprocessString(string& text) {
    for (size_t k = 0; k < text.size(); ++k) {
        if (ispunct(text[k]) && text[k] != '_') // if we need to change it...
            text[k] = ' ';  // ... replace it with a space.
    }
}


map<string , size_t> GenerateKeywordReport(string fileContents) {
    /*  Load the set of keywords from disk. */
    set<string> keywords = LoadKeywords();
    /*  Preprocess the string to allow for easier parsing.  */
    PreprocessString(fileContents);

    /*  Populate a stringstream with the file contents. */
    stringstream tokenizer;
    tokenizer << fileContents;

    map<string, size_t > result;

    string word;
    while (tokenizer >> word)
        if (keywords.count(word))
            ++ result[word];

    return result;
}