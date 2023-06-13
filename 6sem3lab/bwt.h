#pragma once
#include "MTF.h"

string bwt_encode(const string& text) {
    string result(text.size(), ' ');

    for (int i = 0; i < text.size(); i++) {
        result[i] = text[(i + text.size() - 1) % text.size()];
    }

    sort(result.begin(), result.end());

    return result;
}

string bwt_decode(const string& bwt_text) {
    int n = bwt_text.size();
    string sorted_text = bwt_text;
    sort(sorted_text.begin(), sorted_text.end());

    vector<int> next(n);
    vector<int> count(256, 0);

    for (int i = 0; i < n; i++) {
        count[bwt_text[i]]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++) {
        next[count[bwt_text[i]] - 1] = i;
        count[bwt_text[i]]--;
    }

    string result(n, ' ');
    int index = 0;

    for (int i = 0; i < n; i++) {
        result[i] = sorted_text[index];
        index = next[index];
    }

    return result;
}