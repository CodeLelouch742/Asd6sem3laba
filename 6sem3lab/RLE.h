#pragma once
#include "includes.h"

string rle_encode(string str)
{
    string encoding = "";
    int count;

    for (int i = 0; str[i]; i++)
    {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++, i++;
        }

        encoding += to_string(count) + str[i];
    }

    return encoding;
}