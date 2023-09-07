//
// Created by zhuda on 2023/9/7.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    return 0;
}

bool IsPalindrome(string input) {
    for (int k = 0; k < input.size() / 2; ++k) {
        if (input[k] != input[input.length() - 1 - k])
            return false;
    }
    return true;
}

bool IsPalindrome2(string input) {
    string reversed = input;
    reverse(input.begin(), input.end());
    return reversed == input;
}

bool IsPalindrome3(string input) {
    return equal(input.begin(), input.begin() + input.size() / 2,
                 input.rbegin());
}

bool IsNotAlpha(char ch) {
    return !isalpha(ch);
}

bool IsPalindrome4(string input) {
    input.erase(remove_if(input.begin(), input.end(), IsNotAlpha),
                input.end());
    return equal(input.begin(), input.begin() + input.size() / 2,
                 input.rbegin());

}

bool IsPalindrome5(string input) {
    input.erase(remove_if(input.begin(), input.end(), IsNotAlpha), input.end());
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return equal(input.begin(), input.begin() + input.size() / 2, input.rbegin());
}

bool IsNotAlphaOrSpace(char ch) {
    return !isalpha(ch) && !isspace(ch);
}

bool IsWordPalindrome(string input) {
    input.erase(remove_if(input.begin(), input.end(), IsNotAlphaOrSpace),
                input.end());
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    stringstream tokenizer(input);
    vector<string> tokens;

    tokens.insert(tokens.begin(),
                  istream_iterator<string>(tokenizer),
            istream_iterator<string>());
    return equal(tokens.begin(), tokens.begin() + tokens.size()/2,
                 tokens.rbegin());

}