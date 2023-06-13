#pragma once
#include "RLE.h"


vector<int> mtf_encode(const string& input) {
    vector<int> output;
    vector<int> alphabet(100000);
    for (int i = 0; i < 100000; i++) {
        alphabet[i] = i;
    }
    for (char c : input) {
        int index = find(alphabet.begin(), alphabet.end(), c) - alphabet.begin();
        output.push_back(index);
        alphabet.erase(alphabet.begin() + index);
        alphabet.insert(alphabet.begin(), c);
    }
    return output;
}

string mtf_decode(const vector<int>& input) {
    string output;
    vector<int> alphabet(256);
    for (int i = 0; i < 256; i++) {
        alphabet[i] = i;
    }
    for (int index : input) {
        char c = alphabet[index];
        output += c;
        alphabet.erase(alphabet.begin() + index);
        alphabet.insert(alphabet.begin(), c);
    }
    return output;
}